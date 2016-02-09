#include "Jedzenie.h"

Jedzenie::Jedzenie(int x, int y, float r, float g, float b, Mapa* mapa) : Segment(x, y, r, g, b)
{
	this->mapa = mapa;
}

Jedzenie::~Jedzenie()
{
}

int Jedzenie::getTyp()
{
	return 2;
}

void Jedzenie::generuj()
{
	this->mapa->setSegment(this, x, y);
}

void Jedzenie::losuj()
{
	srand((unsigned int)time(NULL));

	int x = std::rand() % 47;
	int y = std::rand() % 47;

	while (this->mapa->getSegment(x, y) != nullptr)
	{
		x = std::rand() % 47;
		y = std::rand() % 47;
	}

	this->x = x;
	this->y = y;
}