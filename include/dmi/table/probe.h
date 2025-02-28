//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef DMI_TABLE_PROBE_H
#define DMI_TABLE_PROBE_H

#pragma once

#include <dmi/table.h>

/**
 * @brief Probe locations.
 */
typedef enum dmi_probe_location : uint8_t
{
    DMI_PROBE_LOCATION_UNSPECIFIED        = 0x00, //< Unspecified
    DMI_PROBE_LOCATION_OTHER              = 0x01, //< Other
    DMI_PROBE_LOCATION_UNKNOWN            = 0x02, //< Unknown
    DMI_PROBE_LOCATION_PROCESSOR          = 0x03, //< Processor
    DMI_PROBE_LOCATION_DISK               = 0x04, //< Disk
    DMI_PROBE_LOCATION_PERIPHERAL_BAY     = 0x05, //< Peripheral bay
    DMI_PROBE_LOCATION_SYSTEM_MGMT_MODULE = 0x06, //< System management module
    DMI_PROBE_LOCATION_MOTHERBOARD        = 0x07, //< Motherboard
    DMI_PROBE_LOCATION_MEMORY_MODULE      = 0x08, //< Memory module
    DMI_PROBE_LOCATION_PROCESSOR_MODULE   = 0x09, //< Processor module
    DMI_PROBE_LOCATION_POWER_UNIT         = 0x0A, //< Power unit
    DMI_PROBE_LOCATION_ADDIN_CARD         = 0x0B, //< Add-in card
    DMI_PROBE_LOCATION_FRONT_PANEL_BOARD  = 0x0C, //< Front panel board
    DMI_PROBE_LOCATION_BACK_PANEL_BOARD   = 0x0D, //< Back panel location
    DMI_PROBE_LOCATION_POWER_SYSTEM_BOARD = 0x0E, //< Power system board
    DMI_PROBE_LOCATION_DRIVE_BACK_PLANE   = 0x0F  //< Drive back plane
} dmi_probe_location_t;

/**
 * @brief Probe statuses.
 */
typedef enum dmi_probe_status : uint8_t
{
    DMI_PROBE_STATUS_UNSPECIFIED     = 0x00, //< Unspecified
    DMI_PROBE_STATUS_OTHER           = 0x01, //< Other
    DMI_PROBE_STATUS_UNKNOWN         = 0x02, //< Unknown
    DMI_PROBE_STATUS_OK              = 0x03, //< OK
    DMI_PROBE_STATUS_NON_CRITICAL    = 0x04, //< Non-critical
    DMI_PROBE_STATUS_CRITICAL        = 0x05, //< Critical
    DMI_PROBE_STATUS_NON_RECOVERABLE = 0x06  //< Non-recoverable
} dmi_probe_status_t;

__BEGIN_DECLS

const char *dmi_probe_location_str(dmi_probe_location_t value);
const char *dmi_probe_status_str(dmi_probe_status_t value);

__END_DECLS

#endif // !DMI_TABLE_PROBE_H
