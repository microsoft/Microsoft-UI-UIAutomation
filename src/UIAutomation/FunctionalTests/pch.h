// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

// The following macro tells the Windows header files to define GUIDs, not just declare them.
// This is necessary for the UI Automation GUIDs that we use in GUID-related tests.
// Normally this macro isn't necessary in application code, because the Windows SDK provides
// static libraries that define all of the commonly used GUIDs. But none of those libraries
// include this category of UI Automation GUID.
#define INITGUID

#include <unknwn.h>
#include <Windows.h>
#include <uiautomation.h>

#include <sstream>
#include <string>
#include <variant>

#include <wil/resource.h>
#include <wil/result.h>
#include <wil/com.h>

#include <winrt/Windows.Foundation.h>
