#include "PacketHeader.h"

PacketHeader::PacketHeader(PacketBuffer &buf) {
    id = buf.read_u16();
    uint8_t flags = buf.read_u8();
    if (flags & (1 << 7)) {
        isResponse = true;
    } else {
        isResponse = false;
    }

    opcode = (flags >> 3) & 15;
    isAuthoritativeAnswer = flags & (1 << 2);
    isTruncated = flags & 2;
    recursionDesired = flags & 1;

    flags = buf.read_u8();
    recursionAvailable = flags & (1 << 7);
    responseCode = flags & 15;

}

std::ostream& operator<<(std::ostream &stream, PacketHeader &h) {
    stream << "Id = " << h.id << "\n";
    if (h.isResponse) {
        stream << "Answer" << "\n";
    } else {
        stream << "Question" << "\n";
    }
    stream << "Opcode: " << h.opcode << "\n";
    stream << "Authority: " << (h.isAuthoritativeAnswer ? "true" : "false") << "\n";
    stream << "Truncated: " << (h.isTruncated ? "true" : "false") << "\n";
    stream << "Recursion Desired: " << (h.recursionDesired ? "true" : "false") << "\n";
    stream << "Recursion Available: " << (h.recursionAvailable ? "true" : "false") << "\n";
    stream << "Response Code: " << h.responseCode << "\n";
}
