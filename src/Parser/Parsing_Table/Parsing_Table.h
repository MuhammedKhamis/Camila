//
// Created by muhammed on 16/04/18.
//

#ifndef COMPILER_PROJECT_PARSING_TABLE_H
#define COMPILER_PROJECT_PARSING_TABLE_H

#include <bits/stdc++.h>
#include "../Production/Production.h"

using namespace std;

class Parsing_Table {

public:
    Parsing_Table( unordered_map<string, unordered_map<string, Production>> &table);

    vector<string> get_production(string non_terminal,string input);

private:

    unordered_map<string,unordered_map<string,Production>> table;

};


#endif //COMPILER_PROJECT_PARSING_TABLE_H
