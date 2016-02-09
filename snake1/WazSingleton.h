#pragma once
#include "Luska.h"
#include "Mapa.h"
#include "Jedzenie.h"
#include <iostream>

class WazSingleton
{
private:
	Mapa* mapa;
	Jedzenie* jedzenie;
	Luska* head;
	Luska* tail;
	int score;
	int kierunek;
	int move(int kierunek);
public:
	WazSingleton(int x, int y, Mapa* mapa, Jedzenie* jedzenie);
	~WazSingleton();
	void update(int kierunek);
	void dodaj(int x, int y);
	void resetuj(void);
	int getScore(void);
	void setScore(int s);
};

