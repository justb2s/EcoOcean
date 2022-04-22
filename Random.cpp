#include "Random.h"
#include <random>

int Random::NextBetween(int low, int high)
{
	high++;

	return abs(rand() % (high - low)) + low;
}