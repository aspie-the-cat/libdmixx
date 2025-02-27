//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#include <dmi/table/cooling-device.h>

static const char *dmi_cooling_device_type_names[] =
{
    [DMI_COOLING_DEVICE_TYPE_UNSPECIFIED]              = "Unspecified",
    [DMI_COOLING_DEVICE_TYPE_OTHER]                    = "Other",
    [DMI_COOLING_DEVICE_TYPE_UNKNOWN]                  = "Unknown",
    [DMI_COOLING_DEVICE_TYPE_FAN]                      = "Fan",
    [DMI_COOLING_DEVICE_TYPE_CENTRIFUGAL_BLOWER]       = "Centrifugal blower",
    [DMI_COOLING_DEVICE_TYPE_CHIP_FAN]                 = "Chip fan",
    [DMI_COOLING_DEVICE_TYPE_CABINET_FAN]              = "Cabinet fan",
    [DMI_COOLING_DEVICE_TYPE_POWER_SUPPLY_FAN]         = "Power supply fan",
    [DMI_COOLING_DEVICE_TYPE_HEAT_PIPE]                = "Heat pipe",
    [DMI_COOLING_DEVICE_TYPE_INTEGRATED_REFRIGERATION] = "Integrated refrigeration",
    [__DMI_COOLING_DEVICE_TYPE_UNUSED_1]               = nullptr,
    [__DMI_COOLING_DEVICE_TYPE_UNUSED_2]               = nullptr,
    [__DMI_COOLING_DEVICE_TYPE_UNUSED_3]               = nullptr,
    [__DMI_COOLING_DEVICE_TYPE_UNUSED_4]               = nullptr,
    [__DMI_COOLING_DEVICE_TYPE_UNUSED_5]               = nullptr,
    [__DMI_COOLING_DEVICE_TYPE_UNUSED_6]               = nullptr,
    [DMI_COOLING_DEVICE_TYPE_ACTIVE_COOLING]           = "Active cooling",
    [DMI_COOLING_DEVICE_TYPE_PASSIVE_COOLING]          = "Passive cooling"
};

static const char *dmi_cooling_device_status_names[] =
{
    [DMI_COOLING_DEVICE_STATUS_UNSPECIFIED]     = "Unspecified",
    [DMI_COOLING_DEVICE_STATUS_OTHER]           = "Other",
    [DMI_COOLING_DEVICE_STATUS_UNKNOWN]         = "Unknown",
    [DMI_COOLING_DEVICE_STATUS_OK]              = "OK",
    [DMI_COOLING_DEVICE_STATUS_NON_CRITICAL]    = "Non-critical",
    [DMI_COOLING_DEVICE_STATUS_CRITICAL]        = "Critical",
    [DMI_COOLING_DEVICE_STATUS_NON_RECOVERABLE] = "Non-recoverable"
};

const char *dmi_cooling_device_type_str(dmi_cooling_device_type_t value)
{
    if (value >= std::size(dmi_cooling_device_type_names))
        return nullptr;

    return dmi_cooling_device_type_names[value];
}

const char *dmi_cooling_device_status_str(dmi_cooling_device_status_t value)
{
    if (value >= std::size(dmi_cooling_device_status_names))
        return nullptr;

    return dmi_cooling_device_status_names[value];
}
