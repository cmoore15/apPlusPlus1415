// SmflExperiment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream> 
#include <string>
#include "Reference.h"
#include "Global.h"
using namespace std;
using namespace sf;
using std::string;

//TODO: look at http://stackoverflow.com/questions/3563756/fatal-error-lnk1112-module-machine-type-x64-conflicts-with-target-machine-typ
//				http://sfml-dev.org/tutorials/2.1/start-vc.php 

int _tmain(int argc, _TCHAR* argv[])
{
	/*cout << "How large would you like the grid? ";
	int size;
	cin >> size;
	cout << endl;

	Game* game = new Game(size);
	game->run();

	int c;
	cin >> c;

	return 0;*/

	RenderWindow window(VideoMode(Global::WINDOW_SIZE, Global::WINDOW_SIZE), "Game of Life");

	Game* game = new Game(Global::GRID_SIZE);
	game->run(window);

    /*CircleShape shape(90.f);
	shape.setFillColor(Color(100, 230, 120));
	shape.setOrigin(-10, -10);
	shape.setOutlineThickness(10);
	shape.setOutlineColor(Color(100, 100, 100));

	RectangleShape rect(Vector2f(200, 200));
	rect.setFillColor(Color(100, 50, 200));

	CircleShape shape2(50.f);
	shape2.setFillColor(Color(0, 30, 255));
	shape2.setOrigin(-250, -50);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
		window.draw(rect);
        window.draw(shape);
		window.draw(shape2);
        window.display();
    }*/

    return 0;
}

