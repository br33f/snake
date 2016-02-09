#pragma once
#include "Segment.h"
#include "WazSingleton.h"
#include "Jedzenie.h"
#include "PrzeszkodaSingleton.h"

using namespace std;

class SnakeInterface
{
private:
	Segment* ekran[48][48];
	int status;
	int poziomTrudnosci;
	int mLevel;
public:
	SnakeInterface();
	~SnakeInterface();
	void clearEkran();
	Segment* getEkran(int x, int y);
	int getStatus(void);
	void setStatus(int s);
	int getPoziomTrudnosci(void);
	void setPoziomTrudnosci(int s);
	int getMLevel(void);
	void update(int kierunek, WazSingleton* waz, Jedzenie* jedzenie, PrzeszkodaSingleton* przeszkoda);
	int looseScore;
};

