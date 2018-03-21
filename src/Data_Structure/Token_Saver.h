/*
 * Token_Saver.h
 *
 *  Created on: Mar 20, 2018
 *      Author: muhammed
 */

#ifndef TOKEN_SAVER_H_
#define TOKEN_SAVER_H_

#include <bits/stdc++.h>
using namespace std;

class Token_Saver{

public:
	 static Token_Saver& get_Instance();
	 void add_token(string token);
	 int get_token_level(string token);

protected:

private:
		/*
		 *  Singleton handling
		 * */
	 Token_Saver(){};
     // Stop the compiler generating methods of copy the object
	 Token_Saver(Token_Saver const& copy);            // Not Implemented
	 Token_Saver& operator=(Token_Saver const& copy); // Not Implemented

	 int level = 0;
	 unordered_map<string,int> token_lvl;

};




#endif /* TOKEN_SAVER_H_ */
