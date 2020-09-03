//
// Created by ankit on 04/08/20.
//

#ifndef DNSSERVER_PACKETBUFFER_H
#define DNSSERVER_PACKETBUFFER_H
#include <cstdint>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <string>
#include <array>

class PacketBuffer {

    unsigned pos;

public:
    std::array<uint8_t, 512> buf;
    PacketBuffer(): pos(0), buf{}{}
    PacketBuffer(std::array<uint8_t, 512> ar): pos(0), buf(ar){}

    unsigned getpos() const { return this->pos; }

    void step(int steps) { this->pos += steps; }

    void seek(unsigned _pos) { this->pos = _pos; }
    uint8_t read_u8();
    uint16_t read_u16();
    uint32_t read_u32();
    std::string read_qname();
    void write_u8(uint8_t data);

};

#endif //DNSSERVER_PACKETBUFFER_H
