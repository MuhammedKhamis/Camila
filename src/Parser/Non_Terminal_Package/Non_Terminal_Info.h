//
// Created by muhammed on 16/04/18.
//

#ifndef COMPILER_PROJECT_NON_TERMINAL_INFO_H
#define COMPILER_PROJECT_NON_TERMINAL_INFO_H

#include <bits/stdc++.h>

#include "../First/First.h"
#include "../Follow/Follow.h"
#include "../Production/Production.h"
#include "../First_Production_Pair/First_Production_Pair.h"
using namespace std;

class Non_Terminal_Info {
public:
    Non_Terminal_Info( vector<First_Production_Pair> &first_production,  vector<Follow> &follows,
                       string &non_terminal);

    Non_Terminal_Info( string &non_terminal);

    void add_first_production(First &f , Production &p);

    void add_first_production(First_Production_Pair &fpp);

    void add_follow(Follow &f);

    vector<First_Production_Pair> get_first_production_pairs();

    vector<Follow> get_follows();



private:
    vector<First_Production_Pair> first_production;
    vector<Follow> follows;
    string non_terminal;


};


#endif //COMPILER_PROJECT_NON_TERMINAL_INFO_H
