#include <xc.h>
#include <stdint.h>
#include "inc/emicbus2_core.h"

#define CTRL_RESET 0x06

/* RX (trama larga ya validada por el core). */
void emicbus2_rx_CTRL(const uint8_t *b, uint16_t n)
{
    uint16_t plen = (uint16_t)b[5] | ((uint16_t)b[6] << 8);
    (void)n;
    if (b[2] == 0x00 && plen >= 1 && b[7] == CTRL_RESET)
        asm volatile ("reset");             /* -> bootloader (ventana 6.4) */
}

