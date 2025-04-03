# C++ Project Template with CMake and GoogleTest

This repository provides a structured template to quickly set up and build C++ projects using **CMake** for build automation and **GoogleTest** for unit testing. It simplifies initial project setup and promotes good practices for project organization and testing. 

Additionally, the template integrates the external library **Eigen3**, which is useful for numerical computations and linear algebra operations.

The template allows you to build a Command Line Interface (CLI) application, which is defined through the `Config` class. The application accepts command-line arguments:

- `-f`: input file [**required**]

- `-o`: output file

- `-v`: display program version

- `-h`: display help message

You can customize the program name and version independently of the CMake configuration by editing the `Config` class.

## Overview

### Features

- **CMake Integration**: Streamlined build system for managing dependencies and project configuration.

- **GoogleTest Integration**: Robust framework for writing and executing unit tests.

- **Eigen3 Integration**: Powerful library for mathematical operations, especially useful in scientific computing and algorithm development.

- **Modular Structure**: Clear separation between application source, external libraries, and tests.

---

### Project Structure

``` text
cpp-template_cmake-gtest/
├── cmake/                  # CMake configuration files
│   └── Dependencies.cmake  # External dependencies configuration
├── include/
│   └── external/           # External library headers
├── src/                    # Application source code
│   ├── app/                # - Main code
│   └── core/               # - another code (Matrix, Vector3D, ...)
└── tests/                  # Unit tests using GoogleTest
```

---

## Getting started

### Prerequisites

|Software|Version|
|-|-|
|**CMake**|3.10 or newer|
|**C++ Compiler**|gcc or clang|
|**C++ standard**|14 or newer|

### Clone

``` console
git clone https://github.com/Baro-00/cpp-template_cmake-gtest.git
cd cpp-template_cmake-gtest
```

### Build

Build the project using:

``` console
mkdir build && cd build && cmake .. && cmake --build .
```

Alternatively, use the proper IDE Extension according to your platform. For example **CMake Tools** for **VS Code**.

> **Tip**: If works on Windows, it is recommended to use **WSL** instead of PowerShell.

### Run tests

After building the project, execute tests using:

```
ctest --output-on-failure
```

*Alternatively*, directly execute the specific test binary:

``` console
./tests/my_tests
```

---

## Customization

### Project Information

You can edit project details directly in the root `CMakeLists.txt`:

``` cmake
# Project
project(USR_PROJECT_NAME
    VERSION 1.0.0
    DESCRIPTION "Description of the project"
    LANGUAGES CXX
)
```

---

## Adding your code

### Source files

- Place your source files in the `src/` directory

- Register new source files by editing `src/CMakeLists.txt`:

``` cmake
# Creating the application components library
add_library(app_components
    app/Config.cpp
    core/Vector3D.cpp
    core/Quaternion.cpp
    core/Matrix.cpp
    # * Add other source files below ...
)
```

### Header files

- Add your header file under `include/`

- Alternatively, place your header file near to the source code. For example class `Config`:

``` text
src/
└── app
    ├── Config.cpp
    ├── Config.hpp
    └── main.cpp
```

### Unit Tests

- Write your unit tests in the `tests/` directory following **GoogleTest conventions**

- Register new tests by editing `tests/CMakeLists.txt` with function *`add_app_test(test_name test_source)`*

``` cmake
# UNIT Tests
add_app_test(matrix_tests unit/core/MatrixTests.cpp)
add_app_test(vector_tests unit/core/Vector3DTests.cpp)
add_app_test(quaternion_tests unit/core/QuaternionTests.cpp)
```

### Managing Dependencies

Dependencies are configured in the `cmake/Dependencies.cmake` file. Here you can add, modify, or remove external libraries used by your project.

#### Removing Eigen3

If Eigen3 is not needed for your project, change the following option in root `CMakeLists.txt` to `OFF`:

``` cmake
option(USE_EIGEN3 "Use Eigen3 library" ON)
```

---

## License

This template is provided under the MIT License. See [LICENSE](LICENSE) for details.
