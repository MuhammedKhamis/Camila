/*
 * Def_Builder.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef DEF_BUILDER_H_
#define DEF_BUILDER_H_

#include <bits/stdc++.h>
using namespace std;


class Def_Builder: Builder{

public:

	void evaluate_def(vector<string> defination);
	vector<string> get_def_value(string def);

protected:


private:
	static const int defination_index = 1;


};



#endif /* DEF_BUILDER_H_ */
