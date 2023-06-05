
#include <pic18f4550.h>

void main(void){
    
    TRISCbits.RC2 = 0;
    CCP1CON = 0b00011100;
    
    T2CON = 0b00000010;
    GIE = 1;
    TRISAbits.RA4 = 0;
    
    while(1){
        TMR2 = 0;
        TMR2IF = 0;
        TMR2ON = 1;
        PR2 = 155;
        CCPR1L = 116;
        for(int i=0; i<255; i+=50){
            CCPR1L = i;
            for(int j=0; j<1000; j++)
                for(int k=0; k<1000; k++);
                PORTAbits.RA4 = ~PORTAbits.RA4;
        }
    }
    
    return;
}