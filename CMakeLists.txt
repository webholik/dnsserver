cmake_minimum_required(VERSION 3.16)
project(dnsserver)

set(CMAKE_CXX_STANDARD 17)

add_executable(dnsserver main.cpp PacketBuffer.h PacketBuffer.cpp PacketHeader.cpp PacketHeader.h ResourceRecord.h ResourceRecord.cpp)
add_executable(test tests/test_main.cpp PacketBuffer.cpp PacketHeader.cpp tests/test_packetbuffer.cpp tests/test_packerheader.cpp)