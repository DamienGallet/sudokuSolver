#include <gtest\gtest.h>
#include "../../../core/header/engine/Area.h"
#include "../../../core/header/Common.h"

TEST(Area, EmptyCheck) {
	// Given
	Area* area = new Area(classUtilities::AreaType::ROW);

	EXPECT_EQ(area->Check(), true);
}

TEST(Area, SimpleWrongCheck) {
	Area* area = new Area(classUtilities::AreaType::ROW);
	Cell* cell1 = new Cell(1, nullptr, nullptr, nullptr, nullptr,0,0);
	Cell* cell2 = new Cell(1, nullptr, nullptr, nullptr, nullptr,0,0);

	area->AddCell(cell1);
	area->AddCell(cell2);

	EXPECT_EQ(area->Check(), false);
}