#include "Mapa.h"


Mapa::Mapa()
{
	int x, y;
	for (x = 0; x < 48; x++)
	{
		for (y = 0; y < 48; y++)
		{
			this->m[x][y] = nullptr;
		}
	}
}


Mapa::~Mapa()
{
}

Segment* Mapa::getSegment(int x, int y)
{
	return this->m[x][y];
}

void Mapa::setSegment(Segment* s, int x, int y)
{
	this->m[x][y] = s;
}

void Mapa::zerujMape()
{
	int x, y;
	for (x = 0; x < 48; x++)
	{
		for (y = 0; y < 48; y++)
		{
			this->m[x][y] = nullptr;
		}
	}
}
