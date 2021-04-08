#include <stdio.h>

unsigned char mergeBits(unsigned char a, unsigned char b) {
    return a << 4 | (b & 0xF);
}

int main() {
    printf("%02x\n", mergeBits(0x5, 0xE));
    printf("%02x\n", mergeBits(0xA, 0xC));
    printf("%02x\n", mergeBits(0xD, 0x2));
}