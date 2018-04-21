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

using namespace std;

int main(int argc, char** argv) {

    Grammar_rule prod;

    prod.set_rule("# A ::= S b d e | S k o l | S t u | S x y");

    Grammar_rule prod2;

    prod2.set_rule("# S ::= r | q");

    prod.replace_with(prod2);

    cout<<prod.non_terminal<<endl;

    //cout<<prod2.non_terminal<<endl;
    std::set<string>::iterator it;
    for (it = prod.expressions.begin(); it != prod.expressions.end(); ++it)
    {

        cout<<*it<<endl;
    }


	return 0;
}

