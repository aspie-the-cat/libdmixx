//
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2025, Dmitry Novikov <cat@aspie.ru>
//
#ifndef LIBDMIXX_DMI_CONTEXT_H
#define LIBDMIXX_DMI_CONTEXT_H

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

#endif // !LIBDMIXX_DMI_CONTEXT_H
