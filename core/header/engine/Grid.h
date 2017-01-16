#pragma once

#include <vector>

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

	bool UpdateCell(int row, int col, int newNb);
	bool UpdateCell(Cell * cell, int newNb);

	Area * GetRow(int rowNb);
	Area * GetCol(int colNb);
	Area * GetBlock(int rowNb, int colNb);

	bool CheckGrid();

protected :
	vector<vector<Cell *>> grid;
	vector<Area *> rows;
	vector<Area *> cols;
	vector<Area *> blocks;

private :
};