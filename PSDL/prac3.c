/*
 * File:   prac3.c
 * Author: somes
 *
 * Created on 30 May, 2023, 6:58 PM
 */


#include <xc.h>

void main(void) {

    TMR1L = 0x04;
    TMR1H = 0x08;
    
    TRISC = 0;
    TRISB = 0;
    
    int choice = 0x0F;
    
    while(1){
        if(choice == 1){
           PORTB = TMR1H * TMR1L;
        }else{
            PORTB = TMR1H % TMR1L; 
            PORTC = TMR1H / TMR1L; 
        }
    }
    
    

    return;
}
