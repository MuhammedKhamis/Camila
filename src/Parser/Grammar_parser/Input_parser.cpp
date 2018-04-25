/*
 * Inputparser.cpp
 * 		Parsing the raw input to be sent to first and follow
 *
 *  Created on: Apr 15, 2018
 *      Author: mishors
 */

#include "Input_parser.h"

Input_parser::Input_parser() {
	// TODO Auto-generated constructor stub

}

Input_parser::~Input_parser() {
	// TODO Auto-generated destructor stub
}

map<string, set<string>> Input_parser::get_rules_map(vector<string> rules){
	map<string, set<string>> result;

	//for each rule(string) in
	for(int i=0; i<rules.size(); i++){
		//first of the result map
		string rule_name;
		//second of the result map
		set<string> expressions;

		// stringstream class convert
		stringstream rule_stream(rules[i]);

		string token;

		//Reading '#' character which indicates start of the rule
		getline(rule_stream, token, ' ');

		//If first token is not production rule returns
		if(token.compare("#") ){
			map<string, set<string>> empty;
			return  empty;
		}

		//Reading the non_terminal (name) of the rule
		getline(rule_stream, token, ' ');

		rule_name = token;

		//Read "::=" symbol
		getline(rule_stream, token, ' ');

		//If after production name there is no "::=" symbol means error;
		if(token.compare("::=")) return result;

		//temp buffer to append expression tokens
		string expr = "";
		// Tokenizing w.r.t. space ' '
		while(getline(rule_stream, token, ' '))
		{
			//if end of expression by '|' operation push to expressions
			if(!token.compare("|")){
				//Add new expression to the production rule
				expressions.insert(expr);
				expr = "";
			}else {
				//ignore spaces
				if(token.compare(" "))
					{
						//Construct the expression
						expr.append(token);
						expr.append(" ");
					}
				}
			}
		//the last expression must be inserted
		expr = trim(expr);
		expressions.insert(expr);

		//insert to map
		result.insert(pair<string,set<string>> (rule_name,expressions));
	}
	return result;
}

string Input_parser::trim (string str){
	string res = str;
	//trim the res
	res.erase(remove(res.begin(), res.end(), ' '), res.end());
	return res;
}

