#include "stdafx.h"
#include <iostream> 
#include "Game.h"
#include <string>
using std::string;
using namespace std;


Game::Game()
{
	board = new Board();
}

Game::Game(int d)
{
	board = new Board(d);
}

Game::Game(int l, int h)
{
	board = new Board(l, h);
}

void Game::run()
{
	string s = "";

	board->print();
	while(true)
	{
		board->prepUpdate();
		board->update();
		board->print();

		cin >> s;
		if(s == "quit")
		{
			break;
		}
	}
}