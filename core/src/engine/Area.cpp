#include <set>
#include <bitset>
#include <iostream>

#include "../../header/Common.h"
#include "../../header/engine/Area.h"

using namespace std;

Area::Area(classUtilities::AreaType areaTypeP) {
	areaType = areaTypeP;
	state = classUtilities::AreaState::UNCHECKED;
}



bool Area::AddCell(Cell * newCell) {

	if (elements.size() > gameConst::SIZE) {
		return false;
	}

	elements.insert(newCell);
	state = classUtilities::AreaState::UNCHECKED;
	return true;
}

bool Area::Check() {
	if (state != classUtilities::AreaState::CHECKED) {
		bitset<size_t(gameConst::SIZE)> currentOccupation(gameConst::AREA_EMPTY);
		for (set<Cell*>::iterator it = elements.begin(); it != elements.end(); it++) {
			int currentValue = (*it)->GetValue();
			if (currentValue == 0) {
				continue;
			}
			if (currentOccupation[currentValue-1] == gameConst::NUMB_USED)
				return false;
			else
				currentOccupation[currentValue-1] = gameConst::NUMB_USED;
		}

		occupation = currentOccupation.to_ulong();
		state = classUtilities::AreaState::CHECKED;
	}

	return true;
}

void Area::Release(int numberToRelease) {
	bitset<gameConst::SIZE> occupationBitSet(occupation);
	occupationBitSet[numberToRelease - 1] = gameConst::NUMB_FREE;
	occupation = occupationBitSet.to_ulong();
}

void Area::Update(int newNb) {
	bitset<gameConst::SIZE> occupationBitSet(occupation);
	occupationBitSet[newNb - 1] = gameConst::NUMB_USED;
	occupation = occupationBitSet.to_ulong();
}

uint64_t Area::GetOccupation() {
	return occupation;
}