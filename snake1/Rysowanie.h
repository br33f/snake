#pragma once
#include "Display.h"
#include <GL/glew.h>
#include <glut.h>
#include "Mesh.h"
#include "Mapa.h"
#include "Segment.h"
#include "SnakeInterface.h"
#include <string>

using namespace std;

class Rysowanie
{
private:
	void rysujFrame();
	void rysujGameplay();
	void rysujNet();
	void rysujMenu();
	void rysujScore(int score);
	Mapa* mapa;
	SnakeInterface* ekran;
	Display* obiektRysujacy;
public:
	Rysowanie(int width, int height, string title);
	virtual ~Rysowanie();
	void rysuj(float r, float g, float b, float a, int score);
	bool isClosed();
	void loadMap(Mapa* m);
	void loadScreen(SnakeInterface* ekran);
	void drawText(string string, int x, int y, float r, float g, float b);
};

