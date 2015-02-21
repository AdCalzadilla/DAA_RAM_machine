/*
 * Instruction.cpp
 *
 *  Created on: 9/2/2015
 *      Author: Adrian
 */

#include "Instruction.h"

using namespace std;

Instruction::Instruction(int tag, int command, int tag2) {
	// TODO Auto-generated constructor stub
	this->tag = tag;
	this->command= command;
	this->tag2= tag2;
}

Instruction::~Instruction() {
	// TODO Auto-generated destructor stub
}

int Instruction::getTag(){
	return tag;
}

int Instruction::getCommand(){
	return command;
}

int Instruction::getTag2(){
	return tag2;
}

void Instruction::setTag(int tg){
	tag = tg;
}

void Instruction::setCommand(int cm){
	command = cm;
}

void Instruction::setTag2(int tg2){
	tag2 = tg2;
}

Instruction& Instruction::operator =(const Instruction &inst){
	tag = inst.tag;
	command = inst.command;
	tag2 = inst.tag2;
	return (*this);
}

