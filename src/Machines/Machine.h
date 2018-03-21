/*
 * Machine.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#include <bits/stdc++.h>
using namespace std;

class Machine{

public:
	/* Get Current State of the Machine */
	 State* get_current();
	 /* Get the Start state of the machine */
	 State* get_start();
	 /* Get the end state of the machine*/
	 State* get_end();
	 /* go to the next state */
	 bool next();
	 virtual ~Machine() = 0;
protected:
	Machine();
	Transition_Table* table;
private:

};



#endif /* MACHINE_H_ */
