//============================================================================
// Name        : Lexical-Analyzer-Generator.cpp
// Author      : Muhammed Essam Khamis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

#include "Lexical/Scanner/Scanner.h"

#include "Parser/Grammar_parser/Grammar_rule.h"

#include "Parser/Grammar_parser/Input_reader.h"

#include "Parser/Grammar_parser/Input_parser.h"

#include "Parser/LL1 - Conversion/LL1_handler.h"

#include "Parser/LL1 - Conversion/prefix_handler.h"

using namespace std;

int main(int argc, char** argv) {


	vector<Grammar_rule> res,input;

	vector<string> input_str;

	Input_reader ir;

	input_str =	ir.read("./Parser_tests/test.txt");

	Input_parser ip;

	input = ip.get_grammar_rules(input_str);

	LL1_handler ll1;

	res = ll1.convert_to_ll1(input);

	vector <string> res_str = ip.get_grammar_strings(res);

	for(int i=0; i<res_str.size(); i++){
		cout<<res_str[i]<<endl;
	}

	return 0;
}

