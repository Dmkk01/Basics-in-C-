#include <stdio.h>

unsigned char sixBits(unsigned char v) {
    return v & 0x3F;
}

int main(void) {
    printf("%02x\n", sixBits(0xDF));
    printf("%02x\n", sixBits(0x8D));
    printf("%02x\n", sixBits(0x28));
}
