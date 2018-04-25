//
// Created by muhammed on 25/04/18.
//

#ifndef COMPILER_PROJECT_PARSER_CONTROLLER_H
#define COMPILER_PROJECT_PARSER_CONTROLLER_H

#include <bits/stdc++.h>
#include "../Non_Terminal_Package/Non_Terminal_Info.h"
#include "../Parsing_Table/Parsing_Table.h"
#include "../Parsing_Table_Generator/Parsing_Table_Generator.h"

using namespace std;

class Parser_Controller {

public:

    Parsing_Table generate_table(string path);

private:

    // Rafaat's Part
    // take input and split it for murad
    map<string,vector<string>> split_input(vector<string> &input_lines);


    // Murad's Part
    // take the map and construct the non_terminal_info for essam
    vector<Non_Terminal_Info> package_non_terminals(map<string,set<string>>follows, map<string, map<string, vector<string>>> firsts);


    // Essam's Part
    // take the info and turn them to table
    Parsing_Table grammer_table(vector<Non_Terminal_Info> info, string start_non_terminal);
    // my needed DataStructures:


};


#endif //COMPILER_PROJECT_CONTOLLER_H
