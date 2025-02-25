//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef LIBDMIXX_TYPES_H
#define LIBDMIXX_TYPES_H

#pragma once

#include <stdint.h>

/**
 * @brief DMI table handle.
 */
typedef uint16_t dmi_handle_t;

/**
 * @brief DMI table header.
 */
typedef struct dmi_header dmi_header_t;

/**
 * @brief DMI table header structure.
 */
struct dmi_header
{
    /**
     * @brief Type of structure.
     *
     * Specifies the type of structure. Types 0 through 127 (7Fh) are
     * reserved for and defined by this specification. Types 128 through 256
     * (80h to FFh) are available forsystem- and OEM-specific information
     */
    uint8_t type;

    /**
     * @brief Length of structure.
     *
     * Specifies the length of the formatted area of the structure, starting
     * at the Type field. The length of the structure’s string-set is not
     * included.
     */
    uint8_t length;

    /**
     * @brief Structure handle.
     *
     * Specifies the structure’s handle, a unique 16-bit number in the range 0
     * to 0FFFEh (for version 2.0) or 0 to 0FEFFh (for version 2.1 and later).
     * The handle numbers are not required to be contiguous. For version 2.1
     * and later, handle values in the range 0FF00h to 0FFFFh are reserved for
     * use by SMBIOS specification.
     *
     * If the system configuration changes, a previously assigned handle might
     * no longer exist. However, after a handle has been assigned by the BIOS,
     * the BIOS cannot re-assign that handle number to another structure.
     *
     * Unless otherwise specified, when referring to another structure’s handle,
     * the value 0FFFFh is used to indicate that the referenced handle is not
     * applicable or does not exist.
     */
    dmi_handle_t handle;
} __attribute__((packed, aligned(1)));

#ifdef __cplusplus

namespace dmi
{
    /**
     * @brief DMI table handle.
     */
    using handle = ::dmi_handle_t;

    /**
     * @brief DMI table header.
     */
    using header = ::dmi_header_t;
};

#endif // __cplusplus

#endif // !LIBDMIXX_TYPES_H
