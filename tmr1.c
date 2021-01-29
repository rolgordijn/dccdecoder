/*
 * File:   tmr1.c
 * Author: Rian
 *
 * Created on 19 januari 2021, 21:42
 */


#include <xc.h>
#include "tmr1.h"


void tmr1Init(void){
  PIR1bits.TMR1IF	 = 0;
  tmr1Reload(); 
  tmr1On();
};

void tmr1Reload(void){
    disableTMR1Intterrupt();
    TMR1H = 0;
    TMR1L = 0;
    enableTMR1Intterrupt(); 
}; 

void enableTMR1Intterrupt(void){
    PIE1bits.TMR1IE = 1;
}

void disableTMR1Intterrupt(void){
    PIE1bits.TMR1IE = 0; 
}

void resetTMR1IntterruptFlag(void){
    PIR1bits.TMR1IF = 0;
    
}

int tmr1InterruptOccured(void){
    return PIR1bits.TMR1IF; 
}

void tmr1On(void){
    T1CONbits.TMR1ON  = 1;
}

void tmr1Off(void){
    T1CONbits.TMR1ON  = 0;
}