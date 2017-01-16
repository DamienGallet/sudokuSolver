#include "../../header/engine/Grid.h"
#include "../../header/engine/Area.h"

using namespace std;

Grid::Grid(vector<vector<int>> initialGrid) {

	// We load the grid thanks to the initial array composed of ints (0 : nothing, 1-9 initial val)
	// We translate that in an array of cells, and each cell has a reference to the grid, its row and its col
	bool valid = true;
	for (int row = 0; row < initialGrid.size(); row++) {
		Area * currentRow = GetRow(row);
		for (int col = 0; col < initialGrid[row].size(); col++) {
			Area * currentCol = GetCol(col);
			Area * currentBlock = GetBlock(row, col);
			Cell * newCell = new Cell(initialGrid[row][col], this, currentRow, currentCol, currentBlock);
			currentCol->AddCell(newCell);
			currentBlock->AddCell(newCell);
			currentRow->AddCell(newCell);
		}
	}

	valid = CheckGrid();

	if (!valid) {
		throw exception("Invalid grid");
	}
}

bool Grid::CheckGrid() {
	
	for (unsigned int row = 0; row < rows.size(); row++) {
		if (!rows[row]->Check())
			return false;
	}

	for (unsigned int col = 0; col < cols.size(); col++) {
		if (!cols[col]->Check())
			return false;
	}

	for (unsigned int block = 0; block < blocks.size(); block++) {
		if (!blocks[block]->Check())
			return false;
	}

	return true;
}