//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#include <dmi/table/system.h>

#include <vector>

static const char *dmi_system_wakeup_names[] =
{
    [DMI_SYSTEM_WAKEUP_RESERVED]     = "Reserved",
    [DMI_SYSTEM_WAKEUP_OTHER]        = "Other",
    [DMI_SYSTEM_WAKEUP_UNKNOWN]      = "Unknown",
    [DMI_SYSTEM_WAKEUP_APM_TIMER]    = "APM Timer",
    [DMI_SYSTEM_WAKEUP_MODEM_RING]   = "Modem Ring",
    [DMI_SYSTEM_WAKEUP_LAN_REMOTE]   = "LAN Remote",
    [DMI_SYSTEM_WAKEUP_POWER_SWITCH] = "Power Switch",
    [DMI_SYSTEM_WAKEUP_PCI_PME]      = "PCI PME#",
    [DMI_SYSTEM_WAKEUP_AC_POWER]     = "AC Power Restored"
};

const char *dmi_system_wakeup_str(dmi_system_wakeup_t value)
{
    if (value >= std::size(dmi_system_wakeup_names))
        return nullptr;

    return dmi_system_wakeup_names[value];
}
