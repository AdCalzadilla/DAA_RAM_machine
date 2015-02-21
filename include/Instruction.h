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
	int tag;
	int command;
	int tag2;
public:
	Instruction(int tag,int command, int tag2);
	virtual ~Instruction();
	int getTag();
	int getCommand();
	int getTag2();
	void setTag(int);
	void setCommand(int);
	void setTag2(int);

	Instruction& operator =(const Instruction &inst);
};

#endif /* INSTRUCTION_H_ */
