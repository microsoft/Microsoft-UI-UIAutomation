// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "SafeArrayUtil.h"

namespace SafeArrayUtil
{

HRESULT SafeArrayGetCount(_In_ SAFEARRAY* array, _Out_ long* size) noexcept try
{
    *size = 0;

    long lowerBound = 0;
    long upperBound = 0;
    THROW_IF_FAILED(::SafeArrayGetLBound(array, 1 /* nDim */, &lowerBound));
    THROW_IF_FAILED(::SafeArrayGetUBound(array, 1 /* nDim */, &upperBound));

    *size = (upperBound - lowerBound + 1);
    return S_OK;
}
CATCH_RETURN();

} // SafeArrayUtil
