//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef DMI_TABLE_H
#define DMI_TABLE_H

#pragma once

#include <vector>
#include <string>

#include <dmi/types.h>

typedef enum dmi_table_type : uint8_t
{
    DMI_TABLE_BIOS                       = 0,
    DMI_TABLE_SYSTEM                     = 1,
    DMI_TABLE_BASEBOARD                  = 2,
    DMI_TABLE_CHASSIS                    = 3,
    DMI_TABLE_PROCESSOR                  = 4,
    DMI_TABLE_MEMORY_CONTROLLER          = 5,
    DMI_TABLE_MEMORY_MODULE              = 6,
    DMI_TABLE_CACHE                      = 7,
    DMI_TABLE_PORT_CONNECTOR             = 8,
    DMI_TABLE_SYSTEM_SLOTS               = 9,
    DMI_TABLE_ONBOARD_DEVICE             = 10,
    DMI_TABLE_OEM_STRINGS                = 11,
    DMI_TABLE_SYSTEM_CONFIG              = 12,
    DMI_TABLE_BIOS_LANGUAGE              = 13,
    DMI_TABLE_GROUP_ASSOC                = 14,
    DMI_TABLE_SYSTEM_EVENT_LOG           = 15,
    DMI_TABLE_MEMORY_PHYS_ARRAY          = 16,
    DMI_TABLE_MEMORY_DEVICE              = 17,
    DMI_TABLE_MEMORY_ERROR_32BIT         = 18,
    DMI_TABLE_MEMORY_ARRAY_MAPPED_ADDR   = 19,
    DMI_TABLE_MEMORY_DEVICE_MAPPED_ADDR  = 20,
    DMI_TABLE_POINTING_DEVICE            = 21,
    DMI_TABLE_PORTABLE_BATTERY           = 22,
    DMI_TABLE_SYSTEM_RESET               = 23,
    DMI_TABLE_HARDWARE_SECURITY          = 24,
    DMI_TABLE_SYSTEM_POWER_CONTROLS      = 25,
    DMI_TABLE_VOLTAGE_PROBE              = 26,
    DMI_TABLE_COOLING_DEVICE             = 27,
    DMI_TABLE_TEMPERATURE_PROBE          = 28,
    DMI_TABLE_CURRENT_PROBE              = 29,
    DMI_TABLE_OOB_REMOTE_ACCESS          = 30,
    DMI_TABLE_BOOT_INTEGRITY             = 31,
    DMI_TABLE_SYSTEM_BOOT                = 32,
    DMI_TABLE_MEMORY_ERROR_64BIT         = 33,
    DMI_TABLE_MGMT_DEVICE                = 34,
    DMI_TABLE_MGMT_DEVICE_COMPONENT      = 35,
    DMI_TABLE_MGMT_DEVICE_THRESHOLD      = 36,
    DMI_TABLE_MEMORY_CHANNEL             = 37,
    DMI_TABLE_IPMI_DEVICE                = 38,
    DMI_TABLE_POWER_SUPPLY               = 39,
    DMI_TABLE_ADDITIONAL_INFO            = 40,
    DMI_TABLE_ONBOARD_DEVICE_EX          = 41,
    DMI_TABLE_MGMT_CONTROLLER_HOST_IF    = 42,
    DMI_TABLE_TPM_DEVICE                 = 43,
    DMI_TABLE_PROCESSOR_EX               = 44,
    DMI_TABLE_FIRMWARE                   = 45,
    DMI_TABLE_STRING_PROPERTY            = 46,
    DMI_TABLE_INACTIVE                   = 126,
    DMI_TABLE_END_OF_TABLE               = 127
} dmi_table_type_t;

__BEGIN_DECLS

const char *dmi_table_type_str(dmi_table_type_t value);

__END_DECLS

#ifdef __cplusplus

