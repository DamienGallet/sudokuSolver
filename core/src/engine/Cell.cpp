#include "../../header/engine/Cell.h"
#include <iostream>

using namespace std;

Cell::Cell(int valueP, Grid * currentGridP, Area * currentRowP, Area * currentColP, Area * currentBlockP) :
	value(valueP),
	updateId(-1),
	currentBlock(currentBlockP),
	currentCol(currentColP),
	currentGrid(currentGridP) 
{
	if (valueP == 0) {
		state = classUtilities::CellState::NOT_FILLED;
	}
	else if (valueP > 0 && valueP <= gameConst::SIZE) {
		state = classUtilities::CellState::INITIALLY_FILLED;
	}
	else {
		throw exception("Invalid cell");
	}
}