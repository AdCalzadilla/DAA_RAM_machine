/*
 * Program.h
 *
 *  Created on: 7/2/2015
 *      Author: Adrian
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <iostream>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <regex>
#include <vector>
#include "Instruction.h"

class Program {
private:
	std::string myFile;
	std::string myProgram;;
	std::vector<Instruction*>vInstruction;

	void cleanString(std::string&);
	//void transformInstruction();

public:
	Program();
	virtual ~Program();
	void readFile();
	void printProgram();
};

#endif /* PROGRAM_H_ */
