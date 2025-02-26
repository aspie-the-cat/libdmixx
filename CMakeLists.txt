#
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
#
cmake_minimum_required(VERSION 3.30)

project(libdmi++
    VERSION 0.1.0
    DESCRIPTION "DMI/SMBIOS interface"
    HOMEPAGE_URL https://github.com/aspie-the-cat/libdmixx
    LANGUAGES C CXX)

option(ENABLE_CPPCHECK "Run CppCheck static code analysis")
option(ENABLE_DOXYGEN "Run Doxygen documentation generator")
option(ENABLE_ASCIIDOCTOR "Run AsciiDoctor documentation generator")

set(CMAKE_COLOR_DIAGNOSTICS ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS ON)
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
)

if(ENABLE_CPPCHECK)
    message(STATUS "Configuring CppCheck...")

    find_program(CMAKE_CPPCHECK_EXECUTABLE NAMES cppcheck REQUIRED)

    set(CMAKE_CPPCHECK_FLAGS
        --platform=native
        --enable=all
        --inconclusive
        --inline-suppr
        --suppressions-list=${PROJECT_SOURCE_DIR}/cppcheck.supp
        --verbose
    )

    set(CMAKE_C_CPPCHECK ${CMAKE_CPPCHECK_EXECUTABLE} --std=c23 ${CMAKE_CPPCHECK_FLAGS})
    set(CMAKE_CXX_CPPCHECK ${CMAKE_CPPCHECK_EXECUTABLE} --std=c++23 ${CMAKE_CPPCHECK_FLAGS})
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
        src/entry.cc
        src/table.cc
        src/version.cc
        src/table/system.cc
        src/table/chassis.cc
        src/table/cache.cc
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

add_executable(dmidump)
target_sources(dmidump
    PRIVATE
        src/dump.cc
)
