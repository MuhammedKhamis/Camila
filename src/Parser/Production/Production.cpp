//
// Created by muhammed on 16/04/18.
//

#include "Production.h"

Production::Production(vector<string> &production,  string &non_terminal) : production(production),
                                                                                       non_terminal(non_terminal) {}

Production::Production(string &non_terminal) : non_terminal(non_terminal) {}

Production::Production() {
    this->non_terminal = "sync";
}

Production::~Production() {}

Production& Production::operator=(Production const &copy) {

    if(this != &copy){
        this->non_terminal = copy.non_terminal;
        this->production = copy.production;
    }
    return *this;
}

Production::Production(Production const &copy) {
    this->non_terminal = copy.non_terminal;
    this->production = copy.production;
}



void Production::add_part(string &part){
    this->production.emplace_back(part);
}

vector<string> Production::get_reversed_production() {
    vector<string> reversed = production;
    reverse(reversed.begin(),reversed.end());
    return reversed;
}

vector<string> Production::get_production() {
    return production;
}

string Production::get_non_terminal() {
    return non_terminal;
}
