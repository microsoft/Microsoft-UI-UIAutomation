// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include "CppUnitTest.h"

template<class... Args>
void LogOutput(Args&&... args)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    std::wostringstream oss;
    (oss << ... << args);
    oss << std::endl;

    auto res = oss.str();
    Logger::WriteMessage(res.c_str());
}

