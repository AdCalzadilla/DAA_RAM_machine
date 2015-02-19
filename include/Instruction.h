/*
 * Instruction.h
 *
 *  Created on: 9/2/2015
 *      Author: Adrian
 */
#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include<iostream>
#include<string.h>


class Instruction {
private:
	std::string tag;
	std::string command;
	std::string tag2;
public:
	Instruction(std::string tag,std::string comand, std::string tag2);
	virtual ~Instruction();
	std::string getTag();
	std::string getCommand();
	std::string getTag2();
	void setTag(std::string);
	void setCommand(std::string);
	void setTag2(std::string);
};

#endif /* INSTRUCTION_H_ */
