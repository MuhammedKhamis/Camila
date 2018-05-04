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


vector<Grammar_rule> Input_parser::get_grammar_rules(vector<string> rules){
	vector<Grammar_rule> result;
	for(int i=0; i<rules.size(); i++){
			Grammar_rule rule;
			rule.set_rule(rules[i]);
			result.push_back(rule);
		}
	return result;
}

vector<string> Input_parser::get_grammar_strings(vector<Grammar_rule> rules){
	vector<string> result;
		for(int i=0; i<rules.size(); i++){
				string rule;
				rule = rules[i].rule_to_string();
				result.push_back(rule);
			}
		return result;
}

FF_Package Input_parser::get_rules_map(vector<string> rules){
	map<string, set<string>> result;
	vector<string> order;
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
			cout << "# ERROR\n";
			exit(1);
		/*
			map<string, set<string>> empty;
			FF_Package ffp(empty,order);
			return  ffp;
		*/
		}


		//Reading the non_terminal (name) of the rule
		getline(rule_stream, token, ' ');

		rule_name = token;

		order.emplace_back(rule_name);

		//Read "::=" symbol
		getline(rule_stream, token, ' ');

		//If after production name there is no "::=" symbol means error;
		if(token.compare("::=")){
			cout << "::= ERROR\n";
			exit(1);
			//return result;
		}

		//temp buffer to append expression tokens
		string expr = "";
		// Tokenizing w.r.t. space ' '
		vector<part> parts;
		line ln(rule_name);
		while(getline(rule_stream, token, ' '))
		{

			//if end of expression by '|' operation push to expressions
			if(!token.compare("|")){
				//Add new expression to the production rule
				expressions.insert(expr);
				// expression complete
				element elem(parts,rule_name);
				ln.add_element(elem);
				parts.clear();
				expr = "";
			}else {
				//ignore spaces
				if(token.compare(" "))
				{
						//Construct the expression
						expr.append(" ");
						expr.append(token);

						if(token[0] == '\''){
							//terminal
							string str = token.substr(1,token.size()-2);
							part p(str,true);
							parts.emplace_back(p);
						}else{
							part p(token,false);
							parts.emplace_back(p);
						}

				}
				}
			}

		//the last expression must be inserted
		string without_space="";
		without_space.append(expr.begin()+1,expr.end());
		expressions.insert(without_space);
		Non_Terminal nt(ln,rule_name,i);
		non_terminals.emplace_back(nt);
		//insert to map
		result.insert(pair<string,set<string>> (rule_name,expressions));
	}
	FF_Package ffp(result,order);
	return ffp;
}


vector<Non_Terminal> Input_parser::get_non_Terminals() {
	return non_terminals;
}

string Input_parser::trim (string str){
	string res = str;
	//trim the res
	res.erase(remove(res.begin(), res.end(), ' '), res.end());
	return res;
}

