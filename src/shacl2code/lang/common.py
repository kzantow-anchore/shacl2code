#
# Copyright (c) 2024 Joshua Watt
#
# SPDX-License-Identifier: MIT

import sys
import os
from pathlib import Path
from contextlib import contextmanager
from jinja2 import Environment, FileSystemLoader, TemplateRuntimeError
from rdflib.namespace import SH
from ..model import SHACL2CODE

THIS_DIR = Path(__file__).parent


class OutputFile(object):
    def __init__(self, path):
        self.path = path

    @contextmanager
    def open(self):
        if self.path == "-":
            yield sys.stdout
        else:
            with open(self.path, "w") as f:
                yield f


class BasicJinjaRender(object):
    """
    Common Jinja Template Renderer

    Renderers that only use a single Jinja file can derive from this class. For
    example:

        @language("my-lang")
        class MyRendered(BasicJinjaRenderer):
            HELP = "Generates my-lang bindings"

            def __init__(self, args):
                super().__init__(args, PATH / TO / TEMPLATE)
    """

    def __init__(self, args, template):
        self.__output = args.output
        self.__template = template

    @classmethod
    def get_arguments(cls, parser):
        parser.add_argument(
            "--output",
            "-o",
            type=OutputFile,
            help="Output file or '-' for stdout",
            required=True,
        )

    def get_additional_render_args(self):
        return {}

    def get_extra_env(self):
        return {}

    def render(self, template, output, *, extra_env={}, render_args={}):
        def abort_helper(msg):
            raise TemplateRuntimeError(msg)

        env = Environment(loader=FileSystemLoader([template.parent, THIS_DIR.parent]))
        for k, v in extra_env.items():
            env.globals[k] = v
        env.globals["abort"] = abort_helper
        env.globals["SHACL2CODE"] = SHACL2CODE
        env.globals["SH"] = SH

        template = env.get_template(template.name)

        render = template.render(
            **render_args,
        )

        output.write(render)
        if not render[-1] == "\n":
            output.write("\n")

    def output(self, model):
        """
        Render the provided model
        """

        class ObjectList(object):
            def __init__(self, objs):
                self.__objs = objs

            def __iter__(self):
                return iter(self.__objs)

            def get(self, _id):
                for o in self.__objs:
                    if o._id == _id:
                        return o
                raise KeyError(f"Object with ID {_id} not found")

        def get_all_derived(cls):
            nonlocal classes

            def _recurse(cls):
                result = set(cls.derived_ids)
                for r in cls.derived_ids:
                    result |= _recurse(classes.get(r))
                return result

            d = list(_recurse(cls))
            d.sort()
            return d

        def get_all_named_individuals(cls):
            ni = set(i._id for i in cls.named_individuals)

            for d in get_all_derived(cls):
                ni |= set(i._id for i in classes.get(d).named_individuals)

            return ni

        classes = ObjectList(model.classes)
        concrete_classes = ObjectList(
            list(c for c in model.classes if not c.is_abstract)
        )
        abstract_classes = ObjectList(list(c for c in model.classes if c.is_abstract))
        enums = ObjectList(model.enums)

        render_args = {
            "classes": classes,
            "concrete_classes": concrete_classes,
            "abstract_classes": abstract_classes,
            "enums": enums,
            "context": model.context,
            "disclaimer": f"This file was automatically generated by {os.path.basename(sys.argv[0])}. DO NOT MANUALLY MODIFY IT",
            **self.get_additional_render_args(),
        }

        env = {
            "get_all_derived": get_all_derived,
            "get_all_named_individuals": get_all_named_individuals,
            **self.get_extra_env(),
        }

        with self.__output.open() as f:
            self.render(
                self.__template,
                f,
                extra_env=env,
                render_args=render_args,
            )
