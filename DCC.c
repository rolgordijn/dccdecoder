/*
 * File:   DCC.c
 * Author: Rian
 *
 * Created on 19 januari 2021, 22:40
 */


#include <xc.h>
#include "dcc.h"
#include <stdint.h>


uint32_t rawPacketLow;
uint16_t rawPacketHigh;
uint32_t validRawPacket;


uint8_t dccPacketData; 
uint8_t dccPacketAddress; 
uint8_t dccPacketChecksum; 

void DCCbitDecode(uint16_t TMR1Value) {
    if (rawPacketLow | 0x80000000) {
        rawPacketHigh = rawPacketHigh * 2 + 1;
    } else {
        rawPacketLow = rawPacketLow * 2;
    }

    if (TMR1Value < 790) {
        rawPacketHigh = rawPacketHigh * 2 + 1;
    } else {
        rawPacketLow = rawPacketLow * 2;
    }
}


int DCCisRawPacketValid() {
    uint32_t mask = 0xF8040201;
    uint32_t expect = 0xF0000000;
    int ret = (((rawPacketHigh & 0x3FF) == 0x3FF) && ((rawPacketLow & mask) == expect));
    if (ret){
        validRawPacket = rawPacketLow;
        DCCgetChecksum();
        DCCgetData();
        DCCgetAddress();         
    }
    return ret;
}


uint8_t DCCgetChecksum(){
    uint8_t  ret = (uint8_t) validRawPacket >> 1; 
    
    return ret;
}

uint8_t DCCgetData(){
    uint8_t  ret = (uint8_t)  validRawPacket >> 10; 
    dccPacketData = ret; 
    return ret; 
}

uint8_t DCCgetAddress(){
    uint32_t  val =  validRawPacket >> 19; 
    uint8_t ret = (uint8_t) val; 
    dccPacketAddress = ret;
    return ret; 
}


uint8_t isDCCCheckSumValid(){
    if((dccPacketAddress ^ dccPacketData) == dccPacketChecksum) return 1;
    else return 0; 
    
   
}

