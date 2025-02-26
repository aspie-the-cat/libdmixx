//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef DMI_TABLE_CHASSIS_H
#define DMI_TABLE_CHASSIS_H

#pragma once

#include <dmi/table.h>

/**
 * @brief System enclosure or chassis types.
 */
typedef enum dmi_chassis_type : uint8_t
{
    DMI_CHASSIS_TYPE_UNSPECIFIED           = 0x00, //< Unspecified
    DMI_CHASSIS_TYPE_OTHER                 = 0x01, //< Other
    DMI_CHASSIS_TYPE_UNKNOWN               = 0x02, //< Unknown
    DMI_CHASSIS_TYPE_DESKTOP               = 0x03, //< Desktop
    DMI_CHASSIS_TYPE_LOW_PROFILE_DESKTOP   = 0x04, //< Low-profile desktop
    DMI_CHASSIS_TYPE_PIZZA_BOX             = 0x05, //< Pizza box
    DMI_CHASSIS_TYPE_MINI_TOWER            = 0x06, //< Mini tower
    DMI_CHASSIS_TYPE_TOWER                 = 0x07, //< Tower
    DMI_CHASSIS_TYPE_PORTABLE              = 0x08, //< Portable
    DMI_CHASSIS_TYPE_LAPTOP                = 0x09, //< Laptop
    DMI_CHASSIS_TYPE_NOTEBOOK              = 0x0A, //< Notebook
    DMI_CHASSIS_TYPE_HANDHELD              = 0x0B, //< Handheld
    DMI_CHASSIS_TYPE_DOCKING_STATION       = 0x0C, //< Docking station
    DMI_CHASSIS_TYPE_ALL_IN_ONE            = 0x0D, //< All-in-one
    DMI_CHASSIS_TYPE_SUB_NOTEBOOK          = 0x0E, //< Sub-notebook
    DMI_CHASSIS_TYPE_SPACE_SAVING          = 0x0F, //< Space-saving
    DMI_CHASSIS_TYPE_LUNCH_BOX             = 0x10, //< Lunch box
    DMI_CHASSIS_TYPE_MAIN_SERVER_CHASSIS   = 0x11, //< Main server chassis
    DMI_CHASSIS_TYPE_EXPANSION_CHASSIS     = 0x12, //< Expansion chassis
    DMI_CHASSIS_TYPE_SUB_CHASSIS           = 0x13, //< Sub-chassis
    DMI_CHASSIS_TYPE_BUS_EXPANSION_CHASSIS = 0x14, //< Bus expansion chassis
    DMI_CHASSIS_TYPE_PERIPHERAL_CHASSIS    = 0x15, //< Peripheral chassis
    DMI_CHASSIS_TYPE_RAID_CHASSIS          = 0x16, //< RAID chassis
    DMI_CHASSIS_TYPE_RACK_MOUNT_CHASSIS    = 0x17, //< Rack-mount chassis
    DMI_CHASSIS_TYPE_SEALED_CASE_PC        = 0x18, //< Sealed-case PC
    DMI_CHASSIS_TYPE_MULTI_SYSTEM_CHASSIS  = 0x19, //< Multi-system chassis
    DMI_CHASSIS_TYPE_COMPACT_PCI           = 0x1A, //< Compact PCI
    DMI_CHASSIS_TYPE_ADVANCED_TCA          = 0x1B, //< Advanced TCA
    DMI_CHASSIS_TYPE_BLADE                 = 0x1C, //< Blade
    DMI_CHASSIS_TYPE_BLADE_ENCLOSURE       = 0x1D, //< Blade chassis
    DMI_CHASSIS_TYPE_TABLET                = 0x1E, //< Tablet
    DMI_CHASSIS_TYPE_CONVERTIBLE           = 0x1F, //< Convertible
    DMI_CHASSIS_TYPE_DETACHABLE            = 0x20, //< Detachable
    DMI_CHASSIS_TYPE_IOT_GATEWAY           = 0x21, //< IoT gateway
    DMI_CHASSIS_TYPE_EMBEDDED_PC           = 0x22, //< Embedded PC
    DMI_CHASSIS_TYPE_MINI_PC               = 0x23, //< Mini PC
    DMI_CHASSIS_TYPE_STICK_PC              = 0x24  //< Stick PC
} dmi_chassis_type_t;

/**
 * @brief System enclosure or chassis states.
 */
typedef enum dmi_chassis_state : uint8_t
{
    DMI_CHASSIS_STATE_UNSPECIFIED     = 0x00, //< Unspecified
    DMI_CHASSIS_STATE_OTHER           = 0x01, //< Other
    DMI_CHASSIS_STATE_UNKNOWN         = 0x02, //< Unknown
    DMI_CHASSIS_STATE_SAFE            = 0x03, //< Safe
    DMI_CHASSIS_STATE_WARNING         = 0x04, //< Warning
    DMI_CHASSIS_STATE_CRITICAL        = 0x05, //< Critical
    DMI_CHASSIS_STATE_NON_RECOVERABLE = 0x06  //< Non-recoverable
} dmi_chassis_state_t;

