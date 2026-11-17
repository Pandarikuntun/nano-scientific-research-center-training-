#include<reg51.h>

sbit led1=P1^0; //led
sbit sw1=P2^0; // switch

void main() {
    led1=0; // Initialize LED to OFF
    while(1) {
        if(sw1==0) {
            led1=1; // Turn ON LED
            while(sw1==0); // Wait for switch release
            led1=0; // Turn OFF LED
            while(sw1==1); // Wait for switch press
        }
    }
}
