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
#include "../Data_Structures/First_Production_Pair/First_Production_Pair.h"
#include "../Data_Structures/First/First.h"
#include "../Data_Structures/Follow/Follow.h"
#include "../Data_Structures/Production/Production.h"
#include "../Data_Structures/First_Follow_Package/FF_Package.h"
#include "../Non_Terminal_Package/Non_Terminal_Info.h"
#include "../Grammar_parser/Grammar_rule.h"
#include "../LL1 - Conversion/LL1_handler.h"


using namespace std;

class Parser_Controller {

public:

    Parsing_Table generate_table(string path);

private:

    // Rafaat's Part
    // take input and split it for murad
    FF_Package split_input(string path);


    // Murad's Part
    // take the map and construct the non_terminal_info for essam
    // Expected that the first non_terminal is the starting non_terminal.
    vector<Non_Terminal_Info> package_non_terminals(FF_Package rules);


    Non_Terminal_Info package_non_terminal(string non_terminal,map<string,vector<string>> firsts,set<string> follows);


    // Essam's Part
    // take the info and turn them to table
    Parsing_Table grammer_table(vector<Non_Terminal_Info> info, string start_non_terminal);
    // my needed DataStructures:


};


#endif //COMPILER_PROJECT_CONTOLLER_H
