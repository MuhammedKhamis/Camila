//
// Created by muhammed on 25/04/18.
//

#ifndef COMPILER_PROJECT_FF_GENERATOR_H
#define COMPILER_PROJECT_FF_GENERATOR_H

#include <bits/stdc++.h>
#include "../Non_Terminal_Package/Non_Terminal_Info.h"
#include "../Data_Structures/Non_Terminal/non_terminal.h"
using namespace std;

class FF_Generator {
public:
    vector<Non_Terminal_Info> get_Non_Terminals_info(vector<pair<string,set<string>>> ms);
private:
    void normalize_input(vector<pair<string,set<string>>> ms);

    void get_parts(vector<part> &parts, string elem);

    void get_firsts();
    void get_follows();
    vector<Non_Terminal> non_terminals;
    string start_non_terminal;
};


#endif //COMPILER_PROJECT_FF_GENERATOR_H
