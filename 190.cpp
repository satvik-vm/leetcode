#include <iostream>
#include <cstdint>
#define SIZE 32

using namespace std;

uint32_t reverseBits(uint32_t n)
{
	uint32_t answer = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (n & (1 << i))
		{
			answer = answer | (1 << (SIZE - i - 1));
		}
	}
	return answer;
}