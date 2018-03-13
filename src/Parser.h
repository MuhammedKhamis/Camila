/*
 * Parser.h
 *      Author: Murad
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include "Token.h"

class Parser{

private:
	char* extract_name();
	char* extract_type();
	char** extract_tokens();


public:
	/* parse will return the name, type of rule and the rest of tokens */
	Token parse();
};




#endif /* PARSER_H_ */
