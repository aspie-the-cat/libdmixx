//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#include <dmi/table/system.h>

#include <stdexcept>
#include <vector>

using namespace dmi::table;

static const char *dmi_system_wakeup_names[] =
{
    [DMI_SYSTEM_WAKEUP_RESERVED]     = "Reserved",
    [DMI_SYSTEM_WAKEUP_OTHER]        = "Other",
    [DMI_SYSTEM_WAKEUP_UNKNOWN]      = "Unknown",
    [DMI_SYSTEM_WAKEUP_APM_TIMER]    = "APM timer",
    [DMI_SYSTEM_WAKEUP_MODEM_RING]   = "Modem ring",
    [DMI_SYSTEM_WAKEUP_LAN_REMOTE]   = "LAN remote",
    [DMI_SYSTEM_WAKEUP_POWER_SWITCH] = "Power switch",
    [DMI_SYSTEM_WAKEUP_PCI_PME]      = "PCI PME#",
    [DMI_SYSTEM_WAKEUP_AC_POWER]     = "AC power restored"
};

const char *dmi_system_wakeup_str(dmi_system_wakeup_t value)
{
    if (value >= std::size(dmi_system_wakeup_names))
        return nullptr;

    return dmi_system_wakeup_names[value];
}

const std::string_view to_string(system_wakeup value)
{
    const char *name = dmi_system_wakeup_str(::dmi_system_wakeup(value));
    if (name == nullptr)
        throw std::invalid_argument("value");

    return name;
}
