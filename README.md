| ![Logo](https://github.com/evandroluizvieira/EToolkit/blob/master/resource/Logo.png) | [![C++](https://img.shields.io/badge/C++-004488)](https://cplusplus.com/)<br/>[![BSL1.0 License](https://img.shields.io/badge/License-BSL-green.svg)](https://choosealicense.com/licenses/bsl-1.0/)<br/>[![WinAPI](https://img.shields.io/badge/WinAPI-0078d4)](https://learn.microsoft.com/en-us/windows/win32/apiindex/api-index-portal/)|
|:-:|:-:|

# EToolkit
WinAPI (old Win32) wrapper in c++.

## Install
Clone the repository by ```git clone https://github.com/evandroluizvieira/EToolkit.git```

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
