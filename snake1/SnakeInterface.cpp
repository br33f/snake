#include "SnakeInterface.h"


SnakeInterface::SnakeInterface()
{
	this->clearEkran();
	this->status = 1;
	this->poziomTrudnosci = 1;
	this->mLevel = 1;
	this->looseScore = 10;
}


SnakeInterface::~SnakeInterface()
{
	int x, y;
	for (x = 0; x < 48; x++)
	{
		for (y = 0; y < 48; y++)
		{
			if (this->ekran[x][y] != nullptr)
				delete this->ekran[x][y];
		}
	}
}

void SnakeInterface::clearEkran(void)
{
	int x, y;
	for (x = 0; x < 48; x++)
	{
		for (y = 0; y < 48; y++)
		{
			this->ekran[x][y] = new Segment(x, y, 0.22f, 0.22f, 0.22f);
		}
	}
}

Segment* SnakeInterface::getEkran(int x, int y)
{
	return this->ekran[x][y];
}

int SnakeInterface::getStatus(void)
{
	return this->status;
}

void SnakeInterface::setStatus(int s)
{
	this->status = s;
}

int SnakeInterface::getPoziomTrudnosci(void)
{
	return this->poziomTrudnosci;
}

void SnakeInterface::setPoziomTrudnosci(int s)
{
	this->poziomTrudnosci = s;
}

void SnakeInterface::update(int kierunek, WazSingleton* waz, Jedzenie* jedzenie, PrzeszkodaSingleton* przeszkoda)
{

	//po zmianie poziomu trudnosci zresetwac licznik punktow
	//ustawic weza na poczatek
	//wygenerowac przeszkody
	//wylosowac jedzenie
	if (kierunek == 2)
	{
		if (this->mLevel > 1)
			this->mLevel--;
	}
	else if (kierunek == 4)
	{
		if (this->mLevel < 3)
			this->mLevel++;
	}
	else if (kierunek == 1)
	{
		if (mLevel == 2)
		{
			if (this->poziomTrudnosci > 1)
			{
				this->poziomTrudnosci--;
				waz->resetuj();
				przeszkoda->zmienWariant(this->poziomTrudnosci);
				przeszkoda->generuj();
				jedzenie->losuj();
			}
		}
	}
	else if (kierunek == 3)
	{
		if (mLevel == 2)
		{
			if (this->poziomTrudnosci < 4)
			{
				this->poziomTrudnosci++;
				waz->resetuj();
				przeszkoda->zmienWariant(this->poziomTrudnosci);
				przeszkoda->generuj();
				jedzenie->losuj();
			}
		}
	}
	else if (kierunek == 5)
	{
		if (this->getStatus() == 0)
		{
			this->mLevel = 1;
			this->setStatus(1);
		}
		
	}
	else if (kierunek == 6)
	{
		if (mLevel == 1)
		{
			
			if (this->getStatus() == 2)
			{
				waz->resetuj();
				przeszkoda->zmienWariant(this->poziomTrudnosci);
				przeszkoda->generuj();
				jedzenie->losuj();
			}
			this->setStatus(0);
		}
		else if (mLevel == 3)
			exit(1);
	}
}

int SnakeInterface::getMLevel(void)
{
	return this->mLevel;
}