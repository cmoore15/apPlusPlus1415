// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream> 
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using std::string;


int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
	
	/*cout << "How large would you like the grid? ";
	int size;
	cin >> size;
	cout << endl;

	Game* game = new Game(size);
	game->run();

	int c;
	cin >> c;

	return 0;*/
}

