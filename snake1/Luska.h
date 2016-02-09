#pragma once
#include "Segment.h"

class Luska: public Segment
{
	friend class WazSingleton;
private:
	Luska* potomek;
public:
	Luska(int x, int y, float r, float g, float b) : Segment(x, y, r, g, b){ this->potomek = nullptr; };
	~Luska();
	int getTyp(void);
	void przesun(int x, int y);
};

