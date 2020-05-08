// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include <string>
#include <vector>
#include <string_view>

// A helper class that is used to build the byte buffer representation of Remote Operation bytecode.
//
// Contains helpers for serializing various primitives that can be encoded as part of that
// representation of Remote Op bytecode.
//
// Exposes a method to retrieve the final serialized buffer.
class MessageBuilder
{
public:
    MessageBuilder() = default;

    void WriteBool(bool);
    void WriteByte(uint8_t);
    void WriteChar(wchar_t);
    void WriteInt(int);
    void WriteUnsignedInt(unsigned int);
    void WriteDouble(double);
    void WriteString(std::wstring_view);

    // Takes ownership of the buffer that contains the serialized representation of all values
    // that have been written to the builder thus far.
    std::vector<uint8_t> DetachBuffer();

private:
    // A helper function that appends the given byte buffer to the end of the result buffer that
    // the builder is accumulating.
    void WriteBytes(_In_reads_(count) const uint8_t* bytes, size_t count);

    std::vector<uint8_t> m_buffer;
};

