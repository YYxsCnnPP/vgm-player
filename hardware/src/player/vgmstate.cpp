// SPDX-License-Identifier: GPL-3.0
#include "vgmstate.hpp"

uint32_t VgmState::waitSamples = 0;

#ifdef ENABLE_PLAYER
FileBuffer VgmState::pcmBank;
#endif
