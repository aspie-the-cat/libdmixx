//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef DMI_TABLE_COOLING_DEVICE_H
#define DMI_TABLE_COOLING_DEVICE_H

#pragma once

#include <dmi/table.h>

/**
 * @brief Cooling device types.
 */
typedef enum dmi_cooling_device_type : uint8_t
{
    DMI_COOLING_DEVICE_TYPE_UNSPECIFIED              = 0x00, //< Unspecified
    DMI_COOLING_DEVICE_TYPE_OTHER                    = 0x01, //< Other
    DMI_COOLING_DEVICE_TYPE_UNKNOWN                  = 0x02, //< Unknown
    DMI_COOLING_DEVICE_TYPE_FAN                      = 0x03, //< Fan
    DMI_COOLING_DEVICE_TYPE_CENTRIFUGAL_BLOWER       = 0x04, //< Centrifugal blower
    DMI_COOLING_DEVICE_TYPE_CHIP_FAN                 = 0x05, //< Chip fan
    DMI_COOLING_DEVICE_TYPE_CABINET_FAN              = 0x06, //< Cabinet fan
    DMI_COOLING_DEVICE_TYPE_POWER_SUPPLY_FAN         = 0x07, //< Power supply fan
    DMI_COOLING_DEVICE_TYPE_HEAT_PIPE                = 0x08, //< Heat pipe
    DMI_COOLING_DEVICE_TYPE_INTEGRATED_REFRIGERATION = 0x09, //< Integrated refrigeration
    __DMI_COOLING_DEVICE_TYPE_UNUSED_1               = 0x0A,
    __DMI_COOLING_DEVICE_TYPE_UNUSED_2               = 0x0B,
    __DMI_COOLING_DEVICE_TYPE_UNUSED_3               = 0x0C,
    __DMI_COOLING_DEVICE_TYPE_UNUSED_4               = 0x0D,
    __DMI_COOLING_DEVICE_TYPE_UNUSED_5               = 0x0E,
    __DMI_COOLING_DEVICE_TYPE_UNUSED_6               = 0x0F,
    DMI_COOLING_DEVICE_TYPE_ACTIVE_COOLING           = 0x10, //< Active cooling
    DMI_COOLING_DEVICE_TYPE_PASSIVE_COOLING          = 0x11  //< Passive cooling
} dmi_cooling_device_type_t;

/**
 * @brief Cooling devices statuses.
 */
typedef enum dmi_cooling_device_status : uint8_t
{
    DMI_COOLING_DEVICE_STATUS_UNSPECIFIED     = 0x00, //< Unspecified
    DMI_COOLING_DEVICE_STATUS_OTHER           = 0x01, //< Other
    DMI_COOLING_DEVICE_STATUS_UNKNOWN         = 0x02, //< Unknown
    DMI_COOLING_DEVICE_STATUS_OK              = 0x03, //< OK
    DMI_COOLING_DEVICE_STATUS_NON_CRITICAL    = 0x04, //< Non-critical
    DMI_COOLING_DEVICE_STATUS_CRITICAL        = 0x05, //< Critical
    DMI_COOLING_DEVICE_STATUS_NON_RECOVERABLE = 0x06  //< Non-recoverable
} dmi_cooling_device_status_t;

/**
 * @brief Cooling device table structure.
 *
 * @details
 * This structure describes the attributes for a cooling device in the system.
 * Each structure describes a single cooling device.
 */
struct dmi_cooling_device_table
{
    /**
     * @brief DMI structure header.
     */
    dmi_header_t header;

    /**
     * @brief Cooling device type.
     *
     * @since SMBIOS 2.2
     */
    dmi_cooling_device_type_t type : 5;

    /**
     * @brief Cooling device status.
     *
     * @since SMBIOS 2.2
     */
    dmi_cooling_device_status_t status : 3;

    /**
     * @brief Cooling unit group.
     *
     * @details
     * Cooling unit group to which this cooling device is associated.
     * Having multiple cooling devices in the same cooling unit implies a
     * redundant configuration. The value is 0x00 if the cooling device is not
     * a member of a redundant cooling unit. Non-zero values imply redundancy
     * and that at least one other cooling device will be enumerated with the
     * same value.
     *
     * @since SMBIOS 2.2
     */
    uint8_t cooling_unit_group;

    /**
     * @brief OEM- or BIOS vendor-specific information.
     *
     * @since SMBIOS 2.2
     */
    uint32_t oem_specific;

    /**
     * @brief Nominal speed.
     *
     * @details
     * Nominal value for the cooling device’s rotational speed, in
     * revolutions-per-minute (rpm). If the value is unknown or the cooling
     * device is non-rotating, the field is set to 0x8000. This field is
     * present in the structure only if the structure’s length is larger than
     * 0x0C.
     *
     * @since SMBIOS 2.2
     */
    uint16_t nominal_speed;

    /**
     * @brief Description.
     *
     * @details
     * Number of the string that contains additional descriptive information
     * about the cooling device or its location. This field is present in the
     * structure only if the structure’s length is 0x0F or larger.
     *
     * @since SMBIOS 2.7
     */
    uint8_t description;
} __attribute__((packed));

__BEGIN_DECLS

const char *dmi_cooling_device_type_str(dmi_cooling_device_type_t value);
const char *dmi_cooling_device_status_str(dmi_cooling_device_status_t value);

__END_DECLS

#endif // !DMI_TABLE_COOLING_DEVICE_H
