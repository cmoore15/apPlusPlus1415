#include "Board.h"

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