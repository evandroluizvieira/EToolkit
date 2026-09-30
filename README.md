# EToolkit

![Logo](https://github.com/evandroluizvieira/EToolkit/blob/master/resource/Brand.png)

[![C++](https://img.shields.io/badge/C++-004488)](https://cplusplus.com/)
[![BSL1.0 License](https://img.shields.io/badge/License-BSL-green.svg)](https://choosealicense.com/licenses/bsl-1.0/)
[![WinAPI](https://img.shields.io/badge/WinAPI-0078d4)](https://learn.microsoft.com/en-us/windows/win32/apiindex/api-index-portal/)

## Overview
EToolkit is a C++ library that serves as a WinAPI (old Win32) wrapper.

It provides convenient abstractions for Windows-specific operations, making it easier to develop Windows applications in C++.

The library is open source and licensed under the BSL 1.0 license.

The code is organized into several key segments (folders), each serving a specific purpose:
- **containers:** Contains data container classes like dynamic and static arrays.
- **controls:** Houses user interface control components, like labels and buttons.
- **core:** Includes essential core components, such as the application class, macros, types, and utility headers.
- **events:** Focuses on event handling classes for user input, like keyboard, mouse, and window-related events.
- **exceptions:** Manages exception-related classes, covering general and specific exceptions.
- **geometry:** Contains classes for handling geometric concepts, such as positions, sizes, and bounds in various dimensions.
- **graphics:** Includes classes for specifying colors in different dimensions, essential for graphical applications.
- **mathematics:** Provides mathematical functions and classes for matrices, projections, transformations, and vectors in multiple dimensions.
- **menus:** Orchestrates menu interactions, streamlining user navigation intuitively and efficiently
- **string:** Manages string-related classes, including C-style and C++ style strings.
- **synchronization:** Focuses on thread synchronization and management, featuring mutual exclusion mechanisms.
- **windows:** Contains classes and headers for window creation and management, for graphical user interface (GUI) applications.

## Installation
To get started, clone the repository:
```bash
git clone https://github.com/evandroluizvieira/EToolkit.git
```

## Containers

The container API provides the following contracts and implementations:

- `IContainer<DataType, SizeType>` — common size, data, clear, empty, comparison, and swap operations.
- `IIterable<DataType>` — mutable, constant, and constant-only iteration operations.
- `IStaticContainer<DataType, SizeType, SizeValue>` — fixed-size container contract; `SizeValue` must be greater than zero.
- `IDynamicContainer<DataType, SizeType>` — runtime size, capacity, insertion, removal, resize, and reserve operations.
- `StaticArray<DataType, SizeType, SizeValue>` — compile-time-sized array implementation.
- `DynamicArray<DataType>` — runtime-sized array implementation.

The public forwarding header is `include/EContainer`.

## Tests and build

The project uses one out-of-source CMake build directory at the repository root. Test source files
remain under `test/`, while generated binaries and CTest metadata are written below `build/test/`.
The tests are organized by production class and use a local assertion runner implemented in
`test/TestAssertions.hpp`. The test code does not use GoogleTest, GoogleMock, FetchContent, or
another external test framework. CTest is only the test execution and reporting tool provided by
CMake; it is not the assertion framework used by the tests.

```text
cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build --output-on-failure
```

## Build
Preprocessor flags:
```
-DETOOLKIT_EXPORT
```

Include flags:
```
-I"..\EToolkit\include"
```

Libraries linker:
```
-lgdi32
-lopengl32
```

## Usage
```c++
#include <EApplication>
#include <EWindow>

using EToolkit::Application;
using EToolkit::Window;

int main(int argc, char** argv){
	Application application;

	Window window;
	window.setVisility(true);
	window.setEnability(true);
	window.setBounds(200, 200, 800, 600);

	return application.execute();
}
```
