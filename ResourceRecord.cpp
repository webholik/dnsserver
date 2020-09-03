#include "ResourceRecord.h"

ResourceRecord::ResourceRecord(PacketBuffer &buf) {
    domain = buf.read_qname();

}

