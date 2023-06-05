//
//// Title: Write an Embedded C program for External interrupt input switch press, output at relay.
//
//#include<pic18f4550.h>
//
//void main(void) {
//    TRISBbits.TRISB1=1;
//    TRISAbits.TRISA4=0;
//    PORTAbits.RA4=0; // if given 1 then led will blink through relay
//    INTCON3bits.INT1F=0; 
//    INTCON3bits.INT1E=1;
//    INTCON2bits.INTEDG1=0;
//    INTCONbits.PEIE=1;
//    INTCONbits.GIE=1;
//    
//    while(1){}
//    
//    return;
//}
//
//void __interrupt() relay(){
//    
//    if(INTCON3bits.INT1IF==1){
//        INTCONbits.GIE=0;
//        PORTAbits.RA4=1; // led will blink
//        
//        for(int i=0; i<1000; i++){
//            for(int j=0; j<1000; j++){
//                
//            }
//        }
//        
//        PORTAbits.RA4 =0;
//        INTCON3bits.INT1IF=0;
//        INTCONbits.GIE=1;
//    }
//}






#include <pic18f4550.h>

void __interrupt() relay(){
    if(INTCON3bits.INT1F == 1){
        INTCONbits.GIE = 0;
        PORTAbits.RA4 = 1;
        
        for(int i=0; i<1000; i++){
            for(int j=0; j<1000; j++);
        }
            
        PORTAbits.RA4 = 0;
            
        
        INTCONbits.GIE = 1;
        INTCON3bits.INT1F = 0;
    }
}

void main(void){
    TRISB.TRISB1 = 1; // making switch as input
    TRISA.TRISA4 = 0; // making relay as output
    PORTA.RA4 = 0;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    INTCON3bits.INT1E = 1;
    INTCON3bits.INT1F = 0;
    INTCON2bits.INTEDG1 = 0;
    
    while(1);
    
    return;
}








