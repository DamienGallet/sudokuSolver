#pragma once

#include <vector>
#include "../Common.h"
using namespace std;

class Grid;
class Area;

class Cell {
public:
	Cell(int valueP, Grid * currentGridP, Area * currentRowP, Area * currentColP, Area * currentBlockP, int col, int row);
	int GetValue() {
		return value;
	};

	int GetScore() {
		UpdateScore();
		return score;
	};
	classUtilities::CellState GetState() {
		return state;
	};

	vector<int> CheckAvailable();
	void SetValue(int value);
	bool IsStuck();
	int UpdateScore();
	void Release();

protected:
	int value;
	int updateId;
	int score;

	Grid * currentGrid;
	Area * currentRow;
	Area * currentCol;
	Area * currentBlock;

	int col;
	int row;

	vector<int> numbersAvailable;
	int currentIndex;

	classUtilities::CellState state;
};