#include "catch.hpp"
#include <fstream>
#include "../PacketHeader.h"

TEST_CASE("header parsing works properly") {
    std::fstream f("query_packet.txt");
    PacketBuffer buf;
    f.read((char *) buf.buf.data(), 512);
    PacketHeader header(buf);
    REQUIRE(header.id == 61752);
    REQUIRE(header.isQuery == true);
    REQUIRE(header.isAuthoritativeAnswer == false);
    REQUIRE(header.isTruncated == false);
    REQUIRE(header.recursionDesired == false);
    REQUIRE(header.recursionAvailable == false);
    REQUIRE(header.responseCode == 0);
    REQUIRE(header.opcode == 0);
}