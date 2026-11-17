#include <reg51.h>

sbit rs = P1^0;
sbit rw = P1^1;
sbit en = P1^2;
sbit led = P1^3;

void delay() {
    int i, j;
    for (i = 0; i < 100; i++)
        for (j = 0; j < 100; j++);
}

void cmd_mode(unsigned char val) {
    P2 = val;
    rs &= ~(1 << 0);
    rw &= ~(1 << 1);
    en |= (1 << 2);
    delay();
    en &= ~(1 << 2);
}

void data_mode(unsigned char data_val) {
    P2 = data_val;
    rs |= (1 << 0);
    rw &= ~(1 << 1);
    en |= (1 << 2);
    delay();
    en &= ~(1 << 2);
}

void init() {
    cmd_mode(0x38);
    delay();
    cmd_mode(0x0F);
    delay();
    cmd_mode(0x01);
    delay();
    cmd_mode(0x80);
    delay();
}

void main() {
    unsigned char a[] = "ON";
    unsigned char b[] = "OFF";
    int l;

    init();
    while (1) {
        l = 0;
        led |= (1 << 3);
        while (a[l] != '\0') {
            data_mode(a[l]);
            l++;
            delay();
        }
        cmd_mode(0x01);
        cmd_mode(0x80);
        l = 0;
        led &= ~(1 << 3);
        while (b[l] != '\0') {
            data_mode(b[l]);
            l++;
            delay();
        }
        cmd_mode(0x01);
        cmd_mode(0x80);
    }
}
