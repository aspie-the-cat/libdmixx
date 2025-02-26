//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef LIBDMIXX_TABLE_CACHE_H
#define LIBDMIXX_TABLE_CACHE_H

#pragma once

#include <dmi/table.h>

/**
 * @brief Logical cache types.
 *
 * @see ::dmi_cache_type_t
 */
enum dmi_cache_type : uint8_t
{
    DMI_CACHE_TYPE_UNSPECIFIED = 0x00, //< Unspecified
    DMI_CACHE_TYPE_OTHER       = 0x01, //< Other
    DMI_CACHE_TYPE_UNKNOWN     = 0x02, //< Unknown
    DMI_CACHE_TYPE_INSTRUCTION = 0x03, //< Instruction
    DMI_CACHE_TYPE_DATA        = 0x04, //< Data
    DMI_CACHE_TYPE_UNIFIED     = 0x05  //< Unified
};

/**
 * @see #dmi_cache_type
 */
typedef enum dmi_cache_type dmi_cache_type_t;

/**
 * @brief Cache size (16-bit).
 */
union dmi_cache_size
{
    /**
     * @brief Cache size word value.
     */
    uint16_t value;

    struct
    {
        /**
         * @brief Size in given granularity.
         */
        unsigned size : 15;

        /**
         * @brief Granularity.
         *
         * @details
         * - `0` -- 1K granularity.
         * - `1` -- 64K granularity.
         */
        unsigned granularity : 1;
    } __attribute((packed, aligned(1)));
} __attribute__((packed, aligned(1)));

static_assert(sizeof(dmi_cache_size) == sizeof(dmi_cache_size::value));

/**
 * @see #dmi_cache_size
 */
typedef union dmi_cache_size dmi_cache_size_t;

/**
 * @brief Cache size (32-bit).
 */
union dmi_cache_size_ex
{
    /**
     * @brief Cache size word value.
     */
    uint32_t value;

    struct
    {
        /**
         * @brief Size in given granularity.
         */
        unsigned size : 31;

        /**
         * @brief Granularity.
         *
         * @details
         * - `0` -- 1K granularity.
         * - `1` -- 64K granularity.
         *
         * @note Always `1` for cache sizes > 2047 MiB.
         */
        unsigned granularity : 1;
    } __attribute((packed, aligned(1)));
} __attribute__((packed, aligned(1)));

static_assert(sizeof(dmi_cache_size_ex) == sizeof(dmi_cache_size_ex::value));

/**
 * @see #dmi_cache_size_ex
 */
typedef union dmi_cache_size_ex dmi_cache_size_ex_t;

/**
 * @brief Cache associativity modes.
 *
 * @see ::dmi_cache_assoc_t
 */
enum dmi_cache_assoc : uint8_t
{
    DMI_CACHE_ASSOC_UNSPECIFIED = 0x00, //< Unspecified
    DMI_CACHE_ASSOC_OTHER       = 0x01, //< Other
    DMI_CACHE_ASSOC_UNKNOWN     = 0x02, //< Unknown
    DMI_CACHE_ASSOC_DIRECT      = 0x03, //< Direct Mapped
    DMI_CACHE_ASSOC_SET_2WAY    = 0x04, //< 2-way Set-Associative
    DMI_CACHE_ASSIC_SET_4WAY    = 0x05, //< 4-way Set-Associative
    DMI_CACHE_ASSOC_FULL        = 0x06, //< Fully Associative
    DMI_CACHE_ASSOC_SET_8WAY    = 0x07, //< 8-way Set-Associative
    DMI_CACHE_ASSOC_SET_16WAY   = 0x08, //< 16-way Set-Associative
    DMI_CACHE_ASSOC_SET_12WAY   = 0x09, //< 12-way Set-Associative
    DMI_CACHE_ASSOC_SET_24WAY   = 0x0A, //< 24-way Set-Associative
    DMI_CACHE_ASSOC_SET_32WAY   = 0x0B, //< 32-way Set-Associative
    DMI_CACHE_ASSOC_SET_48WAY   = 0x0C, //< 48-way Set-Associative
    DMI_CACHE_ASSOC_SET_64WAY   = 0x0D, //< 64-way Set-Associative
    DMI_CACHE_ASSOC_SET_20WAY   = 0x0E  //< 20-way Set-Associative
};

/**
 * @see #dmi_cache_assoc
 */
typedef enum dmi_cache_assoc dmi_cache_assoc_t;

/**
 * @brief Cache error-correction schemes.
 *
 * @see ::dmi_cache_ecc_t
 */
enum dmi_cache_ecc : uint8_t
{
    DMI_CACHE_ECC_UNSPECIFIED = 0x00, //< Unspecified
    DMI_CACHE_ECC_OTHER       = 0x01, //< Other
    DMI_CACHE_ECC_UNKNOWN     = 0x02, //< Unknown
    DMI_CACHE_ECC_NONE        = 0x03, //< None
    DMI_CACHE_ECC_PARITY      = 0x04, //< Parity
    DMI_CACHE_ECC_SINGLE_BIT  = 0x05, //< Single-bit ECC
    DMI_CACHE_ECC_MULTI_BIT   = 0x06  //< Multi-bit ECC
};

