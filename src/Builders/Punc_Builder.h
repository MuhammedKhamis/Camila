/*
 * Punc_Builder.h
 *
 *  Created on: Mar 16, 2018
 *      Author: muhammed
 */

#ifndef PUNC_BUILDER_H_
#define PUNC_BUILDER_H_

#include <bits/stdc++.h>
using namespace std;

class Punc_Builder:Builder{

public:
	// take line of keywords as in the file
	// example => { "}", ")", "," } without { }
	void evaluate_punc(vector<string> punc_line);

protected:

private:


};


#endif /* PUNC_BUILDER_H_ */
