#
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
#
cmake_minimum_required(VERSION 3.30)

project(libdmi++
    VERSION 0.1.0
    DESCRIPTION "DMI/SMBIOS interface"
    HOMEPAGE_URL https://github.com/aspie-the-cat/libdmixx
    LANGUAGES CXX)

set(CMAKE_COLOR_DIAGNOSTICS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -pedantic
)

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck REQUIRED)
if(CMAKE_CXX_CPPCHECK)
    list(APPEND
        CMAKE_CXX_CPPCHECK
            "--platform=native"
            "--enable=all"
            "--inconclusive"
            "--inline-suppr"
            "--verbose"
    )
endif()

include(CTest)
include(CPack)

add_library(libdmixx OBJECT)
set_target_properties(libdmixx
    PROPERTIES
        POSITION_INDEPENDENT_CODE ON
)
target_include_directories(libdmixx
    PUBLIC
        ${PROJECT_BINARY_DIR}/include
)
target_sources(libdmixx
    PRIVATE
        src/context.cc
)

add_library(libdmixx-static STATIC $<TARGET_OBJECTS:libdmixx>)
set_target_properties(libdmixx-static
    PROPERTIES
        OUTPUT_NAME dmi++
)

add_library(libdmixx-shared SHARED $<TARGET_OBJECTS:libdmixx>)
set_target_properties(libdmixx-shared
    PROPERTIES
        OUTPUT_NAME dmi++
)
