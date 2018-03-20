/*
 * Machine.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#include <bits/stdc++.h>
#include "State.h"
#include "Transition_Table.h"

using namespace std;

class Machine{

public:
	Machine(Transition_Table* table);
	/* Get Current State of the Machine */
	 State* get_current();
	 /* Get the Start state of the machine */
	 State* get_start();
	 /* go to the next state */
	 bool next(State* current,char input);
	 virtual ~Machine() = 0;
protected:

private:
		Transition_Table* table;

};



#endif /* MACHINE_H_ */
