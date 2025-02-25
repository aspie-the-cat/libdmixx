//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#include <dmi/table.h>

#include <vector>

static const char *dmi_table_type_names[] =
{
    [DMI_TABLE_BIOS]                       = "BIOS Information",
    [DMI_TABLE_SYSTEM]                     = "System Information",
    [DMI_TABLE_BASEBOARD]                  = "Baseboard (or Module) Information",
    [DMI_TABLE_CHASSIS]                    = "System Enclosure or Chassis",
    [DMI_TABLE_PROCESSOR]                  = "Processor Information",
    [DMI_TABLE_MEMORY_CONTROLLER]          = "Memory Controller Information",
    [DMI_TABLE_MEMORY_MODULE]              = "Memory Module Information",
    [DMI_TABLE_CACHE]                      = "Cache Information",
    [DMI_TABLE_PORT_CONNECTOR]             = "Port Connector Information",
    [DMI_TABLE_SYSTEM_SLOTS]               = "System Slots",
    [DMI_TABLE_ONBOARD_DEVICE]             = "Onboard Devices Information",
    [DMI_TABLE_OEM_STRINGS]                = "OEM Strings",
    [DMI_TABLE_SYSTEM_CONFIG]              = "System Configuration Options",
    [DMI_TABLE_BIOS_LANGUAGE]              = "BIOS Language Information",
    [DMI_TABLE_GROUP_ASSOC]                = "Group Associations",
    [DMI_TABLE_SYSTEM_EVENT_LOG]           = "System Event Log",
    [DMI_TABLE_MEMORY_PHYS_ARRAY]          = "Physical Memory Array",
    [DMI_TABLE_MEMORY_DEVICE]              = "Memory Device",
    [DMI_TABLE_MEMORY_ERROR_32BIT]         = "32-bit Memory Error Information",
    [DMI_TABLE_MEMORY_ARRAY_MAPPED_ADDR]   = "Memory Array Mapped Address",
    [DMI_TABLE_MEMORY_DEVICE_MAPPED_ADDR]  = "Memory Device Mapped Address",
    [DMI_TABLE_POINTING_DEVICE]            = "Built-in Pointing Device",
    [DMI_TABLE_PORTABLE_BATTERY]           = "Portable Battery",
    [DMI_TABLE_SYSTEM_RESET]               = "System Reset",
    [DMI_TABLE_HARDWARE_SECURITY]          = "Hardware Security",
    [DMI_TABLE_SYSTEM_POWER_CONTROLS]      = "System Power Controls",
    [DMI_TABLE_VOLTAGE_PROBE]              = "Voltage Probe",
    [DMI_TABLE_COOLING_DEVICE]             = "Cooling Device",
    [DMI_TABLE_TEMPERATURE_PROBE]          = "Temperature Probe",
    [DMI_TABLE_CURRENT_PROBE]              = "Electrical Current Probe",
    [DMI_TABLE_OOB_REMOTE_ACCESS]          = "Out-of-Band Remote Access",
    [DMI_TABLE_BOOT_INTEGRITY]             = "Boot Integrity Services (BIS) Entry Point",
    [DMI_TABLE_SYSTEM_BOOT]                = "System Boot Information",
    [DMI_TABLE_MEMORY_ERROR_64BIT]         = "64-bit Memory Error Information",
    [DMI_TABLE_MGMT_DEVICE]                = "Management Device",
    [DMI_TABLE_MGMT_DEVICE_COMPONENT]      = "Management Device Component",
    [DMI_TABLE_MGMT_DEVICE_THRESHOLD]      = "Management Device Threshold Data",
    [DMI_TABLE_MEMORY_CHANNEL]             = "Memory Channel",
    [DMI_TABLE_IPMI_DEVICE]                = "IPMI Device Information",
    [DMI_TABLE_POWER_SUPPLY]               = "System Power Supply",
    [DMI_TABLE_ADDITIONAL_INFO]            = "Additional Information",
    [DMI_TABLE_ONBOARD_DEVICE_EX]          = "Onboard Devices Extended Information",
    [DMI_TABLE_MGMT_CONTROLLER_HOST_IF]    = "Management Controller Host Interface",
    [DMI_TABLE_TPM_DEVICE]                 = "TPM Device",
    [DMI_TABLE_PROCESSOR_EX]               = "Processor Additional Information",
    [DMI_TABLE_FIRMWARE]                   = "Firmware Inventory Information",
    [DMI_TABLE_STRING_PROPERTY]            = "String Property"
};

const char *dmi_table_type_str(dmi_table_type_t value)
{
    if (value >= std::size(dmi_table_type_names))
        return nullptr;

    return dmi_table_type_names[value];
}
