/*
 * Instruction.cpp
 *
 *  Created on: 9/2/2015
 *      Author: Adrian
 */

#include "Instruction.h"

using namespace std;

Instruction::Instruction(string tag, string command, string tag2) {
	// TODO Auto-generated constructor stub
	this->tag = tag;
	this->command= command;
	this->tag2= tag2;
}

Instruction::~Instruction() {
	// TODO Auto-generated destructor stub
}

string Instruction::getTag(){
	return tag;
}

string Instruction::getCommand(){
	return command;
}

string Instruction::getTag2(){
	return tag2;
}

void Instruction::setTag(string tg){
	tag = tg;
}

void Instruction::setCommand(string cm){
	command = cm;
}

void Instruction::setTag2(string tg2){
	tag2 = tg2;
}

