#pragma once
#include "Segment.h"

class Przeszkoda : public Segment
{
public:
	Przeszkoda(int x, int y, float r, float g, float b);
	~Przeszkoda();
	int getTyp(void);
	int getXP(void);
	int getYP(void);
};
