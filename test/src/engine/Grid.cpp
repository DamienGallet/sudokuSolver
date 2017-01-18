#include <gtest\gtest.h>
#include <iostream>
#include "../../core/header/engine/Grid.h"

#define private public
#define protected public

using namespace std;

Grid * getZeroGrid() {
	static const int line1[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line2[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line3[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line4[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line5[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line6[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line7[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line8[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line9[] = { 0,0,0,0,0,0,0,0,0 };
	vector<vector<int>> expectedGrid(1, vector<int>(line1, line1 + sizeof(line1) / sizeof(line1[0])));
	expectedGrid.push_back(vector<int>(line2, line2 + sizeof(line2) / sizeof(line2[0])));
	expectedGrid.push_back(vector<int>(line3, line3 + sizeof(line3) / sizeof(line3[0])));
	expectedGrid.push_back(vector<int>(line4, line4 + sizeof(line4) / sizeof(line4[0])));
	expectedGrid.push_back(vector<int>(line5, line5 + sizeof(line5) / sizeof(line5[0])));
	expectedGrid.push_back(vector<int>(line6, line6 + sizeof(line6) / sizeof(line6[0])));
	expectedGrid.push_back(vector<int>(line7, line7 + sizeof(line7) / sizeof(line7[0])));
	expectedGrid.push_back(vector<int>(line8, line8 + sizeof(line8) / sizeof(line8[0])));
	expectedGrid.push_back(vector<int>(line9, line9 + sizeof(line9) / sizeof(line9[0])));

	return new Grid(expectedGrid);
}

TEST(GridCheck, GoodGrid) {
	static const int line1[] = { 1,2,3,4,5,6,7,8,9 };
	static const int line2[] = { 4,5,6,7,8,9,1,2,3 };
	static const int line3[] = { 7,8,9,1,2,3,4,5,6 };
	static const int line4[] = { 2,3,4,5,6,7,8,9,1 };
	static const int line5[] = { 5,6,7,8,9,1,2,3,4 };
	static const int line6[] = { 8,9,1,2,3,4,5,6,7 };
	static const int line7[] = { 3,4,5,6,7,8,9,1,2 };
	static const int line8[] = { 6,7,8,9,1,2,3,4,5 };
	static const int line9[] = { 9,1,2,3,4,5,6,7,8 };
	vector<vector<int>> expectedGrid(1, vector<int>(line1, line1 + sizeof(line1) / sizeof(line1[0])));
	expectedGrid.push_back(vector<int>(line2, line2 + sizeof(line2) / sizeof(line2[0])));
	expectedGrid.push_back(vector<int>(line3, line3 + sizeof(line3) / sizeof(line3[0])));
	expectedGrid.push_back(vector<int>(line4, line4 + sizeof(line4) / sizeof(line4[0])));
	expectedGrid.push_back(vector<int>(line5, line5 + sizeof(line5) / sizeof(line5[0])));
	expectedGrid.push_back(vector<int>(line6, line6 + sizeof(line6) / sizeof(line6[0])));
	expectedGrid.push_back(vector<int>(line7, line7 + sizeof(line7) / sizeof(line7[0])));
	expectedGrid.push_back(vector<int>(line8, line8 + sizeof(line8) / sizeof(line8[0])));
	expectedGrid.push_back(vector<int>(line9, line9 + sizeof(line9) / sizeof(line9[0])));

	Grid * currentGrid = new Grid(expectedGrid);
	EXPECT_TRUE(currentGrid->CheckGrid());
}

TEST(GridCheck, FalseGrid) {
	static const int line1[] = { 1,2,3,4,5,6,7,8,9 };
	static const int line2[] = { 4,5,6,7,8,9,1,2,3 };
	static const int line3[] = { 7,8,9,1,2,3,4,5,6 };
	static const int line4[] = { 2,3,4,5,6,1,8,9,1 };
	static const int line5[] = { 5,6,7,8,9,7,2,3,4 };
	static const int line6[] = { 8,9,1,2,3,4,5,6,7 };
	static const int line7[] = { 3,4,5,6,7,8,9,1,2 };
	static const int line8[] = { 6,7,8,9,1,2,3,4,5 };
	static const int line9[] = { 9,1,2,3,4,5,6,7,8 };
	vector<vector<int>> expectedGrid(1, vector<int>(line1, line1 + sizeof(line1) / sizeof(line1[0])));
	expectedGrid.push_back(vector<int>(line2, line2 + sizeof(line2) / sizeof(line2[0])));
	expectedGrid.push_back(vector<int>(line3, line3 + sizeof(line3) / sizeof(line3[0])));
	expectedGrid.push_back(vector<int>(line4, line4 + sizeof(line4) / sizeof(line4[0])));
	expectedGrid.push_back(vector<int>(line5, line5 + sizeof(line5) / sizeof(line5[0])));
	expectedGrid.push_back(vector<int>(line6, line6 + sizeof(line6) / sizeof(line6[0])));
	expectedGrid.push_back(vector<int>(line7, line7 + sizeof(line7) / sizeof(line7[0])));
	expectedGrid.push_back(vector<int>(line8, line8 + sizeof(line8) / sizeof(line8[0])));
	expectedGrid.push_back(vector<int>(line9, line9 + sizeof(line9) / sizeof(line9[0])));

	ASSERT_THROW(Grid * currentGrid = new Grid(expectedGrid), exception);
}

TEST(GridCheck, ZeroGrid) {
	static const int line1[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line2[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line3[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line4[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line5[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line6[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line7[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line8[] = { 0,0,0,0,0,0,0,0,0 };
	static const int line9[] = { 0,0,0,0,0,0,0,0,0 };
	vector<vector<int>> expectedGrid(1, vector<int>(line1, line1 + sizeof(line1) / sizeof(line1[0])));
	expectedGrid.push_back(vector<int>(line2, line2 + sizeof(line2) / sizeof(line2[0])));
	expectedGrid.push_back(vector<int>(line3, line3 + sizeof(line3) / sizeof(line3[0])));
	expectedGrid.push_back(vector<int>(line4, line4 + sizeof(line4) / sizeof(line4[0])));
	expectedGrid.push_back(vector<int>(line5, line5 + sizeof(line5) / sizeof(line5[0])));
	expectedGrid.push_back(vector<int>(line6, line6 + sizeof(line6) / sizeof(line6[0])));
	expectedGrid.push_back(vector<int>(line7, line7 + sizeof(line7) / sizeof(line7[0])));
	expectedGrid.push_back(vector<int>(line8, line8 + sizeof(line8) / sizeof(line8[0])));
	expectedGrid.push_back(vector<int>(line9, line9 + sizeof(line9) / sizeof(line9[0])));

	Grid * currentGrid = new Grid(expectedGrid);
	EXPECT_TRUE(currentGrid->CheckGrid());
}

TEST(GridFill, OneCell) {
	
	static const int line1[] = { 1,2,3,4,5,6,7,8,9 };
	static const int line2[] = { 4,5,6,7,8,9,1,2,3 };
	static const int line3[] = { 7,8,9,1,2,3,4,5,6 };
	static const int line4[] = { 2,3,4,5,6,7,8,9,1 };
	static const int line5[] = { 5,6,7,8,0,1,2,3,4 };
	static const int line6[] = { 8,9,1,2,3,4,5,6,7 };
	static const int line7[] = { 3,4,5,6,7,8,9,1,2 };
	static const int line8[] = { 6,7,8,9,1,2,3,4,5 };
	static const int line9[] = { 9,1,2,3,4,5,6,7,8 };
	vector<vector<int>> expectedGrid(1, vector<int>(line1, line1 + sizeof(line1) / sizeof(line1[0])));
	expectedGrid.push_back(vector<int>(line2, line2 + sizeof(line2) / sizeof(line2[0])));
	expectedGrid.push_back(vector<int>(line3, line3 + sizeof(line3) / sizeof(line3[0])));
	expectedGrid.push_back(vector<int>(line4, line4 + sizeof(line4) / sizeof(line4[0])));
	expectedGrid.push_back(vector<int>(line5, line5 + sizeof(line5) / sizeof(line5[0])));
	expectedGrid.push_back(vector<int>(line6, line6 + sizeof(line6) / sizeof(line6[0])));
	expectedGrid.push_back(vector<int>(line7, line7 + sizeof(line7) / sizeof(line7[0])));
	expectedGrid.push_back(vector<int>(line8, line8 + sizeof(line8) / sizeof(line8[0])));
	expectedGrid.push_back(vector<int>(line9, line9 + sizeof(line9) / sizeof(line9[0])));

	Grid * newGrid = new Grid(expectedGrid);
	EXPECT_TRUE(newGrid->Play());
}


TEST(GridFill, MultiCell) {

	static const int line1[] = { 0,8,6,7,0,0,0,3,2 };
	static const int line2[] = { 0,0,1,6,0,0,0,8,4 };
	static const int line3[] = { 0,0,3,0,2,4,0,0,0 };
	static const int line4[] = { 3,1,0,0,0,0,4,0,7 };
	static const int line5[] = { 0,0,8,0,0,0,5,0,0 };
	static const int line6[] = { 7,0,9,0,0,0,0,6,8 };
	static const int line7[] = { 0,0,0,4,9,0,8,0,0 };
	static const int line8[] = { 8,5,0,0,0,2,3,0,0 };
	static const int line9[] = { 6,9,0,0,0,8,1,2,0 };
	vector<vector<int>> expectedGrid(1, vector<int>(line1, line1 + sizeof(line1) / sizeof(line1[0])));
	expectedGrid.push_back(vector<int>(line2, line2 + sizeof(line2) / sizeof(line2[0])));
	expectedGrid.push_back(vector<int>(line3, line3 + sizeof(line3) / sizeof(line3[0])));
	expectedGrid.push_back(vector<int>(line4, line4 + sizeof(line4) / sizeof(line4[0])));
	expectedGrid.push_back(vector<int>(line5, line5 + sizeof(line5) / sizeof(line5[0])));
	expectedGrid.push_back(vector<int>(line6, line6 + sizeof(line6) / sizeof(line6[0])));
	expectedGrid.push_back(vector<int>(line7, line7 + sizeof(line7) / sizeof(line7[0])));
	expectedGrid.push_back(vector<int>(line8, line8 + sizeof(line8) / sizeof(line8[0])));
	expectedGrid.push_back(vector<int>(line9, line9 + sizeof(line9) / sizeof(line9[0])));

	Grid * newGrid = new Grid(expectedGrid);
	EXPECT_TRUE(newGrid->Play());
}

TEST(GridFill, MultiCellHard) {

	static const int line1[] = { 3,4,0,0,7,0,8,6,0 };
	static const int line2[] = { 0,0,0,4,1,0,0,0,0 };
	static const int line3[] = { 2,5,0,0,0,0,4,0,0 };
	static const int line4[] = { 0,0,5,0,6,7,0,2,0 };
	static const int line5[] = { 1,0,0,0,4,0,0,0,9 };
	static const int line6[] = { 0,6,0,1,9,0,3,0,0 };
	static const int line7[] = { 0,0,4,0,0,0,0,8,3 };
	static const int line8[] = { 0,0,0,0,2,4,0,0,0 };
	static const int line9[] = { 0,9,2,0,8,0,0,4,1 };
	vector<vector<int>> expectedGrid(1, vector<int>(line1, line1 + sizeof(line1) / sizeof(line1[0])));
	expectedGrid.push_back(vector<int>(line2, line2 + sizeof(line2) / sizeof(line2[0])));
	expectedGrid.push_back(vector<int>(line3, line3 + sizeof(line3) / sizeof(line3[0])));
	expectedGrid.push_back(vector<int>(line4, line4 + sizeof(line4) / sizeof(line4[0])));
	expectedGrid.push_back(vector<int>(line5, line5 + sizeof(line5) / sizeof(line5[0])));
	expectedGrid.push_back(vector<int>(line6, line6 + sizeof(line6) / sizeof(line6[0])));
	expectedGrid.push_back(vector<int>(line7, line7 + sizeof(line7) / sizeof(line7[0])));
	expectedGrid.push_back(vector<int>(line8, line8 + sizeof(line8) / sizeof(line8[0])));
	expectedGrid.push_back(vector<int>(line9, line9 + sizeof(line9) / sizeof(line9[0])));

	Grid * newGrid = new Grid(expectedGrid);
	EXPECT_TRUE(newGrid->Play());
}