#include "WazSingleton.h"


WazSingleton::WazSingleton(int x, int y, Mapa* mapa, Jedzenie* jedzenie)
{
	this->head = new Luska(x, y, 0.0f, 1.0f, 0.0f);
	Luska* p = this->head;
	this->tail = nullptr;
	this->kierunek = 3;
	this->mapa = mapa;
	this->jedzenie = jedzenie;
	this->score = 10;
}


WazSingleton::~WazSingleton()
{
	delete this->head;
}

void WazSingleton::update(int kierunek)
{

	int status = this->move(kierunek);

		//aktualizacja tabeli
		this->mapa->zerujMape(); //zeruje mape
		Luska* p = this->head;
		while (p)
		{
			this->mapa->setSegment(p, p->x, p->y);
			//przesuniecie
			p = p->potomek;
		}
}

int WazSingleton::move(int kierunek)
{
	if (kierunek > 0 && kierunek < 5 && (this->kierunek == kierunek || this->kierunek%2 != kierunek%2))
		this->kierunek = kierunek;
	int destination_x, destination_y;
	destination_x = this->head->x;
	destination_y = this->head->y;
	switch (this->kierunek)
	{
	case 1:
		destination_x--;
		break;
	case 2:
		destination_y--;
		break;
	case 3:
		destination_x++;
		break;
	case 4:
		destination_y++;
		break;
	}

	//zawijanie
	if (destination_x == 48) destination_x = 0;
	else if (destination_x == -1) destination_x = 47;
	if (destination_y == 48) destination_y = 0;
	else if (destination_y == -1) destination_y = 47;

	//akcje
	Segment* el = this->mapa->getSegment(destination_x, destination_y);
	if (el != nullptr) 
	{
		if (el->getTyp() == 2)
		{
			this->dodaj(destination_x, destination_y);
			this->jedzenie->losuj();
			this->setScore(this->getScore() + 10);
			return 2;
		}
		if (el->getTyp() == 1 || el->getTyp() == 3)
		{
			this->setScore(-this->getScore());
			return 1;
		}
		
	}
	//if (0) // warunek przeszkody return 0
	//else
	this->head->przesun(destination_x, destination_y);
	return 0;
}

void WazSingleton::dodaj(int x, int y)
{
	Luska* nowa = new Luska(x, y, 0.0f, 1.0f, 0.0f);
	nowa->potomek = this->head;
	this->head->r = 1.0f;
	this->head->g = 1.0f;
	this->head->b = 1.0f;
	this->head = nowa;
}

void WazSingleton::resetuj(void)
{
	delete this->head->potomek;
	this->head->potomek = nullptr;
	this->head->przesun(10, 10);
	this->setScore(10);
}

int WazSingleton::getScore(void)
{
	return this->score;
}

void WazSingleton::setScore(int s)
{
	this->score = s;
}