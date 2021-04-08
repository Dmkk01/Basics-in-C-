#include "tcpheader.h"

int getSourcePort(const unsigned char* tcp_hdr) {
    return (tcp_hdr[0] << 8) | tcp_hdr[1];
}

int getDestinationPort(const unsigned char* tcp_hdr) {
    return (tcp_hdr[2] << 8) | tcp_hdr[3];
}

void setSourcePort(unsigned char* tcp_hdr, int port) {
    tcp_hdr[0] = (port & 0xFFFF) >> 8;
    tcp_hdr[1] = port & 0xFF;
}

void setDestinationPort(unsigned char* tcp_hdr, int port) {
    tcp_hdr[2] = (port & 0xFFFF) >> 8;
    tcp_hdr[3] = port & 0xFF;
}

int getAckFlag(const unsigned char* tcp_hdr) {
    return !!(tcp_hdr[13] & 0x10);
}

void setAckFlag(unsigned char* tcp_hdr, int flag) {
    if(flag)
        tcp_hdr[13] |= 1<<4;
    else
        tcp_hdr[13] &= ~(1<<4);
}

int getDataOffset(const unsigned char* tcp_hdr) {
    return tcp_hdr[12] >> 4;
}

void setDataOffset(unsigned char* tcp_hdr, int offset) {
    tcp_hdr[12] = (tcp_hdr[12] & 0xF) | (offset << 4);
}
