#include "Global.h"

int Global::gridSize = 21;
int Global::windowSize = 15 * 21;

void Global::setGridSize(int t)
{
	gridSize = t;
	windowSize = gridSize * CELL_SIZE;
}

int Global::getGridSize()
{
	if(gridSize == 0)
	{
		gridSize = 21;
	}
	return gridSize;
}

int Global::getCellSize()
{
	return CELL_SIZE;
}

int Global::getWindowSize()
{
	if(windowSize == 0)
	{
		windowSize = CELL_SIZE * getGridSize();
	}
	return windowSize;
}