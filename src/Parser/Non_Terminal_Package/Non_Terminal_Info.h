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


/*
 *
 *  non_terminal_info is an object that holds info for each non_terminal node
 *  including its follows, its value, and its first pair production.
 *
 *  mainly used to generate the table.
 *
 * */
class Non_Terminal_Info {
public:
    Non_Terminal_Info( vector<First_Production_Pair> &first_production,  vector<Follow> &follows,
                       string &non_terminal);

    Non_Terminal_Info( string &non_terminal);

    /*
     *
     * adding the firsdt_production pair to the info.
     *
     * */

    void add_first_production_pair(First &f, Production &p);

    void add_first_production_pair(First_Production_Pair &fpp);
    /*
     *
     *  adding the follow to the info
     *
     * */
    void add_follow(Follow &f);

    /*
     *
     *  getter for the first_production_pair
     *
     * */
    vector<First_Production_Pair> get_first_production_pairs();
    /*
     *
     *  getter for the follows()
     *
     */
    vector<Follow> get_follows();
    /*
     *
     *  getter for the non_terminal
     *
     * */
    string get_non_terminal();


private:
    vector<First_Production_Pair> first_production;
    vector<Follow> follows;
    string non_terminal;


};


#endif //COMPILER_PROJECT_NON_TERMINAL_INFO_H
