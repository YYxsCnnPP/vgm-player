// SPDX-License-Identifier: GPL-3.0
#ifndef INC_VGMSTATE
#define INC_VGMSTATE

#ifdef ENABLE_PLAYER
#include "filebuffer.hpp"
#endif

#include <cstdint>

class VgmState
{
public:
    static uint32_t waitSamples;
#ifdef ENABLE_PLAYER
    static FileBuffer pcmBank;
#endif
};

#endif
