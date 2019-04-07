// aweme_aes.cpp: 定义控制台应用程序的入口点。
//
#include <stdio.h>
#include "subs.h"
//#include <string>
#include <iostream>
//#include <sstream>
//#include <iomanip>
#include "main.h"

using namespace std;

//string Encode(string hexplain, string key)
//{
//    string plain = hexToStr(hexplain);
//    char *xkey;
//    char *xplain;
//    int keylength = key.length();
//    int plainlength = plain.length();
//    xkey = (char*) malloc(keylength);
//    xplain = (char*) malloc(plainlength);
//    memcpy(xkey, key.data(), keylength);
//    memcpy(xplain, plain.data(), plainlength);
//    unsigned char *out = (unsigned char*) malloc(plainlength + 100);
//    aweme_aes((__int64)xplain, plainlength, (__int64)xkey, keylength, (__int64)out);
//    free(xkey);
//    free(xplain);
//    xkey = NULL;
//    xplain = NULL;
//    int cryptedStr_length = plainlength + 4 + (16 - plainlength%16);
//    std::string hexStr = charsToHex(out, cryptedStr_length);
//    free(out);
//    out = NULL;
//    return hexStr;
//}

char* Encode(char* plain, int plainlength, char* key, int keylength)
{
    //string plain = hexToStr(hexplain);
    char *xkey;
    char *xplain;
    //int keylength = key.length();
    //int plainlength = plain.length();
    xkey = (char*) malloc(keylength);
    xplain = (char*) malloc(plainlength);
    memcpy(xkey, key, keylength);
    memcpy(xplain, plain, plainlength);
    unsigned char *out = (unsigned char*) malloc(plainlength + 100);
    aweme_aes((__int64)xplain, plainlength, (__int64)xkey, keylength, (__int64)out);
    free(xkey);
    free(xplain);
    xkey = NULL;
    xplain = NULL;
//    int cryptedStr_length = plainlength + 4 + (16 - plainlength%16);
//    std::string hexStr = charsToHex(out, cryptedStr_length);
//    free(out);
    //out = NULL;
    return (char*)out;
}

int main(){
    printf("123");
}

void func_test(){
    printf("test");
}

int test_sum(int x, int y){
    return x+y;
}