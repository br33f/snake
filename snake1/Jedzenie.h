#pragma once
#include <cstdlib>
#include <ctime>
#include "Segment.h"
#include "Mapa.h"

class Jedzenie : public Segment
{
private:
	Mapa* mapa;
public:
	Jedzenie(int x, int y, float r, float g, float b, Mapa* mapa);
	~Jedzenie();
	int getTyp(void);
	void generuj(void);
	void losuj(void);
};

