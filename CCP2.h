/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CCP2_H
#define CCP2_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "CCP2.h"

#include <stdint.h>

#define CCP_MODE_DISABLED  0b0000 //= Capture/Compare/PWM disabled (resets CCPx module)
#define CCP_MODE_CAPTURE_EVERY_FALLING_EDGE 0b0100 //= Capture mode, every falling edge
#define CCP_MODE_CAPTURE_EVERY_RISING_EDGE 0b0101 //= Capture mode, every rising edge
#define CCP_MODE_CAPTURE_ON4TH_RISING_EDGE 0b0110 // = Capture mode, every 4th rising edge
#define CCP_MODE_CAPTURE_ON16TH_RISING_EDGE 0b0111 //= Capture mode, every 16th rising edge
#define CCP_MODE_COMPARE_SET_OUTPUT_ON_MATCH 0b1000 //= Compare mode, set output on match (CCPxIF bit is set)
#define CCP_MODE_COMPARE_CLEAR_OUTPUT_ON_MATCH 0b1001 //= Compare mode, clear output on match (CCPxIF bit is set)
#define CCP_MODE_COMPARE_SOFT_INTERRUPT_ON_MATCH 0b1010 //= Compare mode, generate software interrupt on match (CCPxIF bit is set, CCPx pin isunaffected)
#define CCP_MODE_COMPARE_SPECIAL_EVENT_TRIGGER 0b1011 //= Compare mode, trigger special event (CCPxIF bit is set, CCPx pin is unaffected); CCP1 resets TMR1; CCP2 resets TMR1 and starts an A/D conversion (if A/D module isenabled)
#define CCP_MODE_PWM 0b1100 //= PWM mode

void CCP2Init(uint8_t mode); 
// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

