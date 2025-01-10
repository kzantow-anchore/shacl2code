/**
 * @file
 *
 * This file was automatically generated by shacl2code. DO NOT MANUALLY MODIFY IT
 *
 * SPDX-License-Identifier: MIT
 */

/* */
#ifndef _SHACL2CODE_TEST_CONTEXT_NAMEDINDIVIDUAL_HPP
#define _SHACL2CODE_TEST_CONTEXT_NAMEDINDIVIDUAL_HPP

/* */

#include <optional>
#include <string>
#include <unordered_map>

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

class TypeBase;

/**
 * @brief Named Individual
 *
 * A named individual
 */
class EXPORT NamedIndividual {
   public:
    /// Constructor
    NamedIndividual(TypeBase const* type, std::string&& iri,
                    std::optional<std::string>&& compact);

    /// Destructor
    virtual ~NamedIndividual();

    /**
     * @brief String conversion operator
     *
     * Converts a NamedIndividual to a string (the fully qualified IRI)
     */
    operator std::string() const { return mIRI; }

    /**
     * @brief Get IRI
     *
     * @returns the named individuals IRI
     */
    std::string const& getIRI() const { return mIRI; }

    /**
     * @brief Get Compact IRI
     *
     * @returns The compact IRI for the NamedIndividual, or an empty optional
     * if the NamedIndividual has no compact IRI
     *
     * @note The compact IRI only applies to the global context. Individual
     * properties may have additional context for mapping named individuals
     * (e.g. this is common in Enum properties)
     */
    std::optional<std::string> const& getCompactIRI() const {
        return mCompactIRI;
    }

    /**
     * @brief Get NamedIndividual type
     *
     * @returns the TypeBase for the type of the named individual
     */
    TypeBase const* getType() const { return mType; }

    /**
     * @brief Get Named Individual from Compact IRI
     *
     * @returns The NamedIndividual with the compacted IRI, or nullptr if there
     * is none.
     *
     * @note This only applies if the NamedIndividual has a compact IRI in the
     * global context
     */
    static NamedIndividual const* getFromCompact(std::string const& compact);

    /**
     * @brief Get Named Individual from IRI
     *
     * @returns The NamedIndividual with the IRI, or nullptr if there is no
     * NamedIndividual with that IRI
     */
    static NamedIndividual const* getFromIRI(std::string const& iri);

   private:
    TypeBase const* mType;
    std::string mIRI;
    std::optional<std::string> mCompactIRI;

    using Map = std::unordered_map<std::string, NamedIndividual const*>;

    LOCAL static NamedIndividual const* getFromMap(Map const& map,
                                                   std::string const& key);

    LOCAL static Map& getCompactMap();
    LOCAL static Map& getIRIMap();
};

/* */
#undef EXPORT
#undef LOCAL

/* */
/* */
}
/* */
/* */
#endif // _SHACL2CODE_TEST_CONTEXT_NAMEDINDIVIDUAL_HPP
/* */
