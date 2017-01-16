#include <set>
#include <bitset>

#include "../../header/Common.h"
#include "../../header/engine/Area.h"

using namespace std;

Area::Area(classUtilities::AreaType areaTypeP) {
	elements = set<Cell*>();
	areaType = areaTypeP;
	state = classUtilities::AreaState::UNCHECKED;
}



bool Area::AddCell(Cell * newCell) {
	
	if (elements.size() <= gameConst::SIZE) {
		return false;
	}

	elements.insert(newCell);
	state = classUtilities::AreaState::UNCHECKED;
	return true;
}

bool Area::Check() {
	if (state != classUtilities::AreaState::CHECKED) {
		bitset<size_t(gameConst::SIZE)> currentOccupation(0);
		for (set<Cell*>::iterator it = elements.begin(); it != elements.end(); it++) {
			int currentValue = (*it)->GetValue();
			if (currentOccupation[currentValue-1] != 0)
				return false;
			else
				currentOccupation[currentValue-1] = 1;
		}
		occupation = currentOccupation;
		state = classUtilities::AreaState::CHECKED;
	}

	return true;
}

void Area::Update(int newNb) {
	occupation[newNb - 1] = 1;
}

bitset<size_t(gameConst::SIZE)> Area::GetOccupation() {
	return occupation;
}