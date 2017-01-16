#pragma once

#include <set>
#include <bitset>
#include "../Common.h"
#include "Cell.h"

class Area {

public:
	Area(classUtilities::AreaType areaTypeP) : areaType(areaTypeP), occupation(0) {};
	virtual ~Area() {};

	bool AddCell(Cell * newCell);
	bool Check();
	// Definition : check if the row is valid
	// Param : None

	void Update(int newNumber);
	// Definition : Notice the area that newNumber is from now used by a cell
	// WARNING : Please note that no check is done at this step, you've to check before
	// if the number isn't already used by another cell

	bitset<size_t(gameConst::SIZE)> GetOccupation();

protected:
	set<Cell*> elements;
	bitset<size_t(gameConst::SIZE)> occupation;
	classUtilities::AreaType areaType;
	classUtilities::AreaState state;
};