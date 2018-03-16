/*
 * Builder.h
 *
 *  Created on: Mar 16, 2018
 *      Author: muhammed
 */

#ifndef BUILDER_H_
#define BUILDER_H_

#include <bits/stdc++.h>
using namespace std;

class Builder{

public:
		virtual Builder* Instance() = 0 ;
protected:
		virtual ~Builder();
		map<string,vector<string>> to_val;
private:

};


#endif /* BUILDER_H_ */
