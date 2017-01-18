#include "../../header/engine/Cell.h"
#include "../../header/Common.h"
#include "../../header/engine/Utilities.h"
#include "../../header/engine/Area.h"
#include <iostream>
#include <bitset>
#include <stdint.h>

using namespace std;

Cell::Cell(int valueP, Grid * currentGridP, Area * currentRowP, Area * currentColP, Area * currentBlockP, int colP, int rowP) :
	value(valueP),
	updateId(-1),
	currentBlock(currentBlockP),
	currentCol(currentColP),
	currentGrid(currentGridP),
	currentRow(currentRowP),
	currentIndex(-1)
{
	col = colP;
	row = rowP;
	
	if (valueP == 0) {
		state = classUtilities::CellState::NOT_FILLED;
		score = 1;
	}
	else if (valueP > 0 && valueP <= gameConst::SIZE) {
		state = classUtilities::CellState::INITIALLY_FILLED;
	}
	else {
		throw exception("Invalid cell");
	}
}

vector<int> Cell::CheckAvailable() {
	uint64_t rowEq = currentRow->GetOccupation();
	uint64_t colEq = currentCol->GetOccupation();
	uint64_t blockEq = currentBlock->GetOccupation();

	uint64_t remaining = rowEq & colEq & blockEq;

	bitset<gameConst::SIZE> availableBitSet = remaining;

	numbersAvailable.clear();
	for (int i = 0; i < gameConst::SIZE; i++) {
		if (availableBitSet[i] == gameConst::NUMB_FREE) {
			numbersAvailable.push_back(i + 1);
		}
	}

	return numbersAvailable;
}

void Cell::Release() {
	state = classUtilities::CellState::NOT_FILLED;

	currentBlock->Release(value);
	currentCol->Release(value);
	currentRow->Release(value);

	value = 0;
	currentIndex = -1;
}

void Cell::SetValue(int valueP) {
	
	value = valueP;
	state = classUtilities::CellState::FILLED_IN_GAME;

	currentRow->Update(value);
	currentCol->Update(value);
	currentBlock->Update(value);

	score = gameConst::MAX_SCORE;
}

int Cell::UpdateScore() {
	uint64_t rowEq = currentRow->GetOccupation();
	uint64_t colEq = currentCol->GetOccupation();
	uint64_t blockEq = currentBlock->GetOccupation();

	uint64_t remaining = rowEq & colEq & blockEq;

	score = hammingWeight(remaining);

	return score;
}

bool Cell::IsStuck() {
	if (score == 0) {
		return true;
	}
	else {
		return false;
	}
}

