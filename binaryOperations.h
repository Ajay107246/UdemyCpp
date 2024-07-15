#include <iostream>
#include <cstdint>
#include <cstdio>
#include <bitset>
/*
Topicxx: Microcontroller, bitwise operation, Register set/clear/reset
*/
uint8_t REG_0{ 0b0000'0000 };	//8 bits in size means room for 8 flags
uint8_t I2C_GPS_ANTENNA_PIN{0b0001'0000};   //example PIN #5 for GPS Antenna to set/reset


constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

/*
//Above  mask's can be defined in below fashion, bit masks using hexadecima
constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000

//An easier method is to use the left-shift operator to shift a single bit into the proper location:

constexpr std::uint8_t mask0{ 1 << 0 }; // 0000 0001
constexpr std::uint8_t mask1{ 1 << 1 }; // 0000 0010
constexpr std::uint8_t mask2{ 1 << 2 }; // 0000 0100
constexpr std::uint8_t mask3{ 1 << 3 }; // 0000 1000
constexpr std::uint8_t mask4{ 1 << 4 }; // 0001 0000
constexpr std::uint8_t mask5{ 1 << 5 }; // 0010 0000
constexpr std::uint8_t mask6{ 1 << 6 }; // 0100 0000
constexpr std::uint8_t mask7{ 1 << 7 }; // 1000 0000

*/

/* INFO:
This is one of the reasons OpenGL, a well regarded 3d graphic library, opted to use bit flag parameters instead of many consecutive Boolean parameters.

Here’s a sample function call from OpenGL:

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the color and the depth buffer
GL_COLOR_BUFFER_BIT and GL_DEPTH_BUFFER_BIT are bit masks defined as follows (in gl2.h):

#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_COLOR_BUFFER_BIT               0x00004000
*/

/*Topicxx: Bitwise Operation, bit_clear()*/
inline uint8_t bit_clear(uint8_t number, uint8_t index) {
    return number & ~(uint8_t(1) << index);
}
//int clearBit(int n, int k) { return (n & (~(1 << (k)))); } 

/*Topicxx: Bitwise Operation, bit_set()*/
inline uint8_t bit_set(uint8_t number, uint8_t index) {
    return number | (uint8_t(1) << index);
}
//int setBit(int n, int k) { return (n | (1 << (k))); } 

/*Topicxx: Bitwise Operation, bit_check0_1()*/
bool bit_check(uint8_t number, uint8_t n){
    return (number >> n) & 1;
}

/*// Function to toggle the kth bit of n */
uint8_t toggleBit(uint8_t number, int n) { 
    return (number ^ (1 << (n)));
} 


/*
Color display devices such as TVs and monitors are composed of millions of pixels, each of which can display a dot of color. Each dot of color is the result of combining three beams of light: one red, one green, and one blue (RGB). The intensity of these lights are varied to produce different colors.

Typically, the intensity of R, G, and B for a given pixel is represented by an 8-bit unsigned integer. For example, a red pixel would have R=255, G=0, B=0. A purple pixel would have R=255, G=0, B=255. A medium-grey pixel would have R=127, G=127, B=127.

When assigning color values to a pixel, in addition to R, G, and B, a 4th value called A is often used. “A” stands for “alpha”, and it controls how transparent the color is. If A=0, the color is fully transparent. If A=255, the color is opaque.

R, G, B, and A are normally stored as a single 32-bit integer, with 8 bits used for each component:

32-bit RGBA value
bits 31-24	bits 23-16	bits 15-8	bits 7-0
RRRRRRRR	GGGGGGGG	BBBBBBBB	AAAAAAAA
red	        green	    blue	    alpha
The following program asks the user to enter a 32-bit hexadecimal value, 
and then extracts the 8-bit color values for R, G, B, and A.

constexpr std::uint32_t redBits{ 0xFF000000 };
constexpr std::uint32_t greenBits{ 0x00FF0000 };
constexpr std::uint32_t blueBits{ 0x0000FF00 };
constexpr std::uint32_t alphaBits{ 0x000000FF };

std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
std::uint32_t pixel{};
std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

// use Bitwise AND to isolate the pixels for our given color,
// then right shift the value into the lower 8 bits
const std::uint8_t red{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };
const std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
const std::uint8_t blue{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };
const std::uint8_t alpha{ static_cast<std::uint8_t>(pixel & alphaBits) };

std::cout << "Your color contains:\n";
std::cout << std::hex; // print the following values in hex

    // reminder: std::uint8_t will likely print as a char
    // we static_cast to int to ensure it prints as an integer
std::cout << static_cast<int>(red)   << " red\n";
std::cout << static_cast<int>(green) << " green\n";
std::cout << static_cast<int>(blue)  << " blue\n";
std::cout << static_cast<int>(alpha) << " alpha\n";

*/

/*
SUMMARY:
Summarizing how to set, clear, toggle, and query bit flags:

To query bit states, we use bitwise AND:

if (flags & option4) ... // if option4 is set, do something
To set bits (turn on), we use bitwise OR:

flags |= option4; // turn option 4 on.
flags |= (option4 | option5); // turn options 4 and 5 on.
To clear bits (turn off), we use bitwise AND with bitwise NOT:

flags &= ~option4; // turn option 4 off
flags &= ~(option4 | option5); // turn options 4 and 5 off
To flip bit states, we use bitwise XOR:

flags ^= option4; // flip option4 from on to off, or vice versa
flags ^= (option4 | option5); // flip options 4 and 5
*/

/*
Quiz time

Question #1

Do not use std::bitset in this quiz. We’re only using std::bitset for printing.

Given the following program:

#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags{ option_favorited };

    // Place all lines of code for the following quiz here

    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    return 0;
}
a) Add a line of code to set the article as viewed.
Expected output:

00000101
Hide Solution

myArticleFlags |= option_viewed;
b) Add a line of code to check if the article was deleted.

Hide Solution

if (myArticleFlags & option_deleted) ...
c) Add a line of code to clear the article as a favorite.
Expected output (Assuming you did quiz (a)):

00000001
Hide Solution

myArticleFlags &= static_cast<std::uint8_t>(~option_favorited);
If you got 00000000, check two things:

That the solution for quiz (a) has not been removed.
That you cleared option_favorited, not option_viewed.
1d) Extra credit: why are the following two lines identical?

myflags &= ~(option4 | option5); // turn options 4 and 5 off
myflags &= ~option4 & ~option5; // turn options 4 and 5 off
Hide Solution

De Morgan’s laws says that if we distribute a NOT, 
we need to flip ORs and ANDs to the other. So
 ~(option4 | option5) becomes ~option4 & ~option5.
*/