// SPDX-License-Identifier: GPL-3.0
#include "ym2612.hpp"
#include "shiftregister.hpp"
#include <Arduino.h>
#include "util/hal.hpp"

void Ym2612::setup(void)
{
    ShiftRegister::setup();

    // setup IC for FM
    pinMode(FM_IC, OUTPUT);
    // setup WR for FM
    pinMode(FM_WR, OUTPUT);
    // setup A0 for FM
    pinMode(FM_A0, OUTPUT);
    // setup A1 for FM
    pinMode(FM_A1, OUTPUT);

    // IC and WR HIGH by default
    digitalWriteFast(FM_IC, HIGH);
    digitalWriteFast(FM_WR, HIGH);
    // A0 and A1 LOW by default
    digitalWriteFast(FM_A0, LOW);
    digitalWriteFast(FM_A1, LOW);

    // reset FM
    digitalWriteFast(FM_IC, LOW);
    delay(10);
    digitalWriteFast(FM_IC, HIGH);
}

void Ym2612::pushData(uint8_t port, uint8_t data)
{
    port &= 0x03;
    digitalWriteFast(FM_A0, port & 0x01);
    digitalWriteFast(FM_A1, (port & 0x02) >> 1);

    ShiftRegister::pushData(data);

    // TODO: check ready flag instead of waiting 1.056 microseconds
    digitalWriteFast(FM_WR, LOW);
    asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n");
#if TEENSYDUINO
    asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n");
    asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n");
    asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n");
    asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n");
    asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n");
#endif
    digitalWriteFast(FM_WR, HIGH);
}