/**
 * @brief Cache SRAM type.
 *
 * @see ::dmi_cache_sram_t
 */
union dmi_cache_sram
{
    /**
     * @brief Cache type word value.
     */
    uint16_t value;

    struct
    {
        bool other          : 1; //< Other
        bool unknown        : 1; //< Unknown
        bool non_burst      : 1; //< Non-Burst
        bool burst          : 1; //< Burst
        bool pipeline_burst : 1; //< Pipeline Burst
        bool synchronous    : 1; //< Synchronous
        bool asynchronous   : 1; //< Asynchronous
        unsigned reserved   : 9; //< Reserved (must be zero)
    } __attribute((packed, aligned(1)));
} __attribute((packed, aligned(1)));

static_assert(sizeof(dmi_cache_sram) == sizeof(dmi_cache_sram::value));

/**
 * @see #dmi_cache_sram
 */
typedef union dmi_cache_sram dmi_cache_sram_t;

/**
 * @see #dmi_cache_ecc
 */
typedef enum dmi_cache_ecc dmi_cache_ecc_t;

/**
 * @brief Cache locations (relative to the CPU module).
 *
 * @see ::dmi_cache_location_t
 */
enum dmi_cache_location : uint8_t
{
    DMI_CACHE_LOCATION_INTERNAL = 0x00, //< Internal
    DMI_CACHE_LOCATION_EXTERNAL = 0x01, //< External
    DMI_CACHE_LOCATION_RESERVED = 0x02, //< Reserved
    DMI_CACHE_LOCATION_UNKNOWN  = 0x03  //< Unknown
};

/**
 * @see #dmi_cache_location
 */
typedef enum dmi_cache_location dmi_cache_location_t;

/**
 * @brief Cache operational modes.
 *
 * @see ::dmi_cache_mode_t
 */
enum dmi_cache_mode : uint8_t
{
    DMI_CACHE_MODE_WRITE_THROUGH = 0x00, //< Write-through
    DMI_CACHE_MODE_WRITE_BACK    = 0x01, //< Write-back
    DMI_CACHE_MODE_VARIABLE      = 0x02, //< Varies with memory address
    DMI_CACHE_MODE_UNKNOWN       = 0x03  //< Unknown
};

/**
 * @see #dmi_cache_mode
 */
typedef enum dmi_cache_mode dmi_cache_mode_t;

/**
 * @brief Cache configuration.
 *
 * @see ::dmi_cache_config_t
 */
union dmi_cache_config
{
    /**
     * @brief Cache configuration word value.
     */
    uint16_t value;

    struct
    {
        /**
         * @brief Level -- 1 through 8. For example, an L1 cache would use
         * value 000b and an L3 cache would use 010b.
         */
        unsigned level : 3;

        /**
         * @brief Socketed cache flag (e.g. cache on a stick).
         */
        bool socketed : 1;

        /**
         * @brief Reserved, must be zero.
         */
        unsigned reserved_1 : 1;

        /**
         * @brief Location, relative to the CPU module.
         */
        dmi_cache_location_t location : 2;

        /**
         * @brief Enable flag.
         */
        bool enabled : 1;

        /**
         * @brief Operational mode.
         */
        dmi_cache_mode_t mode : 2;

        /**
         * @brief Reserved, must be zero.
         */
        unsigned reserved_2 : 6;
    } __attribute__((packed, aligned(1)));
} __attribute__((packed, aligned(1)));

static_assert(sizeof(dmi_cache_config) == sizeof(dmi_cache_config::value));

/**
 * @see #dmi_cache_config
 */
typedef union dmi_cache_config dmi_cache_config_t;

/**
 * @brief Cache information table structure.
 *
 * @details
 * The information in this structure defines the attributes of CPU cache device
 * in the system. One structure is specified for each such device, whether the
 * device is internal to or external to the CPU module. Cache modules can be
 * associated with a processor structure in one or two ways depending on the
 * SMBIOS version
 *
 * @see ::dmi_cache_table_t
 */
struct dmi_cache_table
{
    /**
     * @brief DMI structure header.
     */
    dmi_header_t header;

    /**
     * @brief String number for reference designation (i.e. “CACHE1”, 0).
     *
     * @since SMBIOS 2.0
     */
    uint8_t socket_designation;

    /**
     * @brief Cache configuration.
     *
     * @since SMBIOS 2.0
     */
    dmi_cache_config_t config;

    /**
     * @brief Maximum cache size.
     *
     * @since SMBIOS 2.0
     */
    dmi_cache_size_t maximum_size;

