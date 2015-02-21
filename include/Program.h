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

struct stringProgram{
	std::string sTag;
	std::string sCommand;
	std::string sTag2;
};

class Program {
private:
	std::string myFile;
	std::string myProgram;;
	std::vector<Instruction*>vInstruction;
	std::vector<stringProgram>vDesensamblador;

	void readFile();
	void cleanString(std::string&);
	int transformCommand(std::string&);
	int transformTag(std::string&);
	int inmediateMode(std::string);
	int directMode(std::string);
	int indirectMode(std::string);
	void instructionJump();
	void lookForHalt();


public:
	Program();
	virtual ~Program();
	void codeProgram();
	std::vector<Instruction*>& getInstruction();
	void desensamblar();
};

#endif /* PROGRAM_H_ */
