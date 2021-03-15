[![Build Status](https://dev.azure.com/ms/Microsoft-UI-UIAutomation/_apis/build/status/Microsoft-UI-UIAutomation%20Desktop%20CI?branchName=main)](https://dev.azure.com/ms/Microsoft-UI-UIAutomation/_build/latest?definitionId=378&branchName=main)

# Windows UIAutomation platform utility libraries

This repository contains utility libraries that simplify consuming [Windows UIAutomation](https://docs.microsoft.com/en-us/windows/win32/winauto/entry-uiauto-win32)
APIs.

## UIAutomation Remote Operations

Remote Operations is an upcoming API exposed by the Windows UIAutomation platform, that aims to give clients
the flexibility to avoid the explosion of cross-process calls by giving them control over when cross-process
work happens. This flexibility allows clients to build applications that perform fewer cross-process calls,
reducing the overhead of cross-process communication latency.

This library exposes an API that simplifies constructing and executing Remote Operations, by exposing a
higher-level API that mirrors the existing/"classic" COM UIA APIs.

The platform API is currently part of preview Windows builds and the preview SDK. It requires a Windows build
`10.0.19613.0` or newer at runtime and a matching preview SDK to build the solution.

Changes to the underlying platform APIs are still possible and as such this library itself might need to
evolve alongside the platform.

### WinRT Builder API

The bulk of the Remote Operations helper code is in a WinRT API exposed by the `Microsoft.UI.UIAutomation` DLL
built from the project of the same name. This DLL exposes an API under the `Microsoft.UI.UIAutomation`
namespace, which helps build up a Remote Operation by using a natural API, that closely mirrors classic
UIA APIs.

This API can be consumed from a wide variety of programming languages. For C++ consumers, we recommend
using the [C++/WinRT projection](https://github.com/Microsoft/cppwinrt). See the functional tests project
for an example.

Other languages, such as Python or C# can also consume WinRT through language-specific projections.
For instance, see the minimal C# demo that's included in the project.

Please note that WinRT as the ABI technology of choice in no way precludes clients from consuming
this API from plain Win32 processes. WinRT does not tie APIs to _only_ be usable from [Universal
Windows Applications](https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide).

### C++ Abstraction

The `UiaOperationAbstraction` project contains a static C++ library that consumers can use in their
C++ client code. The goal of this library is to provide a C++ interface that lets users write code
to express a UIAutomation algorithm that can then be executed as part of a single Remote Operation or
in a "classic" approach where each call elicits a separate cross-process call.

This allows clients to switch between the two "modes" dynamically, which can be helpful for interop
with existing code that doesn't use Remote Operations or for simpler debugging of the logic in an
algorithm.

Note that this library isn't necessarily the best fit for every C++ consumer, as the ability to switch
between these "modes" does come at a runtime cost.

### Building

In order to build the solution, please make sure you have the [Windows Insider Preview SDK](https://www.microsoft.com/en-us/software-download/windowsinsiderpreviewSDK)
installed. 

The solution can then be built either from Visual Studio or simply from the Visual Studio Developer
Console using `msbuild`. For instance:

```
msbuild UIAutomation.sln /p:Configuration=Release,Platform=x64
```

These projects target SDK version 10.0. Note that breaking changes can occur in preview SDKs, so if you install a new preview SDK there are no guarantees that the platform API will be unchanged and as such the projects might not build or they could work differently at runtime.
 
# Contributing

This project welcomes contributions and suggestions.  Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.opensource.microsoft.com.

When you submit a pull request, a CLA bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., status check, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.
