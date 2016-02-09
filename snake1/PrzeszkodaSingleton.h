#pragma once
#include "Przeszkoda.h"
#include "Mapa.h"
#include <vector>

class PrzeszkodaSingleton
{
private:
	int wariant;
	Mapa* mapa;
	std::vector<Przeszkoda*> przeszkodyVector;
public:
	PrzeszkodaSingleton(int wariant, Mapa* mapa);
	~PrzeszkodaSingleton();
	void generuj();
	void zmienWariant(int wariant);
};

