/**
 * @file
 *
 * This file was automatically generated by shacl2code. DO NOT MANUALLY MODIFY IT
 *
 * SPDX-License-Identifier: MIT
 */

/* */
#ifndef _SHACL2CODE_TEST_CONTEXT_PROP_HPP
#define _SHACL2CODE_TEST_CONTEXT_PROP_HPP

/* */

#include <string>

#include "datetime.hpp"
#include "property.hpp"
#include "propertyvalue.hpp"
#include "refproperty.hpp"

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
 * @brief Property value namespace
 *
 * This namespace contains the class definitions that should be used by objects
 * derived from SHACLObject to declare their properties.
 *
 * All Properties use the same general format for declaration. For example to
 * declare a object with a single string property use:
 *
 * @code
 *  class MyClass : public SHACLObject {
 *      SHACL2CODE_TEST_CONTEXT_CLASS(MyClass, SHACLObject, false)
 *      public:
 *          Prop::String _myString;
 *  };
 * @endcode
 *
 * The property can hold a value of a specified type, and may have the ability
 * to have additional restrictions placed on it based on it at the time the
 * property is constructed
 *
 * @note The "_" prefix on the property name is not mandatory, but is suggested
 * to prevent conflict with other properties and member functions of the class
 */
namespace Prop {
/**
 * @brief Enum property
 *
 * Declares an enum type property. An enumeration is only allowed to be
 * assigned specific IRI values
 *
 * @see ::test_context::Prop
 */
using Enum = PropertyValue<std::string, EnumProperty>;

/**
 * @brief String property
 *
 * Declares an string type property. A string can hold any valid string value.
 *
 * @see ::test_context::Prop
 */
using String = PropertyValue<std::string, StringProperty>;

/**
 * @brief Any URI property
 *
 * Declares a URI type property. This property can hold anything that is a valid
 * URI
 *
 * @see ::test_context::Prop
 */
using AnyURI = PropertyValue<std::string, AnyURIProperty>;

/**
 * @brief Integer property
 *
 * Declares an integer type property.
 *
 * @see ::test_context::Prop
 */
using Integer = PropertyValue<int, IntegerProperty>;

/**
 * @brief Double property
 *
 * Declares a double type property.
 *
 * @see ::test_context::Prop
 */
using Double = PropertyValue<double, DoubleProperty>;

/**
 * @brief Boolean property
 *
 * Declares an boolean type property.
 *
 * @see ::test_context::Prop
 */
using Boolean = PropertyValue<bool, BooleanProperty>;

/**
 * @brief DateTime property
 *
 * Declares an DateTime type property.
 *
 * @see ::test_context::Prop
 * @see ::test_context::DateTime
 */
// clang-format off
using DateTime = PropertyValue <::test_context::DateTime, DateTimeProperty>;
// clang-format on

/**
 * @brief DateTime with timezone property
 *
 * Declares an DateTime with timezone type property.
 *
 * @see ::test_context::Prop
 * @see ::test_context::DateTime
 */
// clang-format off
using DateTimeStamp = PropertyValue <::test_context::DateTime, DateTimeStampProperty>;
// clang-format on

/**
 * @brief Referenced property
 *
 * Declares an property which is a reference to another SHACLObject derived type
 *
 * @see ::test_context::Prop
 * @see ::test_context::Ref
 */
template <class C>
using Ref = RefPropertyValue<C>;

/**
 * @brief Enum list property
 *
 * Declares a property which is a list of enum values. An enumeration is only
 * allowed to be a specific set of IRI values
 *
 * @see ::test_context::Prop
 */
using EnumList = ListPropertyValue<std::string, EnumProperty>;

/**
 * @brief String list property
 *
 * Declares a property which is a list of string values
 *
 * @see ::test_context::Prop
 */
using StringList = ListPropertyValue<std::string, StringProperty>;

/**
 * @brief Any URI list property
 *
 * Declares a property which is a list of URI values
 *
 * @see ::test_context::Prop
 */
using AnyURIList = ListPropertyValue<std::string, AnyURIProperty>;

/**
 * @brief Integer list property
 *
 * Declares a property which is a list of integer values
 *
 * @see ::test_context::Prop
 */
using IntegerList = ListPropertyValue<int, IntegerProperty>;

/**
 * @brief Double list property
 *
 * Declares a property which is a list of double values
 *
 * @see ::test_context::Prop
 */
using DoubleList = ListPropertyValue<double, DoubleProperty>;

/**
 * @brief Boolean list property
 *
 * Declares a property which is a list of boolean values
 *
 * @see ::test_context::Prop
 */
using BooleanList = ListPropertyValue<bool, BooleanProperty>;

/**
 * @brief DateTime list property
 *
 * Declares a property which is a list of DateTime values
 *
 * @see ::test_context::Prop
 * @see ::test_context::DateTime
 */
// clang-format off
using DateTimeList = ListPropertyValue<::test_context::DateTime, DateTimeProperty>;

/**
 * @brief DateTime with timezone list property
 *
 * Declares a property which is a list of DateTime with timezone values
 *
 * @see ::test_context::Prop
 * @see ::test_context::DateTime
 */
using DateTimeStampList = ListPropertyValue<::test_context::DateTime, DateTimeStampProperty>;
// clang-format on

/**
 * @brief Reference list property
 *
 * Declares a property which is a list of references to another SHACLObject
 * derived type
 *
 * @see ::test_context::Prop
 * @see ::test_context::Ref
 */
template <class C>
using RefList = RefListPropertyValue<C>;
// clang-format on
}  // namespace Prop

/* */
#undef EXPORT
#undef LOCAL

/* */
/* */
}
/* */
/* */
#endif // _SHACL2CODE_TEST_CONTEXT_PROP_HPP
/* */
