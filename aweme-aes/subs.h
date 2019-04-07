#pragma once
#include "defs.h"
#include <stdlib.h> // pulls in declaration of malloc, free
#include <string.h> // pulls in declaration for strlen.
#include <string> // pulls in declaration for strlen.

using namespace std;
__int64 aweme_aes(__int64 plainStr, __int64 plainStr_length, __int64 key, __int64 key_length, __int64 strOut);
void *sub_1005D0B50(void *keyStr, signed int keyStr_length, unsigned int *out);
signed __int64 sub_1005D099C(const void *a1, signed int a2, void *keyStr, signed int keyStr_Length, _BYTE *strOut, char value_2);
string hexToStr(string hexStr);
string strToHex(string input);
string charsToHex(unsigned char* input, int length);
//extern string Encode(string hexplain, string key);