#include "stdafx.h"

class Global
{
public: 
	static int getGridSize();
	static void setGridSize(int);
	static int getCellSize();
	static int getWindowSize();

private:
	static int gridSize;
	static const int CELL_SIZE = 15;
	static int windowSize;
};

