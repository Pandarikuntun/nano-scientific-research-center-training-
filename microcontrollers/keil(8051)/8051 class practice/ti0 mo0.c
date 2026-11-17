#include <reg51.h>

void delay() {
    TH0 = 0x93;
    TL0 = 0xFF;
    TR0 = 1;
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}

int main() {
    TMOD &= 0xF0;
    TMOD |= 0x01;
    P1 = 0x00;

    while (1) {
        P1 |= (1 << 2);
        delay();
        P1 &= ~(1 << 2);
        delay();
    }
}