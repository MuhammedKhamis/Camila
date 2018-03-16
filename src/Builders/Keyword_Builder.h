/*
 * Keyword_Builder.h
 *
 *  Created on: Mar 16, 2018
 *      Author: muhammed
 */

#ifndef KEYWORD_BUILDER_H_
#define KEYWORD_BUILDER_H_

#include <bits/stdc++.h>
using namespace std;

class Keyword_Builder:Builder{
public:
	// take line of keywords as in the file
	// example => { "while", "int", "float" } without { }
	void evaluate_keyword(vector<string> keywords_line);
protected:

private:

};



#endif /* KEYWORD_BUILDER_H_ */
