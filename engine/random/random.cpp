#include "random/random.h"

using namespace Betoneira;

// TODO: pseudorandom stuff with boost

int Random::randomInteger(int min, int max)
{
	return min + rand() % (max-min+1);
}

Color Random::randomColor(bool doAlpha)
{
    return Color(randomInteger(0, 255), randomInteger(0, 255), randomInteger(0, 255), randomInteger(0, 255) ? (doAlpha == true) : 255);
}