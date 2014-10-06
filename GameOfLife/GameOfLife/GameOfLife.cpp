// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream> 
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Game* game = new Game(5);
	game->run();

	int c;
	cin >> c;

	return 0;
}

