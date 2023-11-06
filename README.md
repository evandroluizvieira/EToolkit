# EToolkit

![Logo](https://github.com/evandroluizvieira/EToolkit/blob/master/resource/Logo.png)

[![C++](https://img.shields.io/badge/C++-004488)](https://cplusplus.com/)
[![BSL1.0 License](https://img.shields.io/badge/License-BSL-green.svg)](https://choosealicense.com/licenses/bsl-1.0/)
[![WinAPI](https://img.shields.io/badge/WinAPI-0078d4)](https://learn.microsoft.com/en-us/windows/win32/apiindex/api-index-portal/)

## Overview
EToolkit is a C++ library that serves as a WinAPI (old Win32) wrapper.

It provides convenient abstractions for Windows-specific operations, making it easier to develop Windows applications in C++.

The library is open source and licensed under the BSL 1.0 license.

The code is organized into several key segments (folders), each serving a specific purpose:
- containers: Contains data container classes like dynamic and static arrays.
- controls: Houses user interface control components, including generic controls and buttons.
- core: Includes essential core components, such as the application class, macros, types, and utility headers.
- events: Focuses on event handling classes for user input, like keyboard, mouse, and window-related events.
- exceptions: Manages exception-related classes, covering general and specific exceptions.
- geometry: Contains classes for handling geometric concepts, such as positions, sizes, and bounds in various dimensions.
- graphics: Includes classes for specifying colors in different dimensions, essential for graphical applications.
- mathematics: Provides mathematical functions and classes for matrices, projections, transformations, and vectors in multiple dimensions.
- string: Manages string-related classes, including C-style and C++ style strings.
- synchronization: Focuses on thread synchronization and management, featuring mutual exclusion mechanisms.
- windows: Contains classes and headers for window creation and management, for graphical user interface (GUI) applications.

## Installation
To get started, clone the repository:
```bash
git clone https://github.com/evandroluizvieira/EToolkit.git
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
