//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef DMI_VERSION_H
#define DMI_VERSION_H

#pragma once

#include <stdint.h>

/**
 * @brief DMI version descriptor.
 */
typedef struct dmi_version_id dmi_version_id_t;

/**
 * @brief DMI version descriptor structure.
 */
struct dmi_version_id
{
    /**
     * @brief SMBIOS major version.
     *
     * @details
     * Major version of SMBIOS specification implemented in the table structures
     * (for example, the value is `0x0A` for revision 10.22 and `0x02` for
     * revision 2.1).
     */
    unsigned major;

    /**
     * @brief SMBIOS minor version.
     *
     * @details
     * Minor version of SMBIOS specification implemented in the table structures
     * (for example, the value is `0x16` for revision 10.22 and `0x01` for
     * revision 2.1).
     */
    unsigned minor;

    /**
     * @brief SMBIOS version revision.
     *
     * @details
     * Identifies the docrev of SMBIOS specification implemented in the table
     * structures (for example, the value is `0x00` for revision 10.22.0 and
     * `0x01` for revision 2.7.1).
     */
    unsigned revision;
};

#ifdef __cplusplus

namespace dmi
{
    using version_id = ::dmi_version_id_t;
}

#endif // __cplusplus

#endif // !DMI_VERSION_H
