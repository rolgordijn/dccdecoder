/*
 * File:   main.c
 * Author: Rian
 *
 * Created on 19 januari 2021, 21:31
 */


#include <xc.h>
#include "interrupts.h"
#include "tmr1.h"
#include "CCP2.h"
#include "dcc.h"


uint8_t adres;
uint8_t data;
uint8_t checksum ;

void setup() {
    tmr1Init();
    CCP2Init(CCP_MODE_CAPTURE_EVERY_RISING_EDGE);
    enableGlobalInterrupts();
    enablePeripheralInterrupts();
    disableTMR1Intterrupt();
    PIR2bits.CCP2IF = 1;


}

void __interrupt() my_isr_routine(void) {
    DCCbitDecode(TMR1);
    if (PIR2bits.CCP2IF) {
        tmr1Reload();
        CCP2IF = 0;
    }


}

void main(void) {
    setup();

    while (1) {
        if (DCCisRawPacketValid()) {
            adres = DCCgetAddress();
            data = DCCgetData();
            checksum = DCCgetChecksum();

            if (adres + data - checksum == 1) {
                PORTA = 50;
            } else {
                PORTA += 5;
            }
        }
    }
    return;
}
