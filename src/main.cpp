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
#include "Parser/Parser_Controller/Parser_Controller.h"

using namespace std;


int main(int argc, char** argv) {

	//TESTING THE INPUT PARSER


    string grammer_path = "../Parser_tests/";

    vector<string> tests = {"test.txt","test_1.txt","test_2.txt","test_3.txt"};

    for(int i = 0 ; i < tests.size() ; i++){

        string test_path = grammer_path + tests[i];

        Input_reader ir;

        vector<string> v =	ir.read(test_path);

        Input_parser ip;

        FF_Package rules = ip.get_rules_map(v);

        first_follow_generator ffg(rules.getProductions(),rules.getOrder_of_productions());
        ffg.generator();

        ffg.print_firsts();
        ffg.print_follows();
        cout << "\n-------------------------------------------------\n";
    }
    /*
     * Report
     *  test : Still segmentation fault @Essam's PC.
     *  test_1 : Passed
     *  test_2 : passed
     *  test_3 : Passed.
     *
     * */

    /*
	Parser_Controller parser_controller;

    Parsing_Table pt = parser_controller.generate_table(grammer_path);
    */

	return 0;
}
