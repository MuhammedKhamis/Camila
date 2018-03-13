/*
 * Token.h
 *
 *  Created on: 13/3/2018
 *      Author: Murad
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>

class Token{

public:
	/* name of regular expression or regular definition */
	char* name;
	/* type is a regular expression or regular definition */
	char type;
	/* the remaining tokens of the statement*/
	char** tokens;
};

#endif /* TOKEN_H_ */
