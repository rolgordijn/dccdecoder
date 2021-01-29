/*
 * File:   interrupts.c
 * Author: Rian
 *
 * Created on 19 januari 2021, 22:03
 */


#include <xc.h>

void enableGlobalInterrupts(void){
    INTCONbits.GIE = 1;
    
};
void disableGlobalInterrupts(void){
    INTCONbits.GIE = 0;
     
};

void enablePeripheralInterrupts(void){
    INTCONbits.PEIE = 1;   
};
void disablePeripheralInterrupts(void){
    INTCONbits.PEIE = 0;
};