#include "PrzeszkodaSingleton.h"

PrzeszkodaSingleton::PrzeszkodaSingleton(int wariant, Mapa* mapa)
{
	this->mapa = mapa;
	this->zmienWariant(wariant);
}


PrzeszkodaSingleton::~PrzeszkodaSingleton()
{
	int size = this->przeszkodyVector.size();
	for (size = size - 1; size >= 0; size--)
		delete this->przeszkodyVector[size];
}

void PrzeszkodaSingleton::zmienWariant(int wariant)
{
	this->przeszkodyVector.clear();

	this->wariant = wariant;
	switch (wariant)
	{
	case 1:
	{
		//pierwszy kwadrat
		int x, y;
		for (x = 0; x < 8; x++)
			for (y = 0; y < 8; y++)
			{
			Przeszkoda* p = new Przeszkoda(5 + x, 35 + y, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			}
		//drugi kwadrat
		for (x = 0; x < 8; x++)
			for (y = 0; y < 8; y++)
			{
			Przeszkoda* p = new Przeszkoda(35 + x, 5 + y, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			}
		for (x = 0; x < 20; x++)
		{
			Przeszkoda* p = new Przeszkoda(14 + x, 24, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
		}
		break;
	}
	case 2:
	{
		//pierwszy kwadrat
		int x, y;
		for (x = 0; x < 8; x++)
			for (y = 0; y < 8; y++)
			{
			Przeszkoda* p = new Przeszkoda(5 + x, 35 + y, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			}
		//drugi kwadrat
		for (x = 0; x < 8; x++)
			for (y = 0; y < 8; y++)
			{
			Przeszkoda* p = new Przeszkoda(35 + x, 5 + y, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			}
		for (x = 0; x < 20; x++)
		{
			Przeszkoda* p = new Przeszkoda(14 + x, 24, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
		}
		for (x = 0; x < 14; x++)
		{
			Przeszkoda* p = new Przeszkoda(17 + x, 47, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(17 + x, 0, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(0, 17 + x, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(47, 17 + x, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
		}

		break;
	}
	case 3:
	{
		//pierwszy kwadrat
		int x, y;
		for (x = 0; x < 8; x++)
			for (y = 0; y < 8; y++)
			{
			Przeszkoda* p = new Przeszkoda(5 + x, 35 + y, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			}
		//drugi kwadrat
		for (x = 0; x < 8; x++)
			for (y = 0; y < 8; y++)
			{
			Przeszkoda* p = new Przeszkoda(35 + x, 5 + y, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			}
		for (x = 0; x < 20; x++)
		{
			Przeszkoda* p = new Przeszkoda(14 + x, 24, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(24, 14 + x, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
		}
		for (x = 0; x < 14; x++)
		{
			Przeszkoda* p = new Przeszkoda(17 + x, 47, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(17 + x, 0, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(0, 17 + x, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(47, 17 + x, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
		}
		break;
	}
	case 4:
	{
		//pierwszy kwadrat
		int x, y;
		for (x = 0; x < 8; x++)
			for (y = 0; y < 8; y++)
			{
			Przeszkoda* p = new Przeszkoda(5 + x, 35 + y, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			}
		//drugi kwadrat
		for (x = 0; x < 8; x++)
			for (y = 0; y < 8; y++)
			{
			Przeszkoda* p = new Przeszkoda(35 + x, 5 + y, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			}
		for (x = 0; x < 20; x++)
		{
			Przeszkoda* p = new Przeszkoda(14 + x, 24, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(24, 14 + x, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
		}
		for (x = 0; x < 48; x++)
		{
			Przeszkoda* p = new Przeszkoda(x, 47, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(x, 0, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(0, x, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
			p = new Przeszkoda(47, x, 1.0f, 0.3f, 0.3f);
			this->przeszkodyVector.push_back(p);
		}
		break;
	}
	}
}

void PrzeszkodaSingleton::generuj()
{
	int size = this->przeszkodyVector.size();
	for (size = size - 1; size >= 0; size--)
	{
		Przeszkoda* p = this->przeszkodyVector[size];
		this->mapa->setSegment(p, p->getXP(), p->getYP());
	}
	
}
