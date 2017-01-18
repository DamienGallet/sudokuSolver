#pragma once

#include <set>
#include <bitset>
#include "../Common.h"
#include "Cell.h"

using namespace std;

class Area {

public:
	Area(classUtilities::AreaType areaTypeP);
	virtual ~Area() {};

	bool AddCell(Cell * newCell);
	bool Check();
	// Definition : check if the row is valid
	// Param : None

	void Update(int newNumber);
	// Definition : Notice the area that newNumber is from now used by a cell
	// WARNING : Please note that no check is done at this step, you've to check before
	// if the number isn't already used by another cell

	void Release(int numberToRelease);

	uint64_t GetOccupation();

protected:
	set<Cell*> elements;
	uint64_t occupation;
	classUtilities::AreaType areaType;
	classUtilities::AreaState state;
};