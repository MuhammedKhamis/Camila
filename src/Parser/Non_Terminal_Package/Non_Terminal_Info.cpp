//
// Created by muhammed on 16/04/18.
//

#include "Non_Terminal_Info.h"

Non_Terminal_Info::Non_Terminal_Info( vector<First_Production_Pair> &first_production,
                                      vector<Follow> &follows,  string &non_terminal) : first_production(
        first_production), follows(follows), non_terminal(non_terminal) {}

Non_Terminal_Info::Non_Terminal_Info( string &non_terminal) : non_terminal(non_terminal) {}


void Non_Terminal_Info::add_first_production(First &f, Production &p) {
    First_Production_Pair fpp(p,f);
    this->add_first_production(fpp);
}

void Non_Terminal_Info::add_first_production(First_Production_Pair &fpp) {
    this->first_production.emplace_back(fpp);
}

void Non_Terminal_Info::add_follow(Follow &f) {
    this->follows.emplace_back(f);
}

vector<Follow> Non_Terminal_Info::get_follows() {
    return this->follows;
}

vector<First_Production_Pair> Non_Terminal_Info::get_first_production_pairs() {
    return this->first_production;
}