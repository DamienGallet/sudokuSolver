#pragma once

namespace gameConst {
	const int SIZE = 9;
	const int MAX_SCORE = SIZE+1;
	const int AREA_EMPTY = 511;
	const int NUMB_FREE = 1;
	const int NUMB_USED = 0;
}

namespace classUtilities {
	const enum AreaType { ROW, COL, BLOCK };
	const enum CellState { INITIALLY_FILLED, FILLED_IN_GAME, NOT_FILLED };
	const enum AreaState { UNCHECKED, CHECKED };
}