#ifndef DNSSERVER_PACKETHEADER_H
#define DNSSERVER_PACKETHEADER_H


#include <cstdint>
#include "PacketBuffer.h"

class PacketHeader {
public:
    uint16_t id;
    bool isResponse;
    int opcode;
    bool isAuthoritativeAnswer;
    bool isTruncated;
    bool recursionDesired;
    bool recursionAvailable;
    int responseCode;

    PacketHeader(PacketBuffer &buf);
    PacketHeader() = default;
    friend std::ostream& operator<<(std::ostream &stream, PacketHeader &header);
};


#endif //DNSSERVER_PACKETHEADER_H
