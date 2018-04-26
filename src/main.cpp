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

	vector<string> v =	ir.read("../Parser_tests/test.txt");

	Input_parser ip;

	FF_Package rules = ip.get_rules_map(v);


    first_follow_generator ffg(rules.getProductions(),rules.getOrder_of_productions());
    ffg.generate_first_productions();
    ffg.generate_follow_productions();
    ffg.print_firsts();
    ffg.print_follows();
	return 0;
}
