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
public:
	UC();
	~UC();
};

} /* namespace std */

#endif /* UC_H_ */
