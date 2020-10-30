// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once

#include <memory>
#include <vector>

#include <wil/resource.h>

namespace SafeArrayUtil
{

// A `unique_any` alias that handles safely disposing of a SAFEARRAY.
using unique_safearray = wil::unique_any<SAFEARRAY*, decltype(&::SafeArrayDestroy), ::SafeArrayDestroy>;

// A helper template that can be used to map a VARTYPE to a C++ type that it represents
// statically at compile time.
//
// # Example:
// ```
// using ActualType = typename VarTypeHelper<VT_UI4>::Type;
// ```
template<VARTYPE vt>
struct VarTypeHelper;

template<>
struct VarTypeHelper<VT_UI4>
{
    using Type = unsigned int;
};

template<>
struct VarTypeHelper<VT_I4>
{
    using Type = int;
};

template<>
struct VarTypeHelper<VT_UNKNOWN>
{
    using Type = IUnknown*;
};

template<>
struct VarTypeHelper<VT_R8>
{
    using Type = double;
};

template<>
struct VarTypeHelper<VT_BSTR>
{
    using Type = wchar_t*;
};


template <class TElement>
class SafeArrayAccessor
{
public:
    SafeArrayAccessor() = default;

    SafeArrayAccessor(_In_ SAFEARRAY* safeArray, VARTYPE vtExpected)
    {
        THROW_IF_FAILED(Access(safeArray, vtExpected));
    }

    ~SafeArrayAccessor()
    {
        if (m_safeArray != nullptr)
        {
            ::SafeArrayUnaccessData(m_safeArray);
        }
    }

    SafeArrayAccessor(const SafeArrayAccessor& rhs) = delete;
    SafeArrayAccessor& operator=(const SafeArrayAccessor& rhs) = delete;
    SafeArrayAccessor(SafeArrayAccessor&& rhs) = delete;
    SafeArrayAccessor& operator=(SafeArrayAccessor&& rhs) = delete;

    HRESULT Access(_In_ SAFEARRAY* safeArray, VARTYPE vtExpected) noexcept
    {
        FAIL_FAST_IF(m_safeArray != nullptr);

        RETURN_HR_IF_NULL(E_INVALIDARG, safeArray);

        m_safeArray = safeArray;

        // Check that it's a 1-D array of the expected type...
        RETURN_HR_IF(E_INVALIDARG, ::SafeArrayGetDim(m_safeArray) != 1);

        VARTYPE actualType;
        RETURN_IF_FAILED(::SafeArrayGetVartype(m_safeArray, &actualType));
        if (actualType != vtExpected)
        {
            // Special case to deal with SafeArrays from managed code
            // Managed interop will bring in arrays of ints as VT_INT
            // This is functionally the same as VT_I4 for this code, so
            // allow them to pass as VT_I4.
            // Actually converting them to VT_I4 arrays would mean full
            // array copies, which would both make the code more complex
            // and less perfomant, making this short-circuit the best way
            // to allow them through.
            RETURN_HR_IF(E_INVALIDARG, !(actualType == VT_INT && vtExpected == VT_I4));
        }

        LONG lb;
        LONG ub;
        RETURN_IF_FAILED(::SafeArrayGetLBound(m_safeArray, 1, &lb));
        RETURN_IF_FAILED(::SafeArrayGetUBound(m_safeArray, 1, &ub));
        m_count = ub - lb + 1;

        RETURN_IF_FAILED(::SafeArrayAccessData(m_safeArray, reinterpret_cast<void**>(&m_data)));
        return S_OK;
    }

    UINT Count() const noexcept
    {
        return m_count;
    }

    const TElement& operator[](UINT i) const noexcept
    {
        return m_data[i];
    }

    TElement& operator[](UINT i) noexcept
    {
        return m_data[i];
    }

    operator TElement*() noexcept
    {
        return m_data;
    }

