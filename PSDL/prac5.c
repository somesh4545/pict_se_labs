//
//// Aim : Write an Embedded C program for Timer programming ISR based buzzer on/off.
//
//#include<pic18f4550.h>
//
//int count =0;
//int buzzer_on =0;
//
//void __interrupt() buzzgobeep(){
//    if(PIR1bits.TMR1IF==1){
//        //INTCONbits.GIE=0;
//        if(buzzer_on && count==10){
//            buzzer_on = 0;
//            PORTAbits.RA5 = 0;
//            count=0;
//        }
//        if(!buzzer_on && count == 20){
//            buzzer_on = 1;
//            PORTAbits.RA5=1;
//            count=0;
//        }
//        count++;
//        TMR1=28038;
//        
//        PIR1bits.TMR1IF=0;
//        // INTCONbits.GIE = 1;
//        
//    }
//}
//
//void main(void) {
//    T1CON = 0XB0;
//    TRISAbits.TRISA5 = 0;
//    PORTAbits.RA5=0;
//    
//    PIE1bits.TMR1IE=1;
//    PIR1bits.TMR1IF=0;
//    INTCONbits.PEIE=1; // sets low interrupt for priority
//    INTCONbits.GIE=1;
//    T1CONbits.TMR1ON=1;
//    while(1);
//    
//    return;
//}














#include <pic18f4550.h>

int count = 0;
int buzzer_on = 0;

void __interrupt() buzz(){
    
    if(PIR1bits.TMR1IF == 1){
        // buzzer off
        if(buzzer_on && count==10){
            buzzer_on = 0;
            count = 0;
            PORTAbits.RA5 = 0;
        }
        if(!buzzer_on && count==20){
            buzzer_on = 1;
            PORTAbits.RA5 = 1;
            count = 0;
        }
        count++;
        PIR1bits.TMR1IF = 0;
    }
    
}

void main(void){
    T1CON = 0xB0; // enable 16 bit mode and 1:8 prescale
    
    TRISAbits.TRISA5 = 0;
    PORTAbits.RA5 = 0;
    
    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 1;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    T1CONbits.TMR1ON = 1;
    
    while(1);
    
    return;
}