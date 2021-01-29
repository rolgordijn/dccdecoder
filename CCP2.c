/*
 * File:   CCP2C.c
 * Author: Rian
 *
 * Created on 19 januari 2021, 22:16
 */


#include <xc.h>
#include <stdint.h>

#include "CCP2.h"




void CCP2Init(uint8_t mode){
    CCP2CONbits.CCP2M = mode; 
}
