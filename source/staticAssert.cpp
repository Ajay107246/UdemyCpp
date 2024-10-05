#include "../header/staticAssert.hpp"

void all_static_assert_methods()
{
    /*
        chk perform at runtime, not compile time
        this will still allow compilation of this code in different mode
        problem: this chk is performed at runtime, code still compile in different mode
        want: prevent compilation of code, if its not compiled in 32-bit mode
        using static_assert this can achieve, 
        static_assert will stop compilation when expression returns false

        using static_assert, we can check an expression at compiler time and if it returns false
        then compiler will stop compilation and print this message as diagnostic message
        we can also use type traits here, cause TT will return boolean at compile time

    */
    //static_assert(sizeof(void*)==4, "compile in 32-bit mode only"); //output: static assertion failed: compile in 32-bit mode only
    static_assert(sizeof(void*)!=4, "compile in 32-bit mode only"); //like below if case
    if (sizeof(void *)!=4)
    {
        std::cout << "Not 32-bit mode" << std::endl;
    }
    else
    {
        //nothing
    }    
}

/*
    how to change 32-bit mode in vscode:
    1. Install MinGW-w64: Ensure you have the 32-bit version of MinGW-w64 installed. You can download it from the MSYS2 website.
    
    2. Configure VS Code:
    Open VS Code and install the C/C++ extension if you haven’t already.
    Create or open your C++ project.
    Open the Command Palette (Ctrl+Shift+P) and type C/C++: Edit Configurations (UI).
    In the configurations, set the compilerPath to point to the 32-bit version of g++ (e.g., C:\\msys64\\mingw32\\bin\\g++.exe).
    
    3. Tasks Configuration:
    Create a tasks.json file in the .vscode folder of your project.
    Configure it to use the 32-bit compiler:
    
    JSON

    {
        "version": "2.0.0",
        "tasks": [
            {
                "label": "build",
                "type": "shell",
                "command": "g++",
                "args": [
                    "-m32",
                    "-g",
                    "${file}",
                    "-o",
                    "${fileDirname}\\${fileBasenameNoExtension}.exe"
                ],
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
                "problemMatcher": ["$gcc"],
                "detail": "Generated task by Debugger."
            }
        ]
    }

    4. Using CMake
    If you are using CMake, you can specify the target architecture in your CMakeLists.txt:

    set(CMAKE_GENERATOR_PLATFORM x86)
*/