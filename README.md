# EToolkit

![Logo](https://github.com/evandroluizvieira/EToolkit/blob/HEAD/resource/Brand.png)

[![C++11](https://img.shields.io/badge/C%2B%2B-11-004488.svg?labelColor=555555)](https://en.cppreference.com/w/cpp/11)
[![Win32 API](https://img.shields.io/badge/Win32_API-Win32-8A2BE2.svg?labelColor=555555)](https://learn.microsoft.com/en-us/windows/win32/apiindex/api-index-portal/)
[![CMake 3.16](https://img.shields.io/badge/CMake-3.16-008000.svg?labelColor=555555)](https://cmake.org/cmake/help/v3.16/)
[![BSL 1.0 License](https://img.shields.io/badge/License-BSL%201.0-FF8C00.svg?labelColor=555555)](https://choosealicense.com/licenses/bsl-1.0/)
[![CI](https://github.com/evandroluizvieira/EToolkit/actions/workflows/ci.yml/badge.svg)](https://github.com/evandroluizvieira/EToolkit/actions/workflows/ci.yml)
[![Documentation](https://img.shields.io/badge/docs-Doxygen-008B8B.svg?labelColor=555555)](https://evandroluizvieira.github.io/EToolkit/)
[![Version](https://img.shields.io/github/v/tag/evandroluizvieira/EToolkit?sort=semver&label=version&labelColor=555555&color=C62828)](https://github.com/evandroluizvieira/EToolkit/releases)

## Overview

EToolkit is a C++ library that serves as a Win32 API wrapper.

This first `main` commit establishes the project baseline (governance, automation, quality, and
release configuration). Implementation modules are added in subsequent development branches.

The library is open source and licensed under the BSL 1.0 license.

## Installation
To get started, clone the repository:
```bash
git clone https://github.com/evandroluizvieira/EToolkit.git
```

## Build and tests

```text
cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build --output-on-failure
```

In this initial setup commit, the build validates repository configuration and workflow wiring.

## Continuous integration and releases

GitHub Actions validates Pull Requests targeting the project's primary branch, defined in
`main`, and pushes to that branch.

The authoritative development version is stored in `VERSION`.
Versioned distribution is separate: an approved SemVer tag triggers packaging and publication to
GitHub Releases.

## Project governance

- [DEVELOPMENT.md](DEVELOPMENT.md)
- [CONTRIBUTING.md](CONTRIBUTING.md)
- [ARCHITECTURE.md](ARCHITECTURE.md)
- [RELEASE.md](RELEASE.md)
- [DEPLOYMENT.md](DEPLOYMENT.md)
- [PROJECT_STATUS.md](PROJECT_STATUS.md)
- [REQUIREMENTS.md](REQUIREMENTS.md)
- [ROADMAP.md](ROADMAP.md)
- [IMPLEMENTATION_PLAN.md](IMPLEMENTATION_PLAN.md)
- [TEST_PLAN.md](TEST_PLAN.md)
- [OPERATIONS.md](OPERATIONS.md)
- [RISK_REGISTER.md](RISK_REGISTER.md)

## Usage

Usage examples are documented as part of the regular development flow after the baseline branch is
published.