    TElement* Ptr() noexcept
    {
        return m_data;
    }

private:
    SAFEARRAY* m_safeArray = nullptr;
    UINT m_count = 0;
    TElement* m_data = nullptr;
};

template<class T>
inline
HRESULT SafeArrayToArray(
    _In_ SAFEARRAY* safeArray,
    _Outptr_result_buffer_(*countOut) T** arrayOut,
    _Out_ int* countOut,
    VARTYPE vt) noexcept
{
    SafeArrayAccessor<T> accessor;
    RETURN_IF_FAILED(accessor.Access(safeArray, vt));

    std::unique_ptr<T[]> arrayCopy(new (std::nothrow) T[accessor.Count()]);
    RETURN_IF_NULL_ALLOC(arrayCopy);
    for (UINT i = 0 ; i < accessor.Count() ; i++)
    {
        arrayCopy[i] = accessor[i];
    }

    *countOut = accessor.Count();
    *arrayOut = arrayCopy.release();
    return S_OK;
}

// Convert the given SAFEARRAY containing elements of the VARTYPE provided as the template
// parameter to a vector of type T. The conversion from the underlying SAFEARRAY type to T
// should be performed by `conversionFn`. If `conversionFn` returns a value that cannot be
// implicitly converted to `T`, the compiler will reject the call.
template<VARTYPE vt, class T, class Fn>
inline
std::vector<T> SafeArrayToVector(_In_ SAFEARRAY* safeArray, Fn&& conversionFn)
{
    std::vector<T> result;
    using SafeArrayElementT = typename VarTypeHelper<vt>::Type;

    SafeArrayAccessor<SafeArrayElementT> accessor;
    THROW_IF_FAILED(accessor.Access(safeArray, vt));

    for (UINT i = 0; i < accessor.Count(); ++i)
    {
        result.push_back(conversionFn(accessor[i]));
    }

    return result;
}

// A convenience overload that by default assumes that the output vector's type should be the same
// as the original SAFEARRAY's element type. The elements are copied into the array
// by using that type's copy ctor. If a different type parameter is provided, then the template
// will compile as long as there exists an implicit conversion between the SAFEARRAY's underlying
// type and `T`.
template<VARTYPE vt, class T = VarTypeHelper<vt>::Type>
inline
std::vector<T> SafeArrayToVector(_In_ SAFEARRAY* safeArray)
{
    return SafeArrayToVector<vt, T>(safeArray, [](auto& el) { return el; });
}

// The noexcept overload, where the type conversion is automatic.
template<VARTYPE vt, class T>
inline
HRESULT SafeArrayToVector(_In_ SAFEARRAY* safeArray, std::vector<T>& arrayOut) noexcept try
{
    arrayOut = SafeArrayToVector<vt, T>(safeArray);
    return S_OK;
}
CATCH_RETURN()

// The noexcept overload, where the type conversion is performed by the given functor.
template<VARTYPE vt, class T, class Fn>
inline
HRESULT SafeArrayToVector(_In_ SAFEARRAY* safeArray, Fn&& conversionFn, std::vector<T>& arrayOut) noexcept try
{
    arrayOut = SafeArrayToVector<vt, T>(safeArray, conversionFn);
    return S_OK;
}
CATCH_RETURN()

template<class T>
inline
HRESULT ArrayToSafeArray(_In_ const T* originalArray, int count, VARTYPE vt, _Outptr_ SAFEARRAY** resultOut) noexcept try
{
    *resultOut = nullptr;
    THROW_HR_IF(E_INVALIDARG, count < 0);
    unique_safearray safeArray(::SafeArrayCreateVector(vt, 0, static_cast<ULONG>(count)));
    THROW_IF_NULL_ALLOC(safeArray);

    {
        SafeArrayAccessor<T> accessor(safeArray.get(), vt);

        for (unsigned int i = 0; i < static_cast<unsigned int>(count); ++i)
        {
            accessor[i] = originalArray[i];
        }
    }

    *resultOut = safeArray.release();
    return S_OK;
}
CATCH_RETURN();

// A type-safe conversion function for going from an array of `T` to a SAFEARRAY of the given VT.
//
// It uses the `VarTypeHelper` to map the given VT to an actual type. If there is no automatic
// conversion possible between the array type and this type, compilation will fail, forcing the
// user to reconcile the array type with the SAFEARRAY's VT.
//
// # Examples
// 
// ## Successfully convert an int array to a VT_I4 SAFEARRAY.
// ```
// std::vector<int> arr;
// unique_safearray res;
// RETURN_IF_FAILED(ArrayToSafeArray<VT_I4>(arr.data(), static_cast<int>(arr.size()), &res));
// ```
//
// ## Conversion fails because there's no automatic type conversion between HWND and a VT_UI4.
// ```
// std::vector<HWND> arr;
// unique_safearray res;
// // NOTE: Compile error! No conversion between HWND and unsigned int.
// RETURN_IF_FAILED(ArrayToSafeArray<VT_UI4>(arr.data(), static_cast<int>(arr.size()), &res));
// ```
template<VARTYPE vt, class T>
inline
HRESULT ArrayToSafeArray(_In_ const T* originalArray, int count, _Outptr_ SAFEARRAY** resultOut) noexcept try
{
    *resultOut = nullptr;
    *resultOut = ArrayToSafeArray<vt>(originalArray, count, [](const auto& el) { return el; }).release();

    return S_OK;
}
CATCH_RETURN();

template<VARTYPE vt, class T>
inline
unique_safearray ArrayToSafeArray(_In_ const T* originalArray, int count)
{
    unique_safearray result;
    THROW_IF_FAILED(ArrayToSafeArray<vt>(originalArray, count, &result));

    return result;
}

// A type-safe conversion function for going from an array of `T` to a SAFEARRAY of the given VT.
//
// It uses the `VarTypeHelper` to map the given VT to an actual type. It uses the given conversion
// function to convert the array element to the SAFEARRAY's type.
//
// This is provided as a convenience overload, so that callers don't have to construct temporary
// arrays when they have mismatched array and target SAFEARRAY types.
template<VARTYPE vt, class T, class Fn>
inline
unique_safearray ArrayToSafeArray(_In_ const T* originalArray, int count, Fn&& conversionFn)
{
    THROW_HR_IF(E_INVALIDARG, count < 0);
    unique_safearray safeArray(::SafeArrayCreateVector(vt, 0, static_cast<ULONG>(count)));
    THROW_IF_NULL_ALLOC(safeArray);

    {
        // The array type is obtained by mapping the vt to the corresponding type. Note that this _could_ be a different
        // type than the array element type, in which case the compiler will try to use an appropriate conversion.
        // If none exists, the compilation will fail, making us find the correct safearray type.
        using SafeArrayElementT = typename VarTypeHelper<vt>::Type;
        SafeArrayAccessor<SafeArrayElementT> accessor(safeArray.get(), vt);

        for (unsigned int i = 0; i < static_cast<unsigned int>(count); ++i)
        {
            accessor[i] = conversionFn(originalArray[i]);
        }
    }

    return safeArray;
}

template<class T>
inline
HRESULT SafeArrayCompare(_In_ SAFEARRAY* array1, _In_ SAFEARRAY* array2, VARTYPE vt, _Out_ BOOL* same) noexcept try
{
    *same = FALSE;

    SafeArrayAccessor<T> a1(array1, vt);
    SafeArrayAccessor<T> a2(array2, vt);
    if (a1.Count() != a2.Count())
    {
        return S_OK;
    }

    for (unsigned int i = 0; i < a1.Count(); ++i)
    {
        if (a1[i] != a2[i])
        {
            return S_OK;
        }
    }

    *same = TRUE;
    return S_OK;
}
CATCH_RETURN();

HRESULT SafeArrayGetCount(_In_ SAFEARRAY* array, _Out_ long* size) noexcept;

} // SafeArrayUtil
