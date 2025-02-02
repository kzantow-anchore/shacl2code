/**
 * @file
 *
 * This file was automatically generated by shacl2code. DO NOT MANUALLY MODIFY IT
 *
 * SPDX-License-Identifier: 0BSD
 */

#include <functional>
#include <optional>
#include <string>

#include "decode.hpp"

/* */
namespace test_context {
/* */

using std::string_literals::operator""s;

// DecoderState
DecoderState::DecoderState(SHACLObjectSet* objectSet) : mObjectSet(objectSet) {}
DecoderState::~DecoderState() {}

// ElementDecoder
ElementDecoder::ElementDecoder(DecoderState& state) : mState(state) {}
ElementDecoder::~ElementDecoder() {}

// ValueDecoder
ValueDecoder::ValueDecoder(DecoderState& state) : ElementDecoder(state) {}
ValueDecoder::~ValueDecoder() {}

// ObjectDecoder
ObjectDecoder::ObjectDecoder(DecoderState& state) : ElementDecoder(state) {}
ObjectDecoder::~ObjectDecoder() {}

// ListDecoder
ListDecoder::ListDecoder(DecoderState& state) : ElementDecoder(state) {}
ListDecoder::~ListDecoder() {}

/* */
}
/* */
