#include "stdafx.h"
#include <iostream> 
#include "Cell.h"
#include <vector> 
#include <string>
using std::vector;
using std::string;

Cell::Cell()
{
	val = false;
	next = false;
}

Cell::Cell(bool v)
{
	val = v;
	next = false;
}

bool Cell::getVal()
{
	return val;
}

void Cell::setVal(bool v)
{
	val = v;
}

void Cell::addNeighbor(Cell* c)
{
	neighbors.push_back(c);
}

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
	else if(numAlive <= 3)
	{
		next = true;
	}
	else
	{
		next = false;
	}
}

void Cell::update()
{
	val = next;
}

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
