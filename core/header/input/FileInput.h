#pragma once

#include <vector>
#include "InputAbstract.h"

class FileInput : public InputAbstract
{
public:
	FileInput();
	virtual ~FileInput() {};

	void Init(std::string fileNameP);

	std::vector<vector<int>> Reader();

protected:
	std::string fileName;
};