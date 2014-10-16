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
	Time time = milliseconds(500);
	Clock clock;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			/*else if (event.type == Event::KeyPressed)
			{
				window.clear();

			board->draw(window);
			board->prepUpdate();
			board->update();

			window.display();

			clock.restart();
			}*/
		}

		Time elapsed = clock.getElapsedTime();
		if (elapsed > time)
		{
			window.clear();

			board->draw(window);
			board->prepUpdate();
			board->update();

			window.display();

			clock.restart();
		}
	}

	/*string s = "";

	while(true)
	{
		//board->print();
		board->draw(window);
		board->prepUpdate();
		board->update();

		cin >> s;
		if(s == "quit")
		{
			break;
		}
	}*/
}