//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef DMI_CONTEXT_H
#define DMI_CONTEXT_H

#pragma once

#include <dmi/types.h>

namespace dmi
{
    class context
    {
    public:
        context();
        virtual ~context();
    };
}

#endif // !DMI_CONTEXT_H
