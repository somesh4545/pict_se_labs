/*
 * File:   prac2.c
 * Author: somes
 *
 * Created on 30 May, 2023, 6:51 PM
 */


#include <xc.h>
#include<stdlib.h>
#include<stdio.h>
#include <pic18f458.h>

void main(void) {

    int sum = 0;
    int arr[100];
    for(int i=0; i<100; i++){
        arr[i] = 1;
    }
    
    for(int i=0; i<100; i++){
        sum += arr[i];
    }
    
    
    
//    TRISB = 0;
    TMR0 = sum;

    return;
}
