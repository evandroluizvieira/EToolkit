# EToolkit

![Logo](https://github.com/evandroluizvieira/EToolkit/blob/master/resource/Brand.png)

[![C++](https://img.shields.io/badge/C++-004488)](https://cplusplus.com/)
[![BSL1.0 License](https://img.shields.io/badge/License-BSL-green.svg)](https://choosealicense.com/licenses/bsl-1.0/)
[![WinAPI](https://img.shields.io/badge/WinAPI-0078d4)](https://learn.microsoft.com/en-us/windows/win32/apiindex/api-index-portal/)
[![CI](https://github.com/evandroluizvieira/EToolkit/actions/workflows/ci.yml/badge.svg)](https://github.com/evandroluizvieira/EToolkit/actions/workflows/ci.yml)
[![Version](https://img.shields.io/github/v/tag/evandroluizvieira/EToolkit?sort=semver&label=version)](https://github.com/evandroluizvieira/EToolkit/releases)

## Overview
EToolkit is a C++ library that serves as a WinAPI (old Win32) wrapper.

It provides convenient abstractions for Windows-specific operations, making it easier to develop Windows applications in C++.

The repository is centered on the `EToolkit` library. On Windows, the default build generates both
a DLL with its import library and a static library. The `applications/` directory contains small
executables that consume the public API and serve as manual integration checks. They complement,
but do not replace, the automated tests in `test/`.

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

## Geometry

The geometry API provides `Position1/2/3`, `Size1/2/3`, and `Bounds1/2/3` templates. Each template
uses a value type, an explicit index/length type, and a `Length` non-type parameter:

```cpp
template<class ValueType, class SizeType, SizeType Length>
```

Multidimensional positions and sizes use virtual inheritance so bounds preserve one shared
`StaticArray` subobject. Bounds expose inherited position and size accessors with `using`
declarations and use these contiguous mappings:

| Type | Mapping |
|---|---|
| `Bounds1` | `[0]` x, `[1]` width |
| `Bounds2` | `[0]` x, `[1]` y, `[2]` width, `[3]` height |
| `Bounds3` | `[0]` x, `[1]` y, `[2]` z, `[3]` width, `[4]` height, `[5]` depth |

The most-derived bounds constructor initializes the shared storage. The geometry tests verify the
field mappings and that access through the inherited views addresses the same array elements.

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

The project uses one out-of-source CMake build directory at the repository root. The library,
application binaries, test binaries, and CTest metadata are generated below `build/`; no root-level
`Debug/` or `Release/` directories are required. With a multi-configuration generator, such as
Visual Studio, configuration-specific outputs are generated below `build/Debug/` and
`build/Release/`.
The tests are organized by production class and use a local assertion runner implemented in
`test/TestAssertions.hpp`. The test code does not use GoogleTest, GoogleMock, FetchContent, or
another external test framework. CTest is only the test execution and reporting tool provided by
CMake; it is not the assertion framework used by the tests.

```text
cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build --output-on-failure
```

The default configuration builds both library variants, the `etoolkit_tests` executable,
and `EToolkitSimpleWindow` from `applications/simple_window/`. The library itself has no executable
because it does not define `main()`. The test executable is generated because CTest and the F5 test
configuration execute that binary. Configure with `-DETOOLKIT_BUILD_APPLICATIONS=OFF` to omit the
examples.

## Continuous integration and releases

GitHub Actions validates Pull Requests targeting `master` and pushes to `master` by configuring,
building, and testing the project on Windows with MSYS2 MinGW-w64, CMake, Ninja, and CTest.
The authoritative development version is stored in `VERSION`; build metadata and generated
documentation consume that value.
The generated API reference is published at
https://evandroluizvieira.github.io/EToolkit/ after successful runs on `master`.
Versioned distribution is separate: an approved SemVer tag will trigger a clean build and publish
versioned ZIP archives containing the DLL, development libraries and headers, `etoolkit_tests.exe`,
and example applications to a GitHub Release. GitHub Packages will only be enabled after a package
format and consumer installation contract are defined.

On the first push to `master`, the Auto Version workflow automatically creates the initial tag
`v0.0.0`, even if no release-worthy commit exists. That tag is a complete first release: it triggers
the Windows build, tests, ZIP package, SHA-256 checksum, and GitHub Release publication. Later
`fix:` and `feat:` commits merged into `master` may create patch and minor tags; breaking changes
create major tags and trigger the same release process.

Project governance and automation policies are documented in [DEVELOPMENT.md](DEVELOPMENT.md),
[CONTRIBUTING.md](CONTRIBUTING.md), [RELEASE.md](RELEASE.md), and [DEPLOYMENT.md](DEPLOYMENT.md).
Architecture, requirements, roadmap, implementation, operational, risk, and migration documents
are maintained in the repository root alongside [PROJECT_STATUS.md](PROJECT_STATUS.md).

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

The following is the minimal application example used by
`applications/simple_window/main.cpp`:

```c++
#include <EApplication>
#include <EWindow>

int main(){
	EToolkit::Application application;
	EToolkit::Window window;

	window.setText("EToolkit basic application");
	window.setBounds(100, 100, 800, 600);
	window.setEnability(true);
	window.setVisibility(true);

	return application.execute();
}
```
