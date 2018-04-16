//
// Created by muhammed on 16/04/18.
//

#ifndef COMPILER_PROJECT_PARSING_TABLE_GENERATOR_H
#define COMPILER_PROJECT_PARSING_TABLE_GENERATOR_H

#include <bits/stdc++.h>
#include "../Non_Terminal_Package/Non_Terminal_Info.h"
#include "../Parsing_Table/Parsing_Table.h"
#include "../First_Production_Pair/First_Production_Pair.h"
#include "../Production/Production.h"

using namespace std;

class Parsing_Table_Generator {

public:
    Parsing_Table_Generator( vector<string> &non_terminals,  vector<Non_Terminal_Info> &non_terminal_info);

    Parsing_Table generate_table();

private:

    vector<string> non_terminals;
    vector<Non_Terminal_Info> non_terminal_info;


};


#endif //COMPILER_PROJECT_PARSING_TABLE_GENERATOR_H
