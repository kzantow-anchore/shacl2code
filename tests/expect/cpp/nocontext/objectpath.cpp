/**
 * @file
 *
 * This file was automatically generated by shacl2code. DO NOT MANUALLY MODIFY IT
 *
 * SPDX-License-Identifier: 0BSD
 */

#include <iterator>
#include <sstream>
#include <string>

#include "decode.hpp"
#include "objectpath.hpp"
#include "propertyvalue.hpp"

/* */
namespace test {
/* */

using std::string_literals::operator""s;

/**
 * @brief Run final function
 *
 * Helper class that uses RAII to invoke a cleanup function when it goes out of
 * scope
 */
class Finally {
   public:
    /// Contructor
    explicit Finally(std::function<void(void)>&& func)
        : mFunc(std::move(func)) {}

    /// Destructor (invokes callback function)
    ~Finally() { mFunc(); }

    Finally(Finally const&) = delete;
    Finally(Finally&&) = delete;
    Finally& operator=(Finally const&) = delete;
    Finally& operator=(Finally&&) = delete;

   private:
    std::function<void(void)> mFunc;
};

// ObjectPath
ObjectPath::ObjectPath() {}
ObjectPath::~ObjectPath() {}

std::string ObjectPath::getPathString() const {
    std::ostringstream s;

    std::copy(mPath.begin(), mPath.end(),
              std::ostream_iterator<std::string>(s));

    return s.str();
}

void ObjectPath::pushPath(std::string const& p, ObjectPath::func const& f) {
    mPath.push_back(p);

    // Use RAII Make sure path is popped
    Finally fin([&] { mPath.pop_back(); });

    f();
}

void ObjectPath::pushIndex(int i, ObjectPath::func const& f) {
    pushPath("["s + std::to_string(i) + "]"s, f);
}

void ObjectPath::pushMember(std::string const& name,
                            ObjectPath::func const& f) {
    pushPath("."s + name, f);
}

void ObjectPath::pushProperty(PropertyValueCommon const& p,
                              ObjectPath::func const& f) {
    pushMember(p.getCompactIRI().value_or(p.getIRI()), f);
}

void ObjectPath::foreachListDecoder(
    ListDecoder& decoder, std::function<void(ValueDecoder&)> const& f) {
    int idx = 0;
    decoder.readItems([&](ValueDecoder& valueDecoder) {
        pushIndex(idx, [&] { f(valueDecoder); });
        idx++;
    });
}

/* */
}
/* */
