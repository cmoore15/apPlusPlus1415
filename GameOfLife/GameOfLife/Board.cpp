#include "stdafx.h"
#include <iostream> 
#include "Board.h"
#include <vector> 
#include <string>
using std::vector;
using std::string;
using namespace std;

Board::Board()
{
	length = 10;
	height = 10;
}

Board::Board(int d)
{
	length = d;
	height = d;
}

Board::Board(int l, int h)
{
	length = l;
	height = h;
}

void Board::initializeCells()
{
	cells.resize(length);
	for(int i = 0; i < length; i++)
	{
		cells[i].resize(height);
		for(int j = 0; j < height; j++)
		{
			cells[i][j] = new Cell();
		}
	}
}

void Board::prepUpdate()
{
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < height; j++)
		{
			cells[i][j]->prepUpdate();
		}
	}
}

void Board::update()
{
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < height; j++)
		{
			cells[i][j]->update();
		}
	}
}

void Board::print()
{
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < height; j++)
		{
			cout << cells[i][j]->toString();
		}
		cout << endl;
	}
	cout << endl;
}