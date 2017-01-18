#pragma once

#include <vector>
#include <queue>
#include "Cell.h"
#include "Area.h"
#include "Grid.h"

using namespace std;

/* GRID CLASS : 
 * represent the game grid
 * Invariant :	the grid is always valid
 *				the grid maintains all the flags up to date
 */

class Grid {
public :
	Grid( vector<vector<int>> initialGrid );
	// Able to throw an exception "Invalid Grid"

	virtual ~Grid();

	bool UpdateCell(int row, int col, int newNb) {};
	bool UpdateCell(Cell * cell, int newNb) {};

	Area * GetRow(int rowNb);
	Area * GetCol(int colNb);
	Area * GetBlock(int rowNb, int colNb);

	bool CheckGrid();

	Cell * GetNextCell();
	void ReleaseCell(Cell * cell);
	bool ExploreNewNode(Cell * cell);
	void UpdateCellsList(Cell * lastModified);
	void UpdateCellsList();
	void Print();

	bool Play();

protected :
	vector<Cell *> toFill;
	vector<Cell *> initiallyFilled;
	vector<vector<Cell *>> grid;
	vector<Area *> rows;
	vector<Area *> cols;
	vector<Area *> blocks;

private :
};