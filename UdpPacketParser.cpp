//UdpPacketParser.cpp - Function definitions for UdpPacketParser.h
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Abhi Nileshkumar Patel
//apatel477@myseneca.ca
//150046217
//SEP 200 WS04
//Date: 06/17/2022
//=======================
#include "UdpPacketParser.h"
#include <iostream>
#include <iomanip>

#define UDP_HEADER_LEN 8

bool UdpPacketParser::parse(const char* packet)
{
    bool ret = false;
    if (packet == nullptr) return ret;

    source_port = ParseHeader(packet, 0, 2);                // This is the parser header: packet, data position, length
    dest_port = ParseHeader(packet, 2, 2);
    length = ParseHeader(packet, 4, 2);
    checksum = ParseHeader(packet, 6, 2);

    ret = checksum == source_port + dest_port + length;

    if (ret)
    {
        data = new unsigned char[length + 1];
        memcpy(data, packet + UDP_HEADER_LEN, length);
        data[length] = '\0';            //This sets the termination
    }
    return ret;
}

void UdpPacketParser::display(std::ostream& os) const
{
    os << "Report for UDP Packet Parser" << std::endl;
    os << std::setw(13) << std::left << "source port:" << source_port << std::endl;
    os << std::setw(13) << "dest port:" << dest_port << std::endl;
    os << std::setw(13) << "data length:" << length << std::endl;
    os << std::setw(13) << "data:" << data << std::endl;
    os << std::endl;
}

unsigned int UdpPacketParser::Power0x0100(unsigned int power)
{
    int res = 0x01;
    for (int i = 0; i < power; i++) res *= 0x0100;
    return res;
}

unsigned int UdpPacketParser::ParseHeader(const char* packet, unsigned int position, unsigned int length)
{
    return length == 1 ? packet[position] :
        (packet[position]) * Power0x0100(length - 1) + ParseHeader(packet, position + 1, length - 1);
}

UdpPacketParser::~UdpPacketParser()
{
    delete[] data;
    data = nullptr;
}