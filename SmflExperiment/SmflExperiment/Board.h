#include <vector> 
#include <string>
#include "Cell.h"
using std::vector;
using std::string;

//contains all cells 
class Board
{
private: 
	int length;
	int height;
	vector<vector<Cell*>> cells;
	void initializeCells();
	
public: 
	Board();
	Board(int);
	Board(int, int);
	void prepUpdate();
	void update();
	void print();
	void draw(RenderWindow&);
};