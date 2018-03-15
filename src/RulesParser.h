/*
 * Parser.h
 *      Author: Murad
 */

#ifndef RULESPARSER_H_
#define RULESPARSER_H_

#include <vector>

class Parser{

private:
	void extract_name(char stmt[]);
	void extract_type(char stmt[]);
	void extract_tokens(char stmt[]);


public:
	/* parse will return a vector of name, type of rule and the rest of tokens */
	std::vector<char*> parse(char stmt[]);
};




#endif /* RULESPARSER_H_ */
