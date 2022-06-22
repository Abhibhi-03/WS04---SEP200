//PacketParser.cpp - Function defintions for PacketParser.h
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Abhi Nileshkumar Patel
//apatel477@myseneca.ca
//150046217
//SEP 200 WS04
//Date: 06/17/2022
//=======================
#include "PacketParser.h";

std::ostream& operator<<(std::ostream& os, PacketParser& parser)
{
    parser.display(os);
    return os;
}