#pragma once

#include "../Common.h"

class Grid;
class Area;

class Cell {
public:
	Cell(int valueP, Grid * currentGridP, Area * currentRowP, Area * currentColP, Area * currentBlockP);
	int GetValue();

protected:
	int value;
	int updateId;

	Grid * currentGrid;
	Area * currentRow;
	Area * currentCol;
	Area * currentBlock;

	classUtilities::CellState state;
};