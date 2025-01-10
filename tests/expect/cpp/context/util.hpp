/**
 * @file
 *
 * This file was automatically generated by shacl2code. DO NOT MANUALLY MODIFY IT
 *
 * SPDX-License-Identifier: MIT
 */

/* */
#ifndef _SHACL2CODE_TEST_CONTEXT_UTIL_HPP
#define _SHACL2CODE_TEST_CONTEXT_UTIL_HPP

/* */

#include <string>

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

/**
 * @brief String is blank node?
 *
 * @returns true if the string is a correctly formatted blank node
 */
extern EXPORT bool isBlankNode(std::string const& id);

/**
 * @brief String is IRI
 *
 * @returns true if the string is a fully qualified IRI (and not a blank node)
 */
extern EXPORT bool isIRI(std::string const& id);

/* */
#undef EXPORT
#undef LOCAL

/* */
/* */
}
/* */
/* */
#endif // _SHACL2CODE_TEST_CONTEXT_UTIL_HPP
/* */
