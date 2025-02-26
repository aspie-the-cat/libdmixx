#
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
#
cmake_minimum_required(VERSION 3.30)

project(libdmi-ng
    VERSION 0.1.0
    DESCRIPTION "DMI/SMBIOS interface"
    HOMEPAGE_URL https://github.com/sdnvx/libdmi-ng
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
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR})

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

if(ENABLE_DOXYGEN)
    message(STATUS "Configuring Doxygen...")

    find_package(Doxygen REQUIRED)

    set(DOXYGEN_OUTPUT_DIRECTORY build/share/html)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_LATEX NO)

    doxygen_add_docs(doxygen ${PROJECT_SOURCE_DIR})
endif()

include(CTest)
include(CPack)

add_library(dmi-ng OBJECT)
set_target_properties(dmi-ng
    PROPERTIES
        POSITION_INDEPENDENT_CODE ON
)
target_include_directories(dmi-ng
    PUBLIC
        ${PROJECT_BINARY_DIR}/include
)
target_sources(dmi-ng
    PRIVATE
        src/context.cc
        src/entry.cc
        src/table.cc
        src/version.cc
        src/table/system.cc
        src/table/chassis.cc
        src/table/cache.cc
)

add_library(dmi-ng-static STATIC $<TARGET_OBJECTS:dmi-ng>)
set_target_properties(dmi-ng-static
    PROPERTIES
        OUTPUT_NAME dmi-ng
)

add_library(dmi-ng-shared SHARED $<TARGET_OBJECTS:dmi-ng>)
set_target_properties(dmi-ng-shared
    PROPERTIES
        OUTPUT_NAME dmi-ng
)

add_executable(dmi-dump)
target_sources(dmi-dump
    PRIVATE
        src/dump.cc
)
