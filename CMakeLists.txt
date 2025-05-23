# The MIT License (MIT)

# Copyright (c) 2015-2025 OpenImageDebugger contributors
# (https://github.com/OpenImageDebugger/OpenImageDebugger)

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.

cmake_minimum_required(VERSION 3.28)

set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type")
set(CMAKE_INSTALL_PREFIX /usr/local CACHE PATH "Install path")

# We want to be as strict as possible with the standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

add_compile_options("$<$<PLATFORM_ID:Linux,Darwin>:-Wall;-Wextra;-pedantic;-fvisibility=hidden>")

project(ModulesTutorial CXX)

set(SOURCES
    ModulesTutorial.cpp
    BasicPlane.Figures.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME}
        PROPERTIES CXX_SCAN_FOR_MODULES ON
)

target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        BasicPlane.Figures.cppm
)

target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_options(${PROJECT_NAME} PRIVATE "$<$<PLATFORM_ID:Linux>:-Wl,--exclude-libs,ALL>")


install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ModulesTutorial)
