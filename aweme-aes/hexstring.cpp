//
// Created by Brian.W on 2018/3/28.
//
#include "subs.h";
#include "string";

using namespace std;
string strToHex(string input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

string hexToStr(string hexStr)
{
    int len = hexStr.length();
    std::string newString;
    for(int i=0; i< len; i+=2)
    {
        string byte = hexStr.substr(i,2);
        char chr = (char) (int)strtol(byte.c_str(), NULL, 16);
        newString.push_back(chr);
    }
    return newString;
}


string charsToHex(unsigned char* input, int length)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = length;

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}