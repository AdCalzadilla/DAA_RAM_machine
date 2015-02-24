/*
 * Memory.cpp
 *
 *  Created on: 19/2/2015
 *      Author: Adrian
 */

#include "Memory.h"
#include <vector>

using namespace std;

Memory::Memory() {
	// TODO Auto-generated constructor stub
	theMemory.resize(10);
	for(int i=0; i< theMemory.size();i++){
		theMemory[i]= 0;
	}
}

Memory::~Memory() {
	// TODO Auto-generated destructor stub
}

void Memory::setMemory(int pos,int value){
	theMemory[pos] = value;
}

int Memory::getMemory(int i){
	return theMemory[i];
}

int Memory::size(){
	return theMemory.size();
}

