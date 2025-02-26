//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#include <dmi/entry.h>

#include <stdexcept>
#include <memory>
#include <fstream>
#include <cstring>

using namespace dmi;

static const std::map<std::string, entry::factory> anchor_map =
{
    {
        DMI_ANCHOR_LEGACY,
        [](const std::byte *ptr, size_t length) -> std::unique_ptr<entry>
        {
            return std::make_unique<entry_legacy>(ptr, length);
        }
    },
    {
        DMI_ANCHOR_V21,
        [](const std::byte *ptr, size_t length) -> std::unique_ptr<entry>
        {
            return std::make_unique<entry_v21>(ptr, length);
        }
    },
    {
        DMI_ANCHOR_V30,
        [](const std::byte *ptr, size_t length) -> std::unique_ptr<entry>
        {
            return std::make_unique<entry_v30>(ptr, length);
        }
    }
};

auto entry::create(const std::byte *ptr, size_t length)
    -> std::unique_ptr<entry>
{
    if (ptr == nullptr)
        throw std::invalid_argument("ptr");
    if (length == 0)
        throw std::invalid_argument("length");

    entry::factory factory = nullptr;

    for (auto [anchor, item] : anchor_map) {
        if (length < anchor.size())
            continue;
        if (std::memcmp(ptr, anchor.c_str(), anchor.size()) != 0)
            continue;

        factory = item;
        break;
    }

    if (factory == nullptr)
        throw std::runtime_error("unsupported entry type");

    return factory(ptr, length);
}

entry::entry(const std::string& anchor, const std::byte *data, size_t length)
{
    if (anchor.empty())
        throw std::invalid_argument("anchor");
    if (data == nullptr)
        throw std::invalid_argument("data");
    if (length < anchor.size())
        throw std::invalid_argument("length");

    if (std::memcmp(data, anchor.c_str(), anchor.size()) != 0)
        throw std::runtime_error("invalid entry point structure");
}

entry::~entry()
{
}

entry_legacy::entry_legacy(const std::byte *data, size_t length)
    : entry(DMI_ANCHOR_LEGACY, data, length)
{
}

entry_v21::entry_v21(const std::byte *data, size_t length)
    : entry(DMI_ANCHOR_V21, data, length)
{
}

entry_v30::entry_v30(const std::byte *data, size_t length)
    : entry(DMI_ANCHOR_V30, data, length)
{
}
