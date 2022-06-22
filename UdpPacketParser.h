//UdpPacketParser.cpp - Class definitions for UdpPacketParser
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Abhi Nileshkumar Patel
//apatel477@myseneca.ca
//150046217
//SEP 200 WS04
//Date: 06/17/2022
//=======================
#ifndef UDPPACKETPARSER_H_
#define UDPPACKETPARSER_H_

#include "PacketParser.h"

class UdpPacketParser : public PacketParser
{
    unsigned int source_port;
    unsigned int dest_port;
    unsigned int length;
    unsigned int checksum;
    unsigned char* data;

public:
    bool parse(const char* packet);
    void display(std::ostream& os) const;
    unsigned int Power0x0100(unsigned int power);
    unsigned int ParseHeader(const char* packet, unsigned int position, unsigned int length);
    ~UdpPacketParser();
};

#endif// _UDPPACKETPARSER_H_