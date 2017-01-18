#include "../../header/engine/Grid.h"
#include "../../header/engine/Area.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool CellComp(Cell * cellA, Cell * cellB) {
	return (cellA->GetScore() < cellB->GetScore());
}

Grid::Grid(vector<vector<int>> initialGrid) : 
		rows(gameConst::SIZE,nullptr),
		cols(gameConst::SIZE,nullptr),
		blocks(gameConst::SIZE,nullptr),
		grid(gameConst::SIZE,vector<Cell*>(gameConst::SIZE,nullptr))
	{

	// We load the grid thanks to the initial array composed of ints (0 : nothing, 1-9 initial val)
	// We translate that in an array of cells, and each cell has a reference to the grid, its row and its col

	bool valid = true;
	for (unsigned int row = 0; row < initialGrid.size(); row++) {
		Area * currentRow = GetRow(row);
		for (unsigned int col = 0; col < initialGrid[row].size(); col++) {
			Area * currentCol = GetCol(col);
			Area * currentBlock = GetBlock(row, col);
			Cell * newCell = new Cell(initialGrid[row][col], this, currentRow, currentCol, currentBlock,col,row);
			currentCol->AddCell(newCell);
			currentBlock->AddCell(newCell);
			currentRow->AddCell(newCell);

			if (newCell->GetState() == classUtilities::CellState::INITIALLY_FILLED) {
				initiallyFilled.push_back(newCell);
			}
			else {
				toFill.push_back(newCell);
			}
			grid[row][col] = newCell;
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


Area * Grid::GetRow(int rowNb) {
	if (rows[rowNb] == nullptr) {
		rows[rowNb] = new Area(classUtilities::AreaType::ROW);
	}
	return rows[rowNb];
}

Area * Grid::GetCol(int colNb) {
	if (cols[colNb] == nullptr) {
		cols[colNb] = new Area(classUtilities::AreaType::COL);
	}
	return cols[colNb];
}

Area * Grid::GetBlock(int rowNb, int colNb) {
	
	int colBlock = colNb / 3;
	int rowBlock = rowNb / 3;
	int blockNb = colBlock + rowBlock * 3;

	if (blocks[blockNb] == nullptr) {
		blocks[blockNb] = new Area(classUtilities::AreaType::BLOCK);
	}
	return blocks[blockNb];
}


void Grid::UpdateCellsList(Cell * lastModified) {
	lastModified->UpdateScore();
	UpdateCellsList();
}

void Grid::UpdateCellsList() {
	for (unsigned int i = 0; i < toFill.size(); i++) {
		toFill[i]->UpdateScore();
	}
	sort(toFill.begin(), toFill.end(), CellComp);
}

Cell * Grid::SeeNextCell() {
	UpdateCellsList();
	if (toFill.size() == 0) {
		return nullptr;
	}
	/*if (toFill[0]->GetScore() == gameConst::MAX_SCORE) {
	return nullptr;
	}*/
	Cell * nextCell = toFill[0];
	return nextCell;
}

void Grid::CatchNextCell() {
	toFill.erase(toFill.begin());
}

void Grid::ReleaseCell(Cell * cell) {
	toFill.push_back(cell);
	UpdateCellsList(cell);
}

bool Grid::ExploreNewNode(Cell * cell) {
	vector<int> availableNumbers = cell->CheckAvailable();
	if (availableNumbers.size() == 0) {
		return true;
	}
	for (	unsigned int currentNumberIndex = 0;
			currentNumberIndex < availableNumbers.size();
			currentNumberIndex++) {
		cell->SetValue(availableNumbers[currentNumberIndex]);
		Cell * next = SeeNextCell();
		if (next == nullptr) {
			return true;
		}
		if (next->IsStuck()) {
			cell->Release();
			return false;
		}
		else {
			CatchNextCell();
			if (ExploreNewNode(next)) {
				return true;
			}
			ReleaseCell(next);
		}
		cell->Release();
		
	}
	return false;
}

bool Grid::Play() {

	UpdateCellsList();
	if (toFill.size() > 0) {
		Cell * firstCell = SeeNextCell();
		CatchNextCell();
		bool res = ExploreNewNode(firstCell);
		Print();
		return res;
	}
	return true;
}

Grid::~Grid() {
	for (unsigned int i = 0; i < toFill.size(); i++) {
		delete toFill[i];
	}
	for (unsigned int i = 0; i < initiallyFilled.size(); i++) {
		delete initiallyFilled[i];
	}
	for (unsigned int i = 0; i < toFill.size(); i++) {
		delete toFill[i];
	}

	for (unsigned int i = 0; i < rows.size(); i++) {
		delete rows[i];
	}
	for (unsigned int i = 0; i < cols.size(); i++) {
		delete cols[i];
	}
	for (unsigned int i = 0; i < blocks.size(); i++) {
		delete blocks[i];
	}
}

void Grid::Print() {
	for (unsigned int row = 0; row < grid.size(); row++) {
		cout << "--";
		for (unsigned int col = 0; col < grid[row].size(); col++) {
			cout << grid[row][col]->GetValue() << " ";
		}
		cout << endl;
	}
}