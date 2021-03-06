/*
 * Memory.h
 *
 *  Created on: 19/2/2015
 *      Author: Adrian
 */

#ifndef MEMORY_H_
#define MEMORY_H_

#include <iostream>
#include <vector>

namespace std {

class Memory {
private:
	std::vector<int>theMemory;
public:
	Memory();
	~Memory();
	void setMemory(int pos, int value);
	int getMemory(int);
	int size();
};

} /* namespace std */

#endif /* MEMORY_H_ */
