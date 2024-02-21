#
# Copyright (c) 2024 Joshua Watt
#
# SPDX-License-Identifier: MIT

import re
import subprocess
import sys
import json
from pathlib import Path

THIS_FILE = Path(__file__)
THIS_DIR = THIS_FILE.parent

SPDX3_MODEL = THIS_DIR / "data" / "spdx3.jsonld"
SPDX3_EXPECT = THIS_DIR / "expect" / "jsonschema" / "spdx3.json"


def test_generation(tmpdir):
    """
    Tests that shacl2code generates json schema output that matches the
    expected output
    """
    outfile = tmpdir.join("spdx3.json")
    subprocess.run(
        [
            "shacl2code",
            "generate",
            "--input",
            SPDX3_MODEL,
            "jsonschema",
            "--output",
            outfile,
        ],
        check=True,
    )

    with SPDX3_EXPECT.open("r") as f:
        assert outfile.read() == f.read()


def test_output_syntax(tmpdir):
    """
    Checks that the output file is valid json syntax by parsing it with Python
    """
    outfile = tmpdir.join("spdx3.json")
    subprocess.run(
        [
            "shacl2code",
            "generate",
            "--input",
            SPDX3_MODEL,
            "jsonschema",
            "--output",
            outfile,
        ],
        check=True,
    )

    json.loads(outfile.read())


def test_trailing_whitespace():
    """
    Tests that the generated file does not have trailing whitespace
    """
    p = subprocess.run(
        [
            "shacl2code",
            "generate",
            "--input",
            SPDX3_MODEL,
            "jsonschema",
            "--output",
            "-",
        ],
        check=True,
        stdout=subprocess.PIPE,
        encoding="utf-8",
    )

    for num, line in enumerate(p.stdout.splitlines()):
        assert (
            re.search(r"\s+$", line) is None
        ), f"Line {num + 1} has trailing whitespace"


def test_tabs():
    """
    Tests that the output file doesn't contain tabs
    """
    p = subprocess.run(
        [
            "shacl2code",
            "generate",
            "--input",
            SPDX3_MODEL,
            "jsonschema",
            "--output",
            "-",
        ],
        check=True,
        stdout=subprocess.PIPE,
        encoding="utf-8",
    )

    for num, line in enumerate(p.stdout.splitlines()):
        assert "\t" not in line, f"Line {num + 1} has tabs"
