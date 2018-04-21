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

    prod.set_rule("# STATMENT ::= DECLARATION | IF | WHILE | \\L");

    cout<<prod.non_terminal<<endl;

    std::set<string>::iterator it;
    for (it = prod.expressions.begin(); it != prod.expressions.end(); ++it)
    {
        cout<<*it;
    }

	return 0;
}

