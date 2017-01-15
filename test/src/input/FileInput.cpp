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