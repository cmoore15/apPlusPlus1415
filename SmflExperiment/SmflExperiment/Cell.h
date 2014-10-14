#include <vector> 
#include <string>
using std::vector;
using std::string;

class Cell
{
private:
	bool val;
	bool next;
	vector<Cell*> neighbors;

public:
	Cell();
	Cell(bool);
	bool getVal();
	void setVal(bool);
	void addNeighbor(Cell*);
	void prepUpdate();
	void update();
	string toString();
};