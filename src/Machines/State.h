/*
 * State.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef STATE_H_
#define STATE_H_

#include <bits/stdc++.h>
#include "../General/Enums.h"
using namespace std;


class State{

public:
	State(priority p,string token,int id);
	priority get_priority();
	string get_token();
	int get_id();

protected:

private:
	string token;
	priority p;
	int id;

};



#endif /* STATE_H_ */
