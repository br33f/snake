#include "Rysowanie.h"


Rysowanie::Rysowanie(int width, int height, string title)
{
	obiektRysujacy = new Display(width, height, title);
	this->ekran = nullptr;
	this->mapa = nullptr;
}


Rysowanie::~Rysowanie()
{
	delete obiektRysujacy;
}

void Rysowanie::rysuj(float r, float g, float b, float a, int score)
{
	obiektRysujacy->Clear(r, g, b, a);
	glColor3f(0.4f, 0.6f, 1.0f);
	this->rysujFrame();
	if (this->ekran != nullptr && this->ekran->getStatus() != 0)
	{
		this->rysujMenu();
	}
	else
	{
		this->rysujGameplay();
		this->rysujNet();
	}
	this->rysujScore(score);
	obiektRysujacy->Update();
}

void Rysowanie::rysujFrame()
{
	//ramka
	Vertex frameVertices[] = { 
		//lewy
		Vertex(glm::vec3(-1.0, -1.0, 0)),
		Vertex(glm::vec3(-1.0, 1.0, 0)),
		Vertex(glm::vec3(-0.96, 1.0, 0)),
		Vertex(glm::vec3(-0.96, -1.0, 0)),

		//gora
		Vertex(glm::vec3(-1.0, 1.0, 0)),
		Vertex(glm::vec3(1.0, 1.0, 0)),
		Vertex(glm::vec3(1.0, 0.96, 0)),
		Vertex(glm::vec3(-1.0, 0.96, 0)),

		//prawy
		Vertex(glm::vec3(1.0, 1.0, 0)),
		Vertex(glm::vec3(1.0, -1.0, 0)),
		Vertex(glm::vec3(0.96, -1.0, 0)),
		Vertex(glm::vec3(0.96, 1.0, 0)),

		//dolny
		Vertex(glm::vec3(1.0, -1.0, 0)),
		Vertex(glm::vec3(-1.0, -1.0, 0)),
		Vertex(glm::vec3(-1.0, -0.96, 0)),
		Vertex(glm::vec3(1.0, -0.96, 0)),
	};
	Mesh frame(frameVertices, sizeof(frameVertices) / sizeof(frameVertices[0]));
	frame.Draw();
}

void Rysowanie::rysujGameplay()
{
	int x, y;
	glBegin(GL_QUADS);
	for (x = 0; x < 48; x++)
	{
		for (y = 0; y < 48; y++)
		{
			Segment* s = this->mapa->getSegment(x, y);
			if ( s != nullptr)
			{
				//cout << "x, y, s: " << x << ", " << y << ", " << s << endl;
				float x_offset, y_offset;
				x_offset = (float)(x*0.04);
				y_offset = (float)(y*0.04);
				glColor3f(s->getRS(), s->getGS(), s->getBS());
				glVertex3f(-0.96f + x_offset, 0.96f - y_offset, 0.0f);
				glVertex3f(-0.92f + x_offset, 0.96f - y_offset, 0.0f);
				glVertex3f(-0.92f + x_offset, 0.92f - y_offset, 0.0f);
				glVertex3f(-0.96f + x_offset, 0.92f - y_offset, 0.0f);
			}

		}
	}
	glEnd();
}

void Rysowanie::rysujNet()
{
	glColor3f(0.25, 0.25, 0.25);
	float wsp = 0.0;
	glBegin(GL_QUADS);
	while (wsp < 1.88)
	{
		//poziom
		glVertex3f(-0.96f, (float)-0.92 + wsp, 0.0f);
		glVertex3f(0.96f, (float)-0.92 + wsp, 0.0f);
		glVertex3f(0.96f, (float)-0.918 + wsp, 0.0f);
		glVertex3f(-0.96f, (float)-0.918 + wsp, 0.0f);

		//pion
		glVertex3f((float)-0.92f + wsp, (float)-0.96, 0.0f);
		glVertex3f((float)-0.92f + wsp, (float) 0.96, 0.0f);
		glVertex3f((float)-0.918f + wsp, (float)0.96f, 0.0f);
		glVertex3f((float)-0.918f + wsp, (float)-0.96f, 0.0f);

		wsp += 0.04f;
	}
	glEnd();
}

void Rysowanie::rysujScore(int score)
{
	string str2 = to_string(score);
	string s = "SCORE: " + str2;
	this->drawText(s, 15, 4, 1.0, 1.0, 1.0);
}

void Rysowanie::rysujMenu()
{
	int x, y;
	glBegin(GL_QUADS);
	for (x = 0; x < 48; x++)
	{
		for (y = 0; y < 48; y++)
		{
			Segment* s = this->ekran->getEkran(x, y);
			if (s != nullptr)
			{
				//cout << "x, y, s: " << x << ", " << y << ", " << s << endl;
				float x_offset, y_offset;
				x_offset = (float)(x*0.04);
				y_offset = (float)(y*0.04);
				glColor3f(s->getRS(), s->getGS(), s->getBS());
				glVertex3f(-0.96f + x_offset, 0.96f - y_offset, 0.0f);
				glVertex3f(-0.92f + x_offset, 0.96f - y_offset, 0.0f);
				glVertex3f(-0.92f + x_offset, 0.92f - y_offset, 0.0f);
				glVertex3f(-0.96f + x_offset, 0.92f - y_offset, 0.0f);
			}

		}
	}
	glEnd();


	//score
	if (this->ekran->getStatus() == 2)
	{
		string str2 = to_string(this->ekran->looseScore);
		string s = "GAMEOVER: " + str2;
		this->drawText(s, 300, 500, 1.0, 0.0, 0.0);
	}

	string str3 = to_string(this->ekran->getPoziomTrudnosci());

	string s2 = "POZIOM TRUDNOSCI < " + str3 + " >";
	float kolory[4][3];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			if (ekran->getMLevel() == i)
				kolory[i][j] = 0.5;
			else
				kolory[i][j] = 1.0;
		}
	this->drawText("MENU", 300, 440, kolory[0][0], kolory[0][1], kolory[0][2]);
	this->drawText("GRAJ", 300, 410, kolory[1][0], kolory[1][1], kolory[1][2]);
	this->drawText(s2, 300, 390, kolory[2][0], kolory[2][1], kolory[2][2]);
	this->drawText("WYJDZ", 300, 370, kolory[3][0], kolory[3][1], kolory[3][2]);
}

bool Rysowanie::isClosed()
{
	return obiektRysujacy->isClosed();
}

void Rysowanie::loadMap(Mapa* mapa)
{
	this->mapa = mapa;
}

void Rysowanie::loadScreen(SnakeInterface* ekran)
{
	this->ekran = ekran;
}

void Rysowanie::drawText(string string, int x, int y, float r, float g, float b)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 800, 0.0, 800);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(r, g, b);

	glRasterPos2i(x, y);
	void * font = GLUT_BITMAP_9_BY_15;
	for (unsigned int i = 0; i < string.size(); i++)
	{
		char c = string[i];
		glutBitmapCharacter(font, c);
	}

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}