#include "../../header/engine/Utilities.h"
#include <stdint.h>

const uint64_t m1 = 0x5555555555555555;
const uint64_t m2 = 0x3333333333333333;
const uint64_t m4 = 0x0f0f0f0f0f0f0f0f;

int hammingWeight(uint64_t x)
{
	x -= (x >> 1) & m1;
	x = (x & m2) + ((x >> 2) & m2);
	x = (x + (x >> 4)) & m4;
	x += x >> 8;
	x += x >> 16;
	x += x >> 32;
	return x & 0x7f;
}