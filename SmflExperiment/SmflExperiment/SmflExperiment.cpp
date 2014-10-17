// SmflExperiment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream> 
#include <string>
#include "Global.h"
using namespace std;
using namespace sf;
using std::string;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "How large do you want the grid? " << endl;

	int size;
	cin >> size;
	Global::setGridSize(size);

	RenderWindow window(VideoMode(Global::getWindowSize(), Global::getWindowSize()), "Game of Life");

	Game* game = new Game(Global::getGridSize());
	game->run(window);

    return 0;
}

