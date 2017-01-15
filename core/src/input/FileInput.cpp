#include "../../header/input/FileInput.h"
#include <iostream>
#include <fstream>
#include "../../header/Common.h"

using namespace std;

FileInput::FileInput() : fileName("") {

}

void FileInput::Init(string fileNameP) {
	fileName = fileNameP;
}

vector<vector<int>> FileInput::Reader() {
	if (fileName == "")
		return vector<vector<int>>();

	vector<vector<int>> sudokuGame;
	
	ifstream currentFile;
	currentFile.open(fileName);

	for (int line = 0; 
		line < gameConst::SIZE && !currentFile.eof(); 
		line++) 
	{
		sudokuGame.push_back(vector<int>());

		for (int column = 0; 
			column < gameConst::SIZE && !currentFile.eof(); 
			column++) 
		{
			int currentCell;
			currentFile >> currentCell;
			sudokuGame[line].push_back(currentCell);
		}
	}
	currentFile.close();

	return sudokuGame;
}