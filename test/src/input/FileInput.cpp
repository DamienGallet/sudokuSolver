#include <gtest\gtest.h>
#include "../../../core/header/input/FileInput.h"

#include <vector>
using namespace std;

TEST(FileInput, LoadGridFillOfZero) {
	// Given
	FileInput* fileInput = new FileInput();

	fileInput->Init("../test/src/input/samples/zeros.txt");
	vector<vector<int>> read = fileInput->Reader();
	
	vector<vector<int>> expectedGrid(9,vector<int>(9,0));


	EXPECT_EQ(expectedGrid, read);
}

TEST(FileInput, LoadRealGrid) {
	// Given
	FileInput* fileInput = new FileInput();

	fileInput->Init("../test/src/input/samples/real.txt");
	vector<vector<int>> read = fileInput->Reader();

	static const int line1[] = { 8,3,6,9,5,7,4,2,1 };
	static const int line2[] = { 1,9,4,8,2,3,7,6,5 };
	static const int line3[] = { 7,2,5,1,4,6,3,9,8 };
	static const int line4[] = { 3,4,9,7,8,2,1,5,6 };
	static const int line5[] = { 6,8,1,4,9,5,2,3,7 };
	static const int line6[] = { 5,7,2,6,3,1,9,8,4 };
	static const int line7[] = { 9,1,8,3,6,4,5,7,2 };
	static const int line8[] = { 2,6,7,5,1,9,8,4,3 };
	static const int line9[] = { 4,5,3,2,7,8,6,1,9 };
	vector<vector<int>> expectedGrid(1, vector<int>(line1, line1 + sizeof(line1) / sizeof(line1[0])));
	expectedGrid.push_back(vector<int>(line2, line2 + sizeof(line2) / sizeof(line2[0])));
	expectedGrid.push_back(vector<int>(line3, line3 + sizeof(line3) / sizeof(line3[0])));
	expectedGrid.push_back(vector<int>(line4, line4 + sizeof(line4) / sizeof(line4[0])));
	expectedGrid.push_back(vector<int>(line5, line5 + sizeof(line5) / sizeof(line5[0])));
	expectedGrid.push_back(vector<int>(line6, line6 + sizeof(line6) / sizeof(line6[0])));
	expectedGrid.push_back(vector<int>(line7, line7 + sizeof(line7) / sizeof(line7[0])));
	expectedGrid.push_back(vector<int>(line8, line8 + sizeof(line8) / sizeof(line8[0])));
	expectedGrid.push_back(vector<int>(line9, line9 + sizeof(line9) / sizeof(line9[0])));

	EXPECT_EQ(expectedGrid, read);
}