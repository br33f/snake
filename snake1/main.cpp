#include <iostream>
#include <windows.h>
#include "Display.h"
#include <GL/glew.h>
#include "Mesh.h"
#include "Rysowanie.h"
#include "WazSingleton.h"
#include "Mapa.h"
#include "Jedzenie.h"
#include "PrzeszkodaSingleton.h"
#include "SnakeInterface.h"
#undef main﻿

using namespace std;

int main(int argc, char** argv)
{
	Rysowanie rysowanie(800, 800, "Snake v1.0b");
	Mapa* mapa = new Mapa();
	PrzeszkodaSingleton* przeszkody = new PrzeszkodaSingleton(1, mapa);
	Jedzenie* jedzenie = new Jedzenie(25, 20, 1.0, 1.0, 1.0, mapa);
	WazSingleton waz(10, 10, mapa, jedzenie);
	jedzenie->losuj();
	SnakeInterface* snakeInterface = new SnakeInterface();
	while (!rysowanie.isClosed())
	{
		//sterowanie
		int kierunek = 0;
		if (GetAsyncKeyState(VK_LEFT))
			kierunek = 1;
		if (GetAsyncKeyState(VK_UP))
			kierunek = 2;
		if (GetAsyncKeyState(VK_RIGHT))
			kierunek = 3;
		if (GetAsyncKeyState(VK_DOWN))
			kierunek = 4;
		if (GetAsyncKeyState(VK_ESCAPE))
			kierunek = 5;
		if (GetAsyncKeyState(VK_RETURN))
			kierunek = 6;

		//sprawdzenie przebiegu
		if (waz.getScore() < 0)
		{
			snakeInterface->setStatus(2);
			snakeInterface->looseScore = -waz.getScore();
			waz.setScore(10);
		}
		//wgrywanie mapy
		if (!snakeInterface->getStatus() && kierunek != 5 && snakeInterface->getStatus() != 2)
			waz.update(kierunek);
		else
		{
			snakeInterface->update(kierunek, &waz, jedzenie, przeszkody);
			Sleep(50);
		}
		przeszkody->generuj();
		jedzenie->generuj();
		rysowanie.loadMap(mapa);
		rysowanie.loadScreen(snakeInterface);
		
		//rysowanie
		rysowanie.rysuj(0.3, 0.3, 0.3, 1.0, waz.getScore());
		
		int szybkosc = 120; //100
		szybkosc -= 15 * (snakeInterface->getPoziomTrudnosci() - 1);
		Sleep(szybkosc);
	}
	delete mapa;

	return 0;
}