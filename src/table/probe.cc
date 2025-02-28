//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#include <dmi/table/probe.h>

#include <vector>

const char *dmi_probe_location_names[] =
{
    [DMI_PROBE_LOCATION_UNSPECIFIED]        = "Unspecified",
    [DMI_PROBE_LOCATION_OTHER]              = "Other",
    [DMI_PROBE_LOCATION_UNKNOWN]            = "Unknown",
    [DMI_PROBE_LOCATION_PROCESSOR]          = "Processor",
    [DMI_PROBE_LOCATION_DISK]               = "Disk",
    [DMI_PROBE_LOCATION_PERIPHERAL_BAY]     = "Peripheral bay",
    [DMI_PROBE_LOCATION_SYSTEM_MGMT_MODULE] = "System management module",
    [DMI_PROBE_LOCATION_MOTHERBOARD]        = "Motherboard",
    [DMI_PROBE_LOCATION_MEMORY_MODULE]      = "Memory module",
    [DMI_PROBE_LOCATION_PROCESSOR_MODULE]   = "Processor module",
    [DMI_PROBE_LOCATION_POWER_UNIT]         = "Power unit",
    [DMI_PROBE_LOCATION_ADDIN_CARD]         = "Add-in card",
    [DMI_PROBE_LOCATION_FRONT_PANEL_BOARD]  = "Front panel board",
    [DMI_PROBE_LOCATION_BACK_PANEL_BOARD]   = "Back panel location",
    [DMI_PROBE_LOCATION_POWER_SYSTEM_BOARD] = "Power system board",
    [DMI_PROBE_LOCATION_DRIVE_BACK_PLANE]   = "Drive back plane"
};

const char *dmi_probe_status_names[] =
{
    [DMI_PROBE_STATUS_UNSPECIFIED]     = "Unspecified",
    [DMI_PROBE_STATUS_OTHER]           = "Other",
    [DMI_PROBE_STATUS_UNKNOWN]         = "Unknown",
    [DMI_PROBE_STATUS_OK]              = "OK",
    [DMI_PROBE_STATUS_NON_CRITICAL]    = "Non-critical",
    [DMI_PROBE_STATUS_CRITICAL]        = "Critical",
    [DMI_PROBE_STATUS_NON_RECOVERABLE] = "Non-recoverable"
};

const char *dmi_probe_location_str(dmi_probe_location_t value)
{
    if (value >= std::size(dmi_probe_location_names))
        return nullptr;

    return dmi_probe_location_names[value];
}

const char *dmi_probe_status_str(dmi_probe_status_t value)
{
    if (value >= std::size(dmi_probe_status_names))
        return nullptr;

    return dmi_probe_status_names[value];
}