    /**
     * @brief Installed cache size.
     *
     * @since SMBIOS 2.0
     */
    dmi_cache_size_t installed_size;

    /**
     * @brief Supported SRAM type.
     *
     * @since SMBIOS 2.0
     */
    dmi_cache_sram_t supported_sram;

    /**
     * @brief Installed SRAM type.
     *
     * @since SMBIOS 2.0
     */
    dmi_cache_sram_t installed_sram;

    /**
     * @brief Cache speed, in nanoseconds. The value is 0 if the speed is
     * unknown.
     *
     * @since SMBIOS 2.1
     */
    uint8_t speed;

    /**
     * @brief Error-correction scheme supported by this cache component.
     *
     * @since SMBIOS 2.1
     */
    dmi_cache_ecc_t ecc_type;

    /**
     * @brief Logical type of the cache.
     *
     * @since SMBIOS 2.1
     */
    dmi_cache_type_t type;

    /**
     * @brief Associativity of the cache.
     *
     * @since SMBIOS 2.1
     */
    dmi_cache_assoc_t associativity;

    /**
     * @brief Maximum Cache Size 2.
     *
     * @since SMBIOS 3.1
     */
    dmi_cache_size_ex_t maximum_size_2;

    /**
     * @brief Installed Cache Size 2.
     *
     * @since SMBIOS 3.1
     */
    dmi_cache_size_ex_t installed_size_2;
} __attribute__((packed, aligned(1)));

/**
 * @see #dmi_cache_table
 */
typedef struct dmi_cache_table dmi_cache_table_t;

#ifdef __cplusplus

namespace dmi::table
{
    using cache_size    = ::dmi_cache_size_t;
    using cache_size_ex = ::dmi_cache_size_ex_t;
    /**
     * @brief Logical cache types.
     *
     * @see #dmi_cache_type
     */
    enum class cache_type : uint8_t
    {
        unspecified = DMI_CACHE_TYPE_UNSPECIFIED, //< Unspecified
        other       = DMI_CACHE_TYPE_OTHER,       //< Other
        unknown     = DMI_CACHE_TYPE_UNKNOWN,     //< Unknown
        instruction = DMI_CACHE_TYPE_INSTRUCTION, //< Instruction
        data        = DMI_CACHE_TYPE_DATA,        //< Data
        unified     = DMI_CACHE_TYPE_UNIFIED      //< Unified
    };

    /**
     * @brief Cache associativity modes.
     *
     * @see #dmi_cache_assoc
     */
    enum class cache_assoc : uint8_t
    {
        unspecified = DMI_CACHE_ASSOC_UNSPECIFIED, //< Unspecified
        other       = DMI_CACHE_ASSOC_OTHER,       //< Other
        unknown     = DMI_CACHE_ASSOC_UNKNOWN,     //< Unknown
        direct      = DMI_CACHE_ASSOC_DIRECT,      //< Direct Mapped
        set_2way    = DMI_CACHE_ASSOC_SET_2WAY,    //< 2-way Set-Associative
        set_4way    = DMI_CACHE_ASSIC_SET_4WAY,    //< 4-way Set-Associative
        full        = DMI_CACHE_ASSOC_FULL,        //< Fully Associative
        set_8way    = DMI_CACHE_ASSOC_SET_8WAY,    //< 8-way Set-Associative
        set_16way   = DMI_CACHE_ASSOC_SET_16WAY,   //< 16-way Set-Associative
        set_12way   = DMI_CACHE_ASSOC_SET_12WAY,   //< 12-way Set-Associative
        set_24way   = DMI_CACHE_ASSOC_SET_24WAY,   //< 24-way Set-Associative
        set_32way   = DMI_CACHE_ASSOC_SET_32WAY,   //< 32-way Set-Associative
        set_48way   = DMI_CACHE_ASSOC_SET_48WAY,   //< 48-way Set-Associative
        set_64way   = DMI_CACHE_ASSOC_SET_64WAY,   //< 64-way Set-Associative
        set_20way   = DMI_CACHE_ASSOC_SET_20WAY    //< 20-way Set-Associative
    };

    /**
     * @brief Cache error-correction schemes.
     *
     * @see #dmi_cache_ecc
     */
    enum class cache_ecc : uint8_t
    {
        unspecified = DMI_CACHE_ECC_UNSPECIFIED, //< Unspecified
        other       = DMI_CACHE_ECC_OTHER,       //< Other
        unknown     = DMI_CACHE_ECC_UNKNOWN,     //< Unknown
        none        = DMI_CACHE_ECC_NONE,        //< None
        parity      = DMI_CACHE_ECC_PARITY,      //< Parity
        single_bit  = DMI_CACHE_ECC_SINGLE_BIT,  //< Single-bit ECC
        multi_bit   = DMI_CACHE_ECC_MULTI_BIT    //< Multi-bit ECC
    };
}

#endif // __cplusplus

#endif // !LIBDMIXX_TABLE_CACHE_H
