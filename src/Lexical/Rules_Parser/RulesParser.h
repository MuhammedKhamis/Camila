/*
 * RulesParser.h
 *      Author: Murad
 */

#ifndef RULESPARSER_H_
#define RULESPARSER_H_

#include <vector>
#include <string>

#include "Rules.h"

class RulesParser {

public:
	/**
	 * parse the whole rules lines and return a Rule object which contain tokens of parsed rules on the specified vector.
	 */
	Rules parse_lines(std::vector<std::string> lines);

	/**
	 * Rules rules is parsed so as to enter the result parsed rule to
	 * the appropriate vector of the class rule.
	 * priorities is determeine which vector of rules this lines' tokens inserted to it.
	 * 	  0 > keywords
	 * 	  1 > puctuation
	 * 	  2 > Definitions
	 * 	  3 > expressions
	 */

protected:
	std::vector<std::string> parse(std::string line, int priorities);

	/**
	 * parse the line rule of keywords line
	 */
	std::vector<std::string> keywords_parser(std::string line);

	/**
	 * parse the line rule of Punctuation line
	 */
	std::vector<std::string> Punctuation_parser(std::string line);

	/**
	 * parse the line rule of definitions line
	 */
	std::vector<std::string> definitions_parser(std::string line);

	/**
	 * parse the line rule of expressions line
	 */
	std::vector<std::string> expressions_parser(std::string line);

private:
	/**
	 * helper function which used inside both definitions_parser and expressions_parser
	 */
	std::vector<std::string> expr_def_parser(std::string line);

//private:
//	void extract_name(char stmt[]);
//	void extract_type(char stmt[]);
//	void extract_tokens(char stmt[]);
//
//
//public:
//	/* parse will return a vector of name, type of rule and the rest of tokens */
//	std::vector<char*> parse(std::vector<std::string> lines);
};

#endif /* RULESPARSER_H_ */
