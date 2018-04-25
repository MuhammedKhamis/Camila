//
// Created by muhammed on 16/04/18.
//

#ifndef COMPILER_PROJECT_PARSING_TABLE_H
#define COMPILER_PROJECT_PARSING_TABLE_H

#include <bits/stdc++.h>
#include "../Data_Structures/Production/Production.h"
#include "../../Lexical/General/Enums.h"

using namespace std;


/*
 *  Parsing table for scanning the file.
 *
 * */

class Parsing_Table {

public:


    /*
     * Constructor that takes the table as input to answer the scanning queries.
     *
     * */
    Parsing_Table( unordered_map<string, unordered_map<string, Production>> &table, string &start_Non_Terminal);

    /*
     *
     * return the production reversed for the stack using the non_terminal and the input symbol
     *
     *  if we found match production will be returned
     *  else an empty vector of string will be sent
     *
     * */
    vector<string> get_production(string non_terminal,string input);

    string get_start_Non_Terminal();

    Type get_production_type(string non_terminal,string input);

    bool is_non_terminal(string &non_terminal);

    void print_table();

private:

    unordered_map<string,unordered_map<string,Production>> table;
    string start_Non_Terminal;
    set<string> non_terminals;
    const string sync_val = "sync";

};


#endif //COMPILER_PROJECT_PARSING_TABLE_H