__BEGIN_DECLS

const char *dmi_chassis_type_str(dmi_chassis_type_t value);
const char *dmi_chassis_state_str(dmi_chassis_state_t value);

__END_DECLS

#ifdef __cplusplus

namespace dmi::table
{
    enum class chassis_type : uint8_t
    {
        unspecified           = DMI_CHASSIS_TYPE_UNSPECIFIED,
        other                 = DMI_CHASSIS_TYPE_OTHER,
        unknown               = DMI_CHASSIS_TYPE_UNKNOWN,
        desktop               = DMI_CHASSIS_TYPE_DESKTOP,
        low_profile_desktop   = DMI_CHASSIS_TYPE_LOW_PROFILE_DESKTOP,
        pizza_box             = DMI_CHASSIS_TYPE_PIZZA_BOX,
        mini_tower            = DMI_CHASSIS_TYPE_MINI_TOWER,
        tower                 = DMI_CHASSIS_TYPE_TOWER,
        portable              = DMI_CHASSIS_TYPE_PORTABLE,
        laptop                = DMI_CHASSIS_TYPE_LAPTOP,
        notebook              = DMI_CHASSIS_TYPE_NOTEBOOK,
        handheld              = DMI_CHASSIS_TYPE_HANDHELD,
        docking_station       = DMI_CHASSIS_TYPE_DOCKING_STATION,
        all_in_one            = DMI_CHASSIS_TYPE_ALL_IN_ONE,
        sub_notebook          = DMI_CHASSIS_TYPE_SUB_NOTEBOOK,
        space_saving          = DMI_CHASSIS_TYPE_SPACE_SAVING,
        lunch_box             = DMI_CHASSIS_TYPE_LUNCH_BOX,
        main_server_chassis   = DMI_CHASSIS_TYPE_MAIN_SERVER_CHASSIS,
        expansion_chassis     = DMI_CHASSIS_TYPE_EXPANSION_CHASSIS,
        sub_chassis           = DMI_CHASSIS_TYPE_SUB_CHASSIS,
        bus_expansion_chassis = DMI_CHASSIS_TYPE_BUS_EXPANSION_CHASSIS,
        peripheral_chassis    = DMI_CHASSIS_TYPE_PERIPHERAL_CHASSIS,
        raid_chassis          = DMI_CHASSIS_TYPE_RAID_CHASSIS,
        rack_mount_chassis    = DMI_CHASSIS_TYPE_RACK_MOUNT_CHASSIS,
        sealed_case_pc        = DMI_CHASSIS_TYPE_SEALED_CASE_PC,
        multi_system_chassis  = DMI_CHASSIS_TYPE_MULTI_SYSTEM_CHASSIS,
        compact_pci           = DMI_CHASSIS_TYPE_COMPACT_PCI,
        advanced_tca          = DMI_CHASSIS_TYPE_ADVANCED_TCA,
        blade                 = DMI_CHASSIS_TYPE_BLADE,
        blade_enclosure       = DMI_CHASSIS_TYPE_BLADE_ENCLOSURE,
        tablet                = DMI_CHASSIS_TYPE_TABLET,
        convertible           = DMI_CHASSIS_TYPE_CONVERTIBLE,
        detachable            = DMI_CHASSIS_TYPE_DETACHABLE,
        iot_gateway           = DMI_CHASSIS_TYPE_IOT_GATEWAY,
        embedded_pc           = DMI_CHASSIS_TYPE_EMBEDDED_PC,
        mini_pc               = DMI_CHASSIS_TYPE_MINI_PC,
        stick_pc              = DMI_CHASSIS_TYPE_STICK_PC
    };

    enum class chassis_state : uint8_t
    {
        unspecified     = DMI_CHASSIS_STATE_UNSPECIFIED,    //< Unspecified
        other           = DMI_CHASSIS_STATE_OTHER,          //< Other
        unknown         = DMI_CHASSIS_STATE_UNKNOWN,        //< Unknown
        safe            = DMI_CHASSIS_STATE_SAFE,           //< Safe
        warning         = DMI_CHASSIS_STATE_WARNING,        //< Warning
        critical        = DMI_CHASSIS_STATE_CRITICAL,       //< Critical
        non_recoverable = DMI_CHASSIS_STATE_NON_RECOVERABLE //< Non-recoverable
    };

    /**
     * @throws std::invalid_argument
     */
    const std::string_view to_string(chassis_type value);

    /**
     * @throws std::invalid_argument
     */
    const std::string_view to_string(chassis_state value);
};

#endif // __cplusplus

#endif // !DMI_TABLE_CHASSIS_H
