#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <GL/glew.h>
#include <iostream>

using namespace std;

class Display
{
public:
	Display(int, int, const string&);
	virtual ~Display();
	void Update();
	bool isClosed();
	void Clear(float r, float g, float b, float a);
private:
	Display(const Display& other){};
	void operator=(const Display& other){};

	SDL_Window* m_window;
	SDL_GLContext m_glContext;

	bool m_isClosed;
};

