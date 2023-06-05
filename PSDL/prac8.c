
#include <pic18f4550.h>

#define RS PORTAbits.RA0
#define EN PORTAbits.RA1

char cmds[5] = {0x38, 0x0E, 0x01, 0x06, 0xC0};

void delay(){
    for(int i=0;i<1000; i++)
        for(int j=0; j<1000; j++);
}

void sendCommand(unsigned char ch){
    RS = 0;
    PORTB = ch;
    EN = 1;
    delay();
    EN = 0;
    delay();
}

void sendData(unsigned char ch){
    RS = 1;
    PORTB = ch;
    EN = 1;
    delay();
    EN = 0;
    delay();
}

void main(void){
    ADCON1 = 0x0F;
    TRISB = 0;
    TRISAbits.RA0 = 0;
    TRISAbits.RA1 = 0;
    
    for(int i=0; i<5; i++){
        sendCommand(cmds[i]);
        delay();
    }
    
    char* msg = "23389";
    while(*msg != '\0'){
        sendData(msg);
        msg++;
        delay();
    }
    
    return;
//}