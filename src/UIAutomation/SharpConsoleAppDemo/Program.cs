// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;

using Microsoft.UI.UIAutomation;
using Windows.UI.UIAutomation.Core;

namespace SharpConsoleAppDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            // Demonstrates how to activate the UIAutomation platform CoreAutomationRemoteOperation runtimeclass.
            // This is a lower-level API that Microsoft.UI.UIAutomation.AutomationRemoteOperation is built on top of.
            Console.WriteLine("Activating Windows.UI.UIAutomation.Core.CoreAutomationRemoteOperation...");
            try
            {
                CoreAutomationRemoteOperation coreOp = new CoreAutomationRemoteOperation();
            }
            catch (Exception)
            {
                Console.WriteLine("Failed to activate the platform runtimeclass. Are you running on a machine with the required platform support?");
                throw;
            }
            Console.WriteLine("Activated!");

            // Demonstrates activating the builder library's AutomationRemoteOperation. This is what most clients would want to use,
            // rather than the platform's CoreAutomationRemoteOperation.
            //
            // The helper will create a platform CoreAutomationRemoteOperation under the hood and use it to actually execute the
            // operation that is built up through its more convenient API.
            Console.WriteLine("Activating Microsoft.UI.UIAutomation.AutomationRemoteOperation...");
            try
            {
                AutomationRemoteOperation op = new AutomationRemoteOperation();
            }
            catch (System.TypeLoadException ex)
            {
                if (ex.InnerException.HResult == -2147221164)
                {
                    Console.WriteLine("REGDB_E_CLASSNOTREG -- is the SxS manifest built?");
                }
                throw;
            }
            catch (System.IO.FileNotFoundException)
            {
                Console.WriteLine("FileNotFound -- is Microsoft.UI.UIAutomation.dll in the same dir as this exe?");
                throw;
            }
            catch (System.BadImageFormatException)
            {
                Console.WriteLine("BadImageFormat -- is Microsoft.UI.UIAutomation.dll of opposite bitness from this exe?");
                throw;
            }

            Console.WriteLine("Activated!");
        }
    }
}
