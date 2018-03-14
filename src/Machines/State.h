/*
 * State.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef STATE_H_
#define STATE_H_

#include <bits/stdc++.h>
#include "../Enums.h"
using namespace std;


class State{

public:
	State(priority p);
	priority get_priority();
	void set_priority(priority p);

protected:

private:
	priority p;

};



#endif /* STATE_H_ */
