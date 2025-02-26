#include <dmi/table/chassis.h>

#include <stdexcept>
#include <vector>

using namespace dmi::table;

static const char *dmi_chassis_type_names[] =
{
    [DMI_CHASSIS_TYPE_UNSPECIFIED]           = "Unspecified",
    [DMI_CHASSIS_TYPE_OTHER]                 = "Other",
    [DMI_CHASSIS_TYPE_UNKNOWN]               = "Unknown",
    [DMI_CHASSIS_TYPE_DESKTOP]               = "Desktop",
    [DMI_CHASSIS_TYPE_LOW_PROFILE_DESKTOP]   = "Low-profile desktop",
    [DMI_CHASSIS_TYPE_PIZZA_BOX]             = "Pizza box",
    [DMI_CHASSIS_TYPE_MINI_TOWER]            = "Mini tower",
    [DMI_CHASSIS_TYPE_TOWER]                 = "Tower",
    [DMI_CHASSIS_TYPE_PORTABLE]              = "Portable",
    [DMI_CHASSIS_TYPE_LAPTOP]                = "Laptop",
    [DMI_CHASSIS_TYPE_NOTEBOOK]              = "Notebook",
    [DMI_CHASSIS_TYPE_HANDHELD]              = "Handheld",
    [DMI_CHASSIS_TYPE_DOCKING_STATION]       = "Docking station",
    [DMI_CHASSIS_TYPE_ALL_IN_ONE]            = "All-in-one",
    [DMI_CHASSIS_TYPE_SUB_NOTEBOOK]          = "Sub-notebook",
    [DMI_CHASSIS_TYPE_SPACE_SAVING]          = "Space-saving",
    [DMI_CHASSIS_TYPE_LUNCH_BOX]             = "Lunch box",
    [DMI_CHASSIS_TYPE_MAIN_SERVER_CHASSIS]   = "Main server chassis",
    [DMI_CHASSIS_TYPE_EXPANSION_CHASSIS]     = "Expansion chassis",
    [DMI_CHASSIS_TYPE_SUB_CHASSIS]           = "Sub-chassis",
    [DMI_CHASSIS_TYPE_BUS_EXPANSION_CHASSIS] = "Bus expansion chassis",
    [DMI_CHASSIS_TYPE_PERIPHERAL_CHASSIS]    = "Peripheral chassis",
    [DMI_CHASSIS_TYPE_RAID_CHASSIS]          = "RAID chassis",
    [DMI_CHASSIS_TYPE_RACK_MOUNT_CHASSIS]    = "Rack-mount chassis",
    [DMI_CHASSIS_TYPE_SEALED_CASE_PC]        = "Sealed-case PC",
    [DMI_CHASSIS_TYPE_MULTI_SYSTEM_CHASSIS]  = "Multi-system chassis",
    [DMI_CHASSIS_TYPE_COMPACT_PCI]           = "Compact PCI",
    [DMI_CHASSIS_TYPE_ADVANCED_TCA]          = "Advanced TCA",
    [DMI_CHASSIS_TYPE_BLADE]                 = "Blade",
    [DMI_CHASSIS_TYPE_BLADE_ENCLOSURE]       = "Blade chassis",
    [DMI_CHASSIS_TYPE_TABLET]                = "Tablet",
    [DMI_CHASSIS_TYPE_CONVERTIBLE]           = "Convertible",
    [DMI_CHASSIS_TYPE_DETACHABLE]            = "Detachable",
    [DMI_CHASSIS_TYPE_IOT_GATEWAY]           = "IoT gateway",
    [DMI_CHASSIS_TYPE_EMBEDDED_PC]           = "Embedded PC",
    [DMI_CHASSIS_TYPE_MINI_PC]               = "Mini PC",
    [DMI_CHASSIS_TYPE_STICK_PC]              = "Stick PC",
};

static const char *dmi_chassis_state_names[] =
{
    [DMI_CHASSIS_STATE_UNSPECIFIED]     = "Unspecified",
    [DMI_CHASSIS_STATE_OTHER]           = "Other",
    [DMI_CHASSIS_STATE_UNKNOWN]         = "Unknown",
    [DMI_CHASSIS_STATE_SAFE]            = "Safe",
    [DMI_CHASSIS_STATE_WARNING]         = "Warning",
    [DMI_CHASSIS_STATE_CRITICAL]        = "Critical",
    [DMI_CHASSIS_STATE_NON_RECOVERABLE] = "Non-recoverable"
};

const char *dmi_chassis_type_str(dmi_chassis_type_t value)
{
    if (value >= std::size(dmi_chassis_type_names))
        return nullptr;

    return dmi_chassis_type_names[value];
}

const char *dmi_chassis_state_str(dmi_chassis_state_t value)
{
    if (value >= std::size(dmi_chassis_state_names))
        return nullptr;

    return dmi_chassis_state_names[value];
}

const std::string_view to_string(chassis_type value)
{
    const char *name = dmi_chassis_type_str(::dmi_chassis_type(value));
    if (name == nullptr)
        throw std::invalid_argument("value");

    return name;
}

const std::string_view to_string(chassis_state value)
{
    const char *name = dmi_chassis_state_str(::dmi_chassis_state(value));
    if (name == nullptr)
        throw std::invalid_argument("value");

    return name;
}
