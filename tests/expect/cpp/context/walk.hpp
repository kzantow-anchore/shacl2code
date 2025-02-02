/**
 * @file
 *
 * This file was automatically generated by shacl2code. DO NOT MANUALLY MODIFY IT
 *
 * SPDX-License-Identifier: 0BSD
 */

/* */
#ifndef _SHACL2CODE_TEST_CONTEXT_WALK_HPP
#define _SHACL2CODE_TEST_CONTEXT_WALK_HPP

/* */

#include <functional>
#include <optional>
#include <string>

#include "datetime.hpp"

/* */
#ifndef DOXYGEN_SKIP
#include "api.hpp"
// These are so that we don't have to use Jinja templates below since that messes up the formatting
#define EXPORT SHACL2CODE_TEST_CONTEXT_API
#define LOCAL  SHACL2CODE_TEST_CONTEXT_LOCAL
#endif // DOXYGEN_SKIP

/* */
/* */
namespace test_context {
/* */

class ObjectPath;
class SHACLObject;

template <class C>
class Ref;

/**
 * @brief Walk callback
 *
 * Callbacks to use when walking a object tree
 */
struct EXPORT WalkCallback {
    /// Callback when a string property is walked
    std::function<void(
        ObjectPath&,
        std::optional<std::reference_wrapper<std::string const>> const&)> const&
        stringProp = [](auto&, auto const&) {};

    /// Callback when an integer property is walked
    std::function<void(ObjectPath const&, std::optional<int>)> const&
        integerProp = [](auto&, auto const&) {};

    /// Callback when a boolean property is walked
    std::function<void(ObjectPath&, std::optional<bool>)> const& booleanProp =
        [](auto const&, auto const&) {};

    /// Callback when a double property is walked
    std::function<void(ObjectPath&, std::optional<double>)> const& doubleProp =
        [](auto&, auto const&) {};

    /// Callback when a DateTime property is walked
    std::function<void(
        ObjectPath&,
        std::optional<std::reference_wrapper<DateTime const>> const&)> const&
        dateTimeProp = [](auto&, auto const&) {};

    /// Callback when an Enum property is walked
    std::function<void(
        ObjectPath&,
        std::optional<std::reference_wrapper<std::string const>> const&)> const&
        enumProp = [](auto&, auto const&) {};

    /// Callback when an Any URI property is walked
    std::function<void(
        ObjectPath&,
        std::optional<std::reference_wrapper<std::string const>> const&)> const&
        anyURIProp = [](auto&, auto const&) {};

    /**
     * @brief Callback when an object is walked
     *
     * The callback should return true if the object is to be recursed into
     * (that is, all its properties walked), or false if not
     */
    std::function<bool(ObjectPath&, std::optional<std::reference_wrapper<
                                        Ref<SHACLObject> const>> const&)> const&
        refProp = [](auto&, auto const&) { return false; };
};

/* */
#undef EXPORT
#undef LOCAL

/* */
/* */
}
/* */
/* */
#endif // _SHACL2CODE_TEST_CONTEXT_WALK_HPP
/* */
