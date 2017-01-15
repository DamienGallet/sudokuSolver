#pragma once

#include <vector>
using namespace std;

class InputAbstract {
public:
	InputAbstract() {};
	virtual ~InputAbstract() {};
	
	virtual vector<vector<int>> Reader() = 0;
};