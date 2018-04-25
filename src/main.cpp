//============================================================================
// Name        : Lexical-Analyzer-Generator.cpp
// Author      : Muhammed Essam Khamis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <bits/stdc++.h>

#include "Parser/Grammar_parser/Input_reader.h"
#include "Parser/Grammar_parser/Input_parser.h"
#include "Parser/First_follow_finder/first_follow_generator.h"

using namespace std;



int main(int argc, char** argv) {

	//TESTING THE INPUT PARSER

	Input_reader ir;

	vector<string> v =	ir.read("test 3.txt");

	Input_parser ip;

	map<string,set<string>> rules = ip.get_rules_map(v);

    first_follow_generator ffg(rules);
    ffg.generate_first_productions();
    ffg.print_firsts();

	return 0;
}
