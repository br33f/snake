#pragma once
class Segment
{
protected:
	int x, y;
	float r, g, b;
public:
	Segment(int x, int y, float r, float g, float b) : x(x), y(y), r(r), g(g), b(b) {};
	~Segment(void);
	virtual int getTyp(void);
	float getRS(void);
	float getGS(void);
	float getBS(void);
};

