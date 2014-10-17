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

void Game::run(RenderWindow& window)
{
	//creates the interval for each iteration 
	Time time = milliseconds(500);
	Clock clock;

	//while the window is open
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			//if the user closes the window
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		Time elapsed = clock.getElapsedTime();
		if (elapsed > time)
		{
			window.clear();

			//updates board
			board->draw(window);
			board->prepUpdate();
			board->update();

			window.display();

			clock.restart();
		}
	}
}