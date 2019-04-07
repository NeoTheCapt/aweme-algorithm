cmake_minimum_required(VERSION 3.9)
project(aweme_aes)

set(CMAKE_CXX_STANDARD 11)
SET (aweme_aes_src main.cpp subs.cpp subs.h hexstring.cpp main.h)
#SET (aweme_aes_src main.cpp main.h)
#add_executable(
#        aweme_aes main.cpp subs.cpp subs.h
#        hexstring.cpp)

include_directories(/Applications/IDA\ Pro\ 7.0/ida.app/Contents/MacOS/plugins/)

ADD_LIBRARY (aweme_aes SHARED ${aweme_aes_src})

#ADD_LIBRARY (aweme_aes STATIC ${aweme_aes} main.h)

#SET_TARGET_PROPERTIES (aweme_aes PROPERTIES OUTPUT_NAME "aweme_aes")