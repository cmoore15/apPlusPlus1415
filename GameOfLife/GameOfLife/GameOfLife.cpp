// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream> 
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "How large would you like the grid? ";
	int size;
	cin >> size;
	cout << endl;

	Game* game = new Game(size);
	game->run();

	int c;
	cin >> c;

	return 0;
}

