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

#include "Parser/LL1 - Conversion/LL1_handler.h"

#include "Parser/LL1 - Conversion/prefix_handler.h"

using namespace std;

int main(int argc, char** argv) {

    Grammar_rule rule1,rule2,rule3;

    rule1.set_rule("# A ::= a d | a | a b | a b c | b");

    rule2.set_rule("# T ::= T * F | F");

    rule3.set_rule("# F ::= id | ( E )");

    LL1_handler ll1;

    vector<Grammar_rule> res,input;

    input.push_back(rule1);

    input.push_back(rule2);

    input.push_back(rule3);

   //res = ll1.eliminate_left_recursion(input);

   ll1.left_factor(rule1, &res);

   prefix_handler ph;

    ph.set_expressions(rule1.expressions);

    ph.generate_sets();

    //ph.print_sets();

    //cout<<ph.get_rules_number();

   // cout<<ph.get_remove_prefix("abcd","abcd");


   std::set<string>::iterator it;

   for(int i=0; i<res.size(); i++){
		Grammar_rule rule = res[i];
		cout<<rule.get_non_terminal()<<endl;

    	for (it = rule.expressions.begin(); it != rule.expressions.end(); ++it)
		{

			cout<<*it<<endl;
		}

		cout<<endl;
    }

	return 0;
}

