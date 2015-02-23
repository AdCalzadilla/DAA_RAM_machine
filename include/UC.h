/*
 * UC.h
 *
 *  Created on: 19/2/2015
 *      Author: Adrian
 */

#ifndef UC_H_
#define UC_H_

#include "Memory.h"
#include "Program.h"

namespace std {

class UC {
private:
	Memory myMemory;
	Program myProgram;
	vector<int>into;
	vector<int>out;
	bool trace;
	bool checkRegister(int, int);
	vector<Instruction*>programInstruction;

	void write(int pos, int value);

public:
	UC();
	~UC();
	bool getTrace();
	void setTrace(bool);
	void run();

	//funciones de intrucciones.
	//--------------------------
	void funcLOAD(int);
	void funcSTORE(int);
	void funcADD(int);
	void funcSUB(int);
	void funcMULT(int);
	void funcDIV(int);
	void funcREAD(int);
	void funcWRITE(int);
	int funcJUMP(int);
	int funcJGTZ(int);
	int funcJZERO(int);
	int funcHALT();
};

} /* namespace std */

#endif /* UC_H_ */
