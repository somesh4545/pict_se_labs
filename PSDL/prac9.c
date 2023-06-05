
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

int read_temp(){
    ADCON0 = 0b00011101; // channel 3, go/done on, power on adcon
    // ADCON0bits.GO_DONE = 1;
    ADCON0bits_t.GO_DONE = 1;
    while(ADCON0bits_t.GO_DONE == 1);
    return ADRES;
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
    
    int temp;
    
    while(1){
        temp = read_temp();
        temp = ((temp*500) / 1023);
        sendData(temp/10 + 48);
        sendData(temp%10 + 48);
        
        for(int i=0; i<100; i++)
            delay();
    }   
    
    return;
}