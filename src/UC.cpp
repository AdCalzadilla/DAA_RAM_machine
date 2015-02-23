/*
 * UC.cpp
 *
 *  Created on: 19/2/2015
 *      Author: Adrian
 */

#include "UC.h"

using namespace std;

enum Code{LOAD=0,STORE,ADD,SUB,MULT,DIV,READ,WRITE,JUMP,JGTZ,JZERO,HALT};

UC::UC() {
	// TODO Auto-generated constructor stub
	trace = false;
}

UC::~UC() {
	// TODO Auto-generated destructor stub
}

bool UC::getTrace(){
	return trace;
}

void UC::setTrace(bool tr){
	trace = tr;
}

bool UC::checkRegister(int pos,int value){
	if(pos >= myMemory.size() || pos < 0){
		cout<< "Accediendo a posición inexistente de memoria.\n";
		return false;
	}
	if(value < 0 || value > 9){
		cout<< "Desbordamiento en los registros de la memoria.\n";
		return false;
	}
	return true;
}

void UC::run(){
	programInstruction= myProgram.getInstruction();
	int i = 0;
	while(1 <= programInstruction.size()){
		if(programInstruction[i]->getCommand()== LOAD){
			funcLOAD(i);
		}
		else if(programInstruction[i]->getCommand()== STORE){
			funcSTORE(i);
		}
	}
}

void UC::funcLOAD(int instruc){
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 || programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		if(checkRegister(0,auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 20 || programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkRegister(0,auxInt)){
			myMemory.setMemory(0,myMemory.getMemory(auxInt));
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 30 || programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkRegister(0,auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			myMemory.setMemory(0,auxInt);
		}
	}
}

void UC::funcSTORE(int instruc){
	int auxInt = -1;
	int value = -1;
	/*if(programInstruction[instruc]->getTag2() >= 10 || programInstruction[instruc]->getTag2() < 20){

	}*/
	if(programInstruction[instruc]->getTag2() >= 20 || programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkRegister(0,auxInt)){
			value = myMemory.getMemory(0);
			myMemory.setMemory(auxInt,value);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 30 || programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkRegister(0,auxInt)){
			value = myMemory.getMemory(0);
			auxInt = myMemory.getMemory(auxInt);
			myMemory.setMemory(auxInt,value);
		}
	}
}

void UC::funcADD(int instruc){
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 || programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		if(checkRegister(0,auxInt)){
			auxInt = auxInt + myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 20 || programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkRegister(0,auxInt)){
			auxInt = myMemory.getMemory(auxInt) + myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 30 || programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkRegister(0,auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			auxInt = myMemory.getMemory(auxInt);
			auxInt = auxInt + myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
}

void UC::funcSUB(int instruc){
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 || programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		if(checkRegister(0,auxInt)){
			auxInt = auxInt - myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 20 || programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkRegister(0,auxInt)){
			auxInt = myMemory.getMemory(auxInt) - myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 30 || programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkRegister(0,auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			auxInt = myMemory.getMemory(auxInt);
			auxInt = auxInt - myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
}

void UC::funcMULT(int instruc){
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 || programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		if(checkRegister(0,auxInt)){
			auxInt = auxInt * myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 20 || programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkRegister(0,auxInt)){
			auxInt = myMemory.getMemory(auxInt) * myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 30 || programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkRegister(0,auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			auxInt = myMemory.getMemory(auxInt);
			auxInt = auxInt * myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
}

void UC::funcDIV(int instruc){     //DIVISION POR 0.
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 || programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		if(checkRegister(0,auxInt)){
			auxInt = auxInt / myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 20 || programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkRegister(0,auxInt)){
			auxInt = myMemory.getMemory(auxInt) / myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 30 || programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkRegister(0,auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			auxInt = myMemory.getMemory(auxInt);
			auxInt = auxInt / myMemory.getMemory(0);
			myMemory.setMemory(0,auxInt);
		}
	}
}

void UC::funcREAD(int instruc){

}

void UC::funcWRITE(int instruc){

}

int UC::funcJUMP(int instruc){
	return programInstruction[instruc]->getTag2();
}

int UC::funcJGTZ(int instruc){
	if(myMemory.getMemory(0) >= 0){
		return programInstruction[instruc]->getTag2();
	}
	else{
		return instruc;
	}
}

int UC::funcJZERO(int instruc){
	if(myMemory.getMemory(0)== 0){
		return programInstruction[instruc]->getTag2();
	}
	else{
		return instruc;
	}
}

int UC::funcHALT(){
	return -1;
}






