#ifndef DNSSERVER_RESOURCE_RECORD_H
#define DNSSERVER_RESOURCE_RECORD_H

#include <string>
#include "PacketBuffer.h"

class ResourceRecord {
    enum Type {UNKNOWN, A, AAAA, MX, CNAME, NS};
public:
    Type type;
    std::string domain;
    std::string addr;
    uint32_t ttl;
    uint16_t data_len;
    uint16_t qtype;

    ResourceRecord(PacketBuffer &buf);
    void write(PacketBuffer &buf);
};

#endif // DNSSERVER_RESOURCE_RECORD_H