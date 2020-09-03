#include "PacketBuffer.h"

uint8_t PacketBuffer::read_u8() {
    return this->buf.at(this->pos++);
}

uint16_t PacketBuffer::read_u16() {
    uint16_t a = this->read_u8();
    a = a << 8u | this->read_u8();
    return a;
}

uint32_t PacketBuffer::read_u32() {
    uint32_t a = this->read_u16();
    a = a << 16u | this->read_u16();
    return a;
}

std::string PacketBuffer::read_qname() {
    unsigned old_pos;
    bool compressed = false;
    std::string s;
    uint16_t len = this->read_u8();

    while(len != 0) {
        if (!compressed && (len & 192u)) {
            old_pos = this->getpos() - 1;
            compressed = true;
            len ^= 192u;
            len = len << 8u | this->read_u8();
            this->seek(len);
            len = this->read_u8();
        }
        while(len > 0) {
            s += (char) this->read_u8();
            len -= 1;
        }
        s += '.';
        len = this->read_u8();
    }
    s.pop_back();
    if (compressed) {
        this->seek(old_pos + 2);
    }
    return s;
}

void PacketBuffer::write_u8(uint8_t data) {
    this->buf.at(this->pos) = data;
    this->pos++;
}
