#include "Przeszkoda.h"

Przeszkoda::Przeszkoda(int x, int y, float r, float g, float b) : Segment(x, y, r, g, b)
{
}

Przeszkoda::~Przeszkoda()
{
}

int Przeszkoda::getTyp()
{
	return 3;
}

int Przeszkoda::getXP(void)
{
	return this->x;
}
int Przeszkoda::getYP(void)
{
	return this->y;
}