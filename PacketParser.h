//PacketParser.h - class declaration for a packet parser
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Abhi Nileshkumar Patel
//apatel477@myseneca.ca
//150046217
//SEP 200 WS04
//Date: 06/17/2022
//=======================

#ifndef _PACKETPARSER_H_
#define _PACKETPARSER_H_

#include <iostream>

class PacketParser {
public:
	virtual bool parse(const char* packet) { return false; };
	virtual void display(std::ostream& os) const {};
	virtual ~PacketParser() {};
};

std::ostream& operator<<(std::ostream& os, PacketParser& parser);

#endif// _PACKETPARSER_H_
