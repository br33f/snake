#pragma once
#include "Segment.h"
#include "Przeszkoda.h"

class Mapa
{
private:
	Segment* m[48][48];
public:
	Mapa();
	~Mapa();
	Segment* getSegment(int x, int y);
	void setSegment(Segment* s, int x, int y);
	void zerujMape();
};

