//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef LIBDMIXX_TABLE_SYSTEM_H
#define LIBDMIXX_TABLE_SYSTEM_H

#pragma once

#include <dmi/table.h>

#include <string>
#include <optional>

enum dmi_system_wakeup : uint8_t
{
    DMI_SYSTEM_WAKEUP_RESERVED     = 0x00,
    DMI_SYSTEM_WAKEUP_OTHER        = 0x01,
    DMI_SYSTEM_WAKEUP_UNKNOWN      = 0x02,
    DMI_SYSTEM_WAKEUP_APM_TIMER    = 0x03,
    DMI_SYSTEM_WAKEUP_MODEM_RING   = 0x04,
    DMI_SYSTEM_WAKEUP_LAN_REMOTE   = 0x05,
    DMI_SYSTEM_WAKEUP_POWER_SWITCH = 0x06,
    DMI_SYSTEM_WAKEUP_PCI_PME      = 0x07,
    DMI_SYSTEM_WAKEUP_AC_POWER     = 0x08
};

typedef enum dmi_system_wakeup dmi_system_wakeup_t;

struct dmi_system_table
{
    /**
     * @brief DMI structure header.
     */
    dmi_header_t header;

    /**
     * @brief Manufacturer.
     *
     * @details
     * String number of the manufacturer name.
     *
     * @since SMBIOS 2.0
     */
    uint8_t manufacturer;

    /**
     * @brief Product name.
     *
     * @details
     * String number of the product name.
     *
     * @since SMBIOS 2.0
     */
    uint8_t product;

    /**
     * @brief Version.
     *
     * @details
     * String number of the version.
     *
     * @since SMBIOS 2.0
     */
    uint8_t version;

    /**
     * @brief Serial number.
     *
     * @details
     * String number of the serial number.
     *
     * @since SMBIOS 2.0
     */
    uint8_t serial_number;

    /**
     * @brief System UUID.
     *
     * @details
     * Although RFC4122 recommends network byte order for all fields, the PC
     * industry (including the ACPI, UEFI, and Microsoft specifications) has
     * consistently used little-endian byte encoding for the first three fields:
     * time_low, time_mid, time_hi_and_version. The same encoding, also known
     * as wire format, should also be used for the SMBIOS representation of the
     * UUID.
     *
     * The UUID {00112233-4455-6677-8899-AABBCCDDEEFF} would thus be
     * represented as:
     *
     * 33 22 11 00 55 44 77 66 88 99 AA BB CC DD EE FF.1003
     *
     * If the value is all 0xFF, the ID is not currently present in the system,
     * but it can be set. If the value is all 0x00, the ID is not present in
     * the system.
     *
     * @since SMBIOS 2.1
     */
    uint8_t uuid[16];

    /**
     * @brief Wake-up type.
     *
     * @details
     * Identifies the event that caused the system to power up.
     *
     * @since SMBIOS 2.1
     */
    dmi_system_wakeup_t wakeup_type;

    /**
     * @brief SKU number.
     *
     * @details
     * String number of the SKU number.
     *
     * This text string identifies a particular computer configuration for sale.
     * It is sometimes also called a product ID or purchase order number. This
     * number is frequently found in existing fields, but there is no standard
     * format. Typically for a given system board from a given OEM, there are
     * tens of unique processor, memory, hard drive, and optical drive
     * configurations.
     *
     * @since SMBIOS 2.4
     */
    uint8_t sku_number;

    /**
     * @brief Product family.
     *
     * @details
     * String number of the product family.
     *
     * This text string identifies the
     * family to which a particular computer belongs. A family refers to a set
     * of computers that are similar but not identical from a hardware or
     * software point of view.
     *
     * Typically, a family is composed of different computer models, which have
     * different configurations and pricing points. Computers in the same family
     * often have similar branding and cosmetic features.
     *
     * @since SMBIOS 2.4
     */
    uint8_t family;
} __attribute__((packed, aligned(1)));

#ifdef __cplusplus

namespace dmi::table
{
    enum class system_wakeup : uint8_t
    {
        reserved     = DMI_SYSTEM_WAKEUP_RESERVED,
        other        = DMI_SYSTEM_WAKEUP_OTHER,
        unknown      = DMI_SYSTEM_WAKEUP_UNKNOWN,
        apm_timer    = DMI_SYSTEM_WAKEUP_APM_TIMER,
        modem_ring   = DMI_SYSTEM_WAKEUP_MODEM_RING,
        lan_remote   = DMI_SYSTEM_WAKEUP_LAN_REMOTE,
        power_switch = DMI_SYSTEM_WAKEUP_POWER_SWITCH,
        pci_pme      = DMI_SYSTEM_WAKEUP_PCI_PME,
        ac_power     = DMI_SYSTEM_WAKEUP_AC_POWER
    };

    class system : public dmi::basic_table
    {
    private:
        std::string m_manufacturer;
        std::optional<std::string> m_family;
        std::string m_product;
        std::string m_version;
        std::optional<std::string> m_serial_number;
        std::optional<std::string> m_sku_number;
        std::optional<system_wakeup> m_wakeup_type;

    public:
        inline const std::string& manufacturer() const { return m_manufacturer; }
        inline const std::optional<std::string>& family() const { return m_family; }
        inline const std::string& product() const { return m_product; }
        inline const std::string& version() const { return m_version; }
        inline const std::optional<std::string>& serial_number() const { return m_serial_number; }
        inline const std::optional<std::string>& sku_number() const { return m_sku_number; }
        inline const std::optional<system_wakeup> wakeup_type() const { return m_wakeup_type; }
    };
};

#endif // __cplusplus

__BEGIN_DECLS

const char *dmi_system_wakeup_str(dmi_system_wakeup_t value);

__END_DECLS

#endif // !LIBDMIXX_TABLE_SYSTEM_H
