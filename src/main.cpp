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

using namespace std;

int main(int argc, char** argv) {

    Grammar_rule rule;

    rule.set_rule("# A ::= A c1 | b1 | A c2 | b2");

    Grammar_rule cont,not_cont;


    LL1_handler ll1;

    vector<Grammar_rule> res;

    res = ll1.eliminate_immediate_recursion(rule);

    cont = res[0];

    not_cont = res[1];

    cout<<rule.non_terminal<<endl;

    std::set<string>::iterator it;

    for (it = rule.expressions.begin(); it != rule.expressions.end(); ++it)
    {

        cout<<*it<<endl;
    }

    cout<<endl;

    cout<<cont.non_terminal<<endl;
    for (it = cont.expressions.begin(); it != cont.expressions.end(); ++it)
    {

        cout<<*it<<endl;
    }

    cout<<endl;

    cout<<not_cont.non_terminal<<endl;
    for (it = not_cont.expressions.begin(); it != not_cont.expressions.end(); ++it)
     {

            cout<<*it<<endl;
     }

	return 0;
}

