#pragma once

namespace gameConst {
	extern const int SIZE;
}

namespace classUtilities {
	const enum AreaType { ROW, COL, BLOCK };
	const enum CellState { INITIALLY_FILLED, FILLED_IN_GAME, NOT_FILLED };
	const enum AreaState { UNCHECKED, CHECKED };
}