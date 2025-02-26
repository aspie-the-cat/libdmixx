//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#include <dmi/table.h>

#include <stdexcept>
#include <vector>

using namespace dmi;

static const char *dmi_table_type_names[] =
{
    [DMI_TABLE_BIOS]                       = "BIOS information",
    [DMI_TABLE_SYSTEM]                     = "System information",
    [DMI_TABLE_BASEBOARD]                  = "Baseboard or module information",
    [DMI_TABLE_CHASSIS]                    = "System enclosure or chassis",
    [DMI_TABLE_PROCESSOR]                  = "Processor information",
    [DMI_TABLE_MEMORY_CONTROLLER]          = "Memory controller information",
    [DMI_TABLE_MEMORY_MODULE]              = "Memory module information",
    [DMI_TABLE_CACHE]                      = "Cache information",
    [DMI_TABLE_PORT_CONNECTOR]             = "Port connector information",
    [DMI_TABLE_SYSTEM_SLOTS]               = "System slots",
    [DMI_TABLE_ONBOARD_DEVICE]             = "Onboard devices information",
    [DMI_TABLE_OEM_STRINGS]                = "OEM strings",
    [DMI_TABLE_SYSTEM_CONFIG]              = "System configuration options",
    [DMI_TABLE_BIOS_LANGUAGE]              = "BIOS language information",
    [DMI_TABLE_GROUP_ASSOC]                = "Group associations",
    [DMI_TABLE_SYSTEM_EVENT_LOG]           = "System event log",
    [DMI_TABLE_MEMORY_PHYS_ARRAY]          = "Physical memory array",
    [DMI_TABLE_MEMORY_DEVICE]              = "Memory device",
    [DMI_TABLE_MEMORY_ERROR_32BIT]         = "32-bit memory error information",
    [DMI_TABLE_MEMORY_ARRAY_MAPPED_ADDR]   = "Memory array mapped address",
    [DMI_TABLE_MEMORY_DEVICE_MAPPED_ADDR]  = "Memory device mapped address",
    [DMI_TABLE_POINTING_DEVICE]            = "Built-in pointing device",
    [DMI_TABLE_PORTABLE_BATTERY]           = "Portable battery",
    [DMI_TABLE_SYSTEM_RESET]               = "System reset",
    [DMI_TABLE_HARDWARE_SECURITY]          = "Hardware security",
    [DMI_TABLE_SYSTEM_POWER_CONTROLS]      = "System power controls",
    [DMI_TABLE_VOLTAGE_PROBE]              = "Voltage probe",
    [DMI_TABLE_COOLING_DEVICE]             = "Cooling device",
    [DMI_TABLE_TEMPERATURE_PROBE]          = "Temperature probe",
    [DMI_TABLE_CURRENT_PROBE]              = "Electrical current probe",
    [DMI_TABLE_OOB_REMOTE_ACCESS]          = "Out-of-band remote access",
    [DMI_TABLE_BOOT_INTEGRITY]             = "Boot Integrity Services (BIS) entry point",
    [DMI_TABLE_SYSTEM_BOOT]                = "System boot information",
    [DMI_TABLE_MEMORY_ERROR_64BIT]         = "64-bit memory error information",
    [DMI_TABLE_MGMT_DEVICE]                = "Management device",
    [DMI_TABLE_MGMT_DEVICE_COMPONENT]      = "Management device component",
    [DMI_TABLE_MGMT_DEVICE_THRESHOLD]      = "Management device threshold data",
    [DMI_TABLE_MEMORY_CHANNEL]             = "Memory channel",
    [DMI_TABLE_IPMI_DEVICE]                = "IPMI device information",
    [DMI_TABLE_POWER_SUPPLY]               = "System power supply",
    [DMI_TABLE_ADDITIONAL_INFO]            = "Additional information",
    [DMI_TABLE_ONBOARD_DEVICE_EX]          = "Onboard devices extended information",
    [DMI_TABLE_MGMT_CONTROLLER_HOST_IF]    = "Management controller host interface",
    [DMI_TABLE_TPM_DEVICE]                 = "TPM device",
    [DMI_TABLE_PROCESSOR_EX]               = "Processor additional information",
    [DMI_TABLE_FIRMWARE]                   = "Firmware inventory information",
    [DMI_TABLE_STRING_PROPERTY]            = "String property"
};

const char *dmi_table_type_str(dmi_table_type_t value)
{
    if (value >= std::size(dmi_table_type_names))
        return nullptr;

    return dmi_table_type_names[value];
}

const std::string_view to_string(table_type value)
{
    const char *name = dmi_table_type_str(::dmi_table_type(value));
    if (name == nullptr)
        throw std::invalid_argument("value");

    return name;
}
