// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "MessageBuilder.h"

void MessageBuilder::WriteBool(bool val)
{
    WriteByte(val ? 1 : 0);
}

void MessageBuilder::WriteByte(uint8_t val)
{
    static_assert(sizeof(uint8_t) == 1, "uint8_t expected to be 1 byte");
    WriteBytes(&val, sizeof(val));
}

void MessageBuilder::WriteChar(wchar_t val)
{
    static_assert(sizeof(wchar_t) == 2, "wchar_t expected to be 2 bytes");
    WriteBytes(reinterpret_cast<const uint8_t*>(&val), sizeof(val));
}

void MessageBuilder::WriteInt(int val)
{
    static_assert(sizeof(int) == 4, "int expected to be 4 bytes");
    WriteBytes(reinterpret_cast<const uint8_t*>(&val), sizeof(val));
}

void MessageBuilder::WriteUnsignedInt(unsigned int val)
{
    static_assert(sizeof(unsigned int) == 4, "unsigned int expected to be 4 bytes");
    WriteBytes(reinterpret_cast<const uint8_t*>(&val), sizeof(val));
}

void MessageBuilder::WriteDouble(double val)
{
    static_assert(sizeof(double) == 8, "double expected to be 8 bytes");
    WriteBytes(reinterpret_cast<const uint8_t*>(&val), sizeof(val));
}

void MessageBuilder::WriteString(std::wstring_view val)
{
    static_assert(sizeof(wchar_t) == 2, "wchar_t expected to be 2 bytes");
    WriteInt(static_cast<int>(val.size()));
    WriteBytes(reinterpret_cast<const uint8_t*>(val.data()), val.size() * sizeof(wchar_t));
}

std::vector<uint8_t> MessageBuilder::DetachBuffer()
{
    return std::move(m_buffer);
}

void MessageBuilder::WriteBytes(_In_reads_(count) const uint8_t* bytes, size_t count)
{
    std::copy(bytes, bytes + count, std::back_inserter(m_buffer));
}
