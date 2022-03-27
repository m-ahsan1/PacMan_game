#include "mygraphics.h"
#include <iostream>
using namespace std;

class map
{
private:
	//boundary coordinates
	int top1x, top1y;
	int top2x, top2y;
	int bot1x, bot1y; // rix, riy, lix, liy;
	int bot2x, bot2y;

public:
	map()
	{

	}
	map(int t1x, int t1y, int t2x, int t2y, int b1x, int b1y, int b2x, int b2y)
	{
		// top points 
		top1x = t1x;
		top1y = t1y;
		top2x = t2x;
		top2y = t2y;
		// bottom points

		bot1x = b1x;
		bot1y = b1y;
		bot2x = b2x;
		bot2y = b2y;
	}
	void displayBoundary()							
	{
		//boundaries
		drawLine(top1x, top1y, top2x, top2y, 0, 0, 255); //top
		drawLine(bot1x, bot1y, bot2x, bot2y, 0, 0, 255); //bottom
		drawLine(top1x, top1y, bot1x, bot1y, 0, 0, 255); //left
		drawLine(top2x, top2y, bot2x, bot2y,0, 0, 255); //right


	}
	void displayObs()               //obstacles
	{
		int ob1x=( ((top2x - top1x) / 2)/2 )+top1x;
		//y1 // (top)
		int y = top1y + 120;

		int ob2x = (((top2x - top1x) / 2) / 2) + top1x;
		int ob1y = top1y;
		//mid obs
		drawLine(((top2x - top1x) / 2 ) + top1x, top1y, ((top2x - top1x) / 2) + top1x, top1y + 150, 0, 0, 255);
		drawLine(((bot2x - bot1x) / 2 ) + bot1x, bot1y, ((bot2x - bot1x) / 2) + bot1x, bot1y - 150, 0, 0, 255);

		//side obs
		drawLine((((top2x - top1x) / 2) / 2) + top1x, top1y + 120, (((top2x - top1x) / 2) / 2) + top1x, top1y + 220, 0, 0, 255);
		drawLine((((top2x - top1x) / 2) / 2) + top1x +257, top1y + 120, (((top2x - top1x) / 2) / 2) + top1x + 257, top1y + 220, 0, 0, 255);

		
	}

	void displayFood()
	{
		//yahan food display karlen ge bad me
	}

	~map()
	{

	}
}; 

class PacMan : public map
{
private:
	int px;
	int py;

public:
	PacMan()
	{
		px = 0;
		py = 0;
	}

	void DrawPacMan()
	{
		int w = 0;
		drawEllipse(10 * px + 0, py + 0, 10 * px + 25, py + 25, 0, 0, 0, 255, 255, 0);
		delay(10);
		drawEllipse(10 * px + 0, py + 0, 10 * px + 25, py + 25, 0, 0, 0, 0, 0, 0);

		px++;
		if (10 * px > w) px = 0;

		char c = getKey();

		if (c == 'q') 

		if (c == 's') px = 0;

		if (c == 'k') py += 10;

		if (c == 'i') py -= 10;
	}
	~PacMan()
	{

	}

};

class Ghost1
{
private:
public:
	Ghost1()
	{

	}

};

class Ghost2
{
private:
public:

};

int main() {

	//// Initialising
	int w = 0, h = 0;
	getWindowDimensions(w, h);

	cls();
	showConsoleCursor(false);
	map M(535, 125, 1050, 125, 535, 545, 1050, 545);
	PacMan P;
	int i = 0, j = 0;
	while (true)
	{
		
		M.displayBoundary();
		M.displayObs();
		P.DrawPacMan();
		
	}


	return 0;
}

