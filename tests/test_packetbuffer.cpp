//
// Created by ankit on 04/08/20.
//

#include "catch.hpp"
#include "../PacketBuffer.h"
TEST_CASE("read_qname() works properly") {
    PacketBuffer b;
    std::string s = "www.google.com";
    unsigned len = 0;

    std::string temp;
    for (auto c: s) {
        if (c == '.') {
            b.write_u8(len);
            for (auto i: temp) {
                b.write_u8((uint8_t)i);
            }
            temp = "";
            len = 0;
        } else {
            temp += c;
            len++;
        }
    }
    b.write_u8(len);
    for (auto c: temp) {
        b.write_u8((uint8_t)c);
    }
    b.write_u8(0);
    b.write_u8(192);
    b.write_u8(0);
    b.write_u8(0);
    b.seek(0);

    REQUIRE(b.read_qname() == "www.google.com");
    REQUIRE(b.read_qname() == "www.google.com");
}