//
// Created by muhammed on 16/04/18.
//

#ifndef COMPILER_PROJECT_PARSING_TABLE_GENERATOR_H
#define COMPILER_PROJECT_PARSING_TABLE_GENERATOR_H

#include <bits/stdc++.h>
#include "../Non_Terminal_Package/Non_Terminal_Info.h"
#include "../Parsing_Table/Parsing_Table.h"
#include "../Data_Structures/First_Production_Pair/First_Production_Pair.h"
#include "../Data_Structures/Production/Production.h"

using namespace std;

class Parsing_Table_Generator {

public:

    /*
     *  Constructor for the parse table generator that takes the non_terminals and their info
     *  as parameters each non_terminal_info object corresponds to its non_terminal
     *  in the other vector.
     *
     * */

    Parsing_Table_Generator(vector<Non_Terminal_Info> &non_terminal_info,string &start_non_terminal);

    /*
     * function that generate the parsing table with knowing the non_terminals and their info
     *  as first and its corresponding production and its follows.
     *
     * */
    Parsing_Table generate_table();

private:

    string start_non_terminal;
    vector<Non_Terminal_Info> non_terminal_info;


};


#endif //COMPILER_PROJECT_PARSING_TABLE_GENERATOR_H
