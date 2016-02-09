#include "Luska.h"
#include <iostream>
using namespace std;
Luska::~Luska()
{
	if(this->potomek != nullptr)
		delete this->potomek;
}

int Luska::getTyp(void)
{
	return 1;
}

void Luska::przesun(int x, int y)
{
	if (potomek != nullptr)
	{
		potomek->przesun(this->x, this->y);
		this->x = x;
		this->y = y;
	}
	else
	{
		this->x = x;
		this->y = y;
	}
}