namespace dmi
{
    enum class table_type : uint8_t
    {
        bios                      = DMI_TABLE_BIOS,
        system                    = DMI_TABLE_SYSTEM,
        baseboard                 = DMI_TABLE_BASEBOARD,
        chassis                   = DMI_TABLE_CHASSIS,
        processor                 = DMI_TABLE_PROCESSOR,
        memory_controller         = DMI_TABLE_MEMORY_CONTROLLER,
        memory_module             = DMI_TABLE_MEMORY_MODULE,
        cache                     = DMI_TABLE_CACHE,
        port_connector            = DMI_TABLE_PORT_CONNECTOR,
        system_slots              = DMI_TABLE_SYSTEM_SLOTS,
        onboard_device            = DMI_TABLE_ONBOARD_DEVICE,
        oem_strings               = DMI_TABLE_OEM_STRINGS,
        system_config             = DMI_TABLE_SYSTEM_CONFIG,
        bios_language             = DMI_TABLE_BIOS_LANGUAGE,
        group_assoc               = DMI_TABLE_GROUP_ASSOC,
        system_event_log          = DMI_TABLE_SYSTEM_EVENT_LOG,
        memory_phys_array         = DMI_TABLE_MEMORY_PHYS_ARRAY,
        memory_device             = DMI_TABLE_MEMORY_DEVICE,
        memory_error_32bit        = DMI_TABLE_MEMORY_ERROR_32BIT,
        memory_array_mapped_addr  = DMI_TABLE_MEMORY_ARRAY_MAPPED_ADDR,
        memory_device_mapped_addr = DMI_TABLE_MEMORY_DEVICE_MAPPED_ADDR,
        pointing_device           = DMI_TABLE_POINTING_DEVICE,
        portable_battery          = DMI_TABLE_PORTABLE_BATTERY,
        system_reset              = DMI_TABLE_SYSTEM_RESET,
        hardware_security         = DMI_TABLE_HARDWARE_SECURITY,
        system_power_controls     = DMI_TABLE_SYSTEM_POWER_CONTROLS,
        voltage_probe             = DMI_TABLE_VOLTAGE_PROBE,
        cooling_device            = DMI_TABLE_COOLING_DEVICE,
        temperature_probe         = DMI_TABLE_TEMPERATURE_PROBE,
        current_probe             = DMI_TABLE_CURRENT_PROBE,
        oob_remote_access         = DMI_TABLE_OOB_REMOTE_ACCESS,
        boot_integrity            = DMI_TABLE_BOOT_INTEGRITY,
        system_boot               = DMI_TABLE_SYSTEM_BOOT,
        memory_error_64bit        = DMI_TABLE_MEMORY_ERROR_64BIT,
        mgmt_device               = DMI_TABLE_MGMT_DEVICE,
        mgmt_device_component     = DMI_TABLE_MGMT_DEVICE_COMPONENT,
        mgmt_device_threshold     = DMI_TABLE_MGMT_DEVICE_THRESHOLD,
        memory_channel            = DMI_TABLE_MEMORY_CHANNEL,
        ipmi_device               = DMI_TABLE_IPMI_DEVICE,
        power_supply              = DMI_TABLE_POWER_SUPPLY,
        additional_info           = DMI_TABLE_ADDITIONAL_INFO,
        onboard_device_ex         = DMI_TABLE_ONBOARD_DEVICE_EX,
        mgmt_controller_host_if   = DMI_TABLE_MGMT_CONTROLLER_HOST_IF,
        tpm_device                = DMI_TABLE_TPM_DEVICE,
        processor_ex              = DMI_TABLE_PROCESSOR_EX,
        firmware                  = DMI_TABLE_FIRMWARE,
        string_property           = DMI_TABLE_STRING_PROPERTY,
        inactive                  = DMI_TABLE_INACTIVE,
        end_of_table              = DMI_TABLE_END_OF_TABLE
    };

    const std::string_view to_string(table_type value);

    class basic_table
    {
    protected:
        handle_t m_handle;

    public:
        basic_table();
        virtual ~basic_table();

        inline handle_t handle() const { return m_handle; }
    };
}

#endif // __cplusplus

#endif // !DMI_TABLE_H
