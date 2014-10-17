#include "stdafx.h"
#include <iostream> 
#include "Cell.h"
#include <vector> 
#include <string>
#include "Global.h"
using std::vector;
using std::string;

Cell::Cell(int x, int y)
{
	//default to dead
	val = false;
	next = false;
	rect = *(new RectangleShape(Vector2f(Global::getCellSize() - 1, Global::getCellSize() - 1)));
	rect.setOrigin(x, y);
	rect.setOutlineThickness(1);
	rect.setOutlineColor(Color(50, 50, 50));

	updateRect();
}

Cell::Cell(bool v, int x, int y)
{
	val = v;
	next = false;
	rect = *(new RectangleShape(Vector2f(Global::getCellSize() - 1, Global::getCellSize() - 1)));
	rect.setOrigin(x, y);
	rect.setOutlineThickness(1);
	rect.setOutlineColor(Color(50, 50, 50));

	updateRect();
}

bool Cell::getVal()
{
	return val;
}

void Cell::setVal(bool v)
{
	val = v;

	updateRect();
}

void Cell::addNeighbor(Cell* c)
{
	neighbors.push_back(c);
}

//finds the value for the next iteration 
void Cell::prepUpdate()
{
	int numAlive = 0;
	for(Cell* c : neighbors)
	{
		bool v = c->getVal();
		if(c->getVal())
		{
			numAlive++;
		}
	}

	if(numAlive <= 1)
	{
		next = false;
	}
	else if (numAlive <= 3)
	{
		next = true;
	}
	else
	{
		next = false;
	}
}

//updates the cell to the next itertation 
void Cell::update()
{
	val = next;

	updateRect();
}

//returns a string representation of the state, 1=true, 0=false 
string Cell::toString()
{
	if(val)
	{
		return "1";
	}
	else
	{
		return "0";
	}
	
}

RectangleShape Cell::getRectangle()
{
	return rect;
}

void Cell::draw(RenderWindow& window)
{
	window.draw(rect);
}

//changes the color of the rectangle to be the current value of the cell 
void Cell::updateRect()
{
	if (val)
	{
		rect.setFillColor(Color(100, 230, 120));
	}
	else
	{
		rect.setFillColor(Color(100, 100, 100));
	}
}