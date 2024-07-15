#include <iostream>
#include <cstdint>
//#include "binaryOperations.h"

/* Topicxx: bin operatio:bit clear, inline definition and normal declaration 
If you define the function in a single source file (.cpp), you shouldn’t declare it as inline.
Otherwise, you’d have redundant definitions across multiple translation units
In such cases, omit the inline keyword.

inline uint8_t bit_clear(uint8_t number, uint8_t n) {
    return number & ~(uint8_t(1) << n);
}

ISSUE:
/VSCode/UdemyCpp/main.cpp:1212:(.text+0x27d5): undefined reference to `bit_clear(unsigned char, unsigned char)'
collect2.exe: error: ld returned 1 exit status
*/