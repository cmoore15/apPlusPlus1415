#include "Board.h"

//contains and runs all parts of the Game of Life 
class Game
{
private: 
	Board* board;

public:
	Game();
	Game(int);
	Game(int, int);
	void run(RenderWindow&);

};