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
#include "Scanner/Scanner.h"

#include "Parser/Grammar_parser/Grammar_rule.h"

#include "Parser/Grammar_parser/Input_reader.h"

#include "Parser/Grammar_parser/Input_parser.h"

#include "Parser/LL1 - Conversion/LL1_handler.h"

#include "Parser/LL1 - Conversion/prefix_handler.h"

using namespace std;


int main(int argc, char** argv) {

	//TESTING THE INPUT PARSER


    string grammer_path = "./phase_2/grammar_modified.txt";
    string lexical_path = "./Lexical_Rules/rules.txt";
    string program_path = "./phase_2/test2.txt";

    /*

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
*/
    /*
     * Report
     *  test : Still segmentation fault @Essam's PC.
     *  test_1 : Passed
     *  test_2 : passed
     *  test_3 : Passed.
     *
     * */

    Scanner scanner;
    scanner.normal_scan(lexical_path,program_path,grammer_path);


	return 0;
}
