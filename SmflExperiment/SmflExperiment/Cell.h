#include <vector> 
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
using std::vector;
using std::string;

class Cell
{
private:
	bool val;
	bool next;
	vector<Cell*> neighbors;
	RectangleShape rect;
	void updateRect();

public:
	Cell(int, int);
	Cell(bool, int, int);
	bool getVal();
	void setVal(bool);
	void addNeighbor(Cell*);
	void prepUpdate();
	void update();
	string toString();
	RectangleShape getRectangle();
	void draw(RenderWindow&);
};