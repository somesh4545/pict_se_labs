/*
 * File:   newmain.c
 * Author: somes
 *
 * Created on 30 May, 2023, 6:46 PM
 */


#include <xc.h>
//#include <pic18f458.h>

void main(void) {
    TMR0 = 0x05;
    TMR1 = 0x06;
    TRISB = 0;
    PORTB = TMR0 + TMR1;
    return;
}
