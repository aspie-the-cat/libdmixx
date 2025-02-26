//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef DMI_TABLE_SYSTEM_SLOTS_H
#define DMI_TABLE_SYSTEM_SLOTS_H

#pragma once

#include <dmi/table.h>

/**
 * @brief Slot heights.
 */
enum dmi_system_slot_height : uint8_t
{
    DMI_SLOT_HEIGHT_NOT_APPLICABLE = 0x00, //< Not applicable
    DMI_SLOT_HEIGHT_OTHER          = 0x01, //< Other
    DMI_SLOT_HEIGHT_UNKNOWN        = 0x02, //< Unknown
    DMI_SLOT_HEIGHT_FULL           = 0x03, //< Full height
    DMI_SLOT_HEIGHT_LOW_PROFILE    = 0x04  //< Low-profile
};

typedef enum dmi_system_slot_height dmi_system_slot_height_t;

#endif // !DMI_TABLE_SYSTEM_SLOTS_H
