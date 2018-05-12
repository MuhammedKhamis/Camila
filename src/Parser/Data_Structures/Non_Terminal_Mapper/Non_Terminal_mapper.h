//
// Created by muhammed on 25/04/18.
//

#ifndef COMPILER_PROJECT_NON_TERMINAL_MAPPER_H
#define COMPILER_PROJECT_NON_TERMINAL_MAPPER_H

#include <bits/stdc++.h>
using namespace std;

class Non_Terminal_mapper {

    void add_nonTerminal(string &non_terminal,int id);

    int get_id(string &non_terminal);

private:

    unordered_map<string,int> nonTerminal_to_id;


};


#endif //COMPILER_PROJECT_NON_TERMINAL_MAPPER_H
