///*
// * File:   prac4.c
// * Author: somes
// *
// * Created on 30 May, 2023, 7:03 PM
// */
//
//
//#include <xc.h>
//#include <pic18f458.h>
//
//void delay(){
//    T0CON = 0x07;
//    TMR0 = 65500;
//    //TMR1 = 65531;
//    //INTCONbits.TMR0IF = 0;
//    T0CONbits.TMR0ON = 1;
//    while(INTCONbits.TMR0IF==0);
//    INTCONbits.TMR0IF = 0;
//    T0CONbits.TMR0ON = 0;
//    return;
//}
//
//void main(void) {
//    TRISB = 0;
////    PORTB = 0x00;
//    while(1){
//        delay();
//        PORTB = 0b0000111;
//        delay();
//        PORTB = 0b0001110;
//        delay();
//        PORTB = 0b0011100;
//        
//    }
//    return;
//}












#include <pic18f4550.h>

void delay(){
    T0CON = 0x07; // prescale of 1:256
    TMR0 = 65000;
    T0CONbits.TMR0ON = 1;
    INTCONbits.TMR0IF = 0;
    while(INTCONbits.TMR0IF == 0);
    T0CONbits.TMR0ON = 0;
    INTCONbits.TMR0IF = 0;
    
}

void main(void){
    TRISB = 0;
    while(1){
        PORTB = 0x07;
        delay();
        PORTB = 0x14;
        delay();
        PORTB = 0x28;
        delay();
    }
    return;
}