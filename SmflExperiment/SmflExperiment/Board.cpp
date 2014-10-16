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
	initializeCells();
}

Board::Board(int d)
{
	length = d;
	height = d;
	initializeCells();
}

Board::Board(int l, int h)
{
	length = l;
	height = h;
	initializeCells();
}

void Board::initializeCells()
{
	cells.resize(length);
	for(int i = 0; i < length; i++)
	{
		cells[i].resize(height);
		for(int j = 0; j < height; j++)
		{
			if(j == 10 || i == 10)
			{
				cells[i][j] = new Cell(true, i * -15, j * -15);
			}
			else
			{
				cells[i][j] = new Cell(false, i * -15, j * -15);
			}
		}
	}

	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < height; j++)
		{
			bool left = (i+1)<length;
			bool right = (i-1)>=0;
			bool down = (j-1)>=0;
			bool up = (j+1)<length;

			if(right) cells[i][j]->addNeighbor(cells[i-1][j]);
			if(left) cells[i][j]->addNeighbor(cells[i+1][j]);
			if(up) cells[i][j]->addNeighbor(cells[i][j+1]);
			if(down) cells[i][j]->addNeighbor(cells[i][j-1]);

			if(right && up) cells[i][j]->addNeighbor(cells[i-1][j+1]);
			if(right && down) cells[i][j]->addNeighbor(cells[i-1][j-1]);

			if(left && up) cells[i][j]->addNeighbor(cells[i+1][j+1]);
			if(left && down) cells[i][j]->addNeighbor(cells[i+1][j-1]);
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

void Board::draw(RenderWindow& window)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cells[i][j]->draw(window);
		}
	}
}