//
// Created by muhammed on 25/04/18.
//

#ifndef COMPILER_PROJECT_PARSER_CONTROLLER_H
#define COMPILER_PROJECT_PARSER_CONTROLLER_H

#include <bits/stdc++.h>
#include "../Non_Terminal_Package/Non_Terminal_Info.h"
#include "../Parsing_Table/Parsing_Table.h"
#include "../Parsing_Table_Generator/Parsing_Table_Generator.h"
#include "../Grammar_parser/Input_parser.h"
#include "../Grammar_parser/Input_reader.h"
#include "../First_follow_finder/first_follow_generator.h"

using namespace std;

class Parser_Controller {

public:

    Parsing_Table generate_table(string path);

private:

    // Rafaat's Part
    // take input and split it for murad
    map<string,set<string>> split_input(string path);


    // Murad's Part
    // take the map and construct the non_terminal_info for essam
    // Expected that the first non_terminal is the starting non_terminal.
    vector<Non_Terminal_Info> package_non_terminals(map<string,set<string>> rules);


    // Essam's Part
    // take the info and turn them to table
    Parsing_Table grammer_table(vector<Non_Terminal_Info> info, string start_non_terminal);
    // my needed DataStructures:


};


#endif //COMPILER_PROJECT_CONTOLLER_H
