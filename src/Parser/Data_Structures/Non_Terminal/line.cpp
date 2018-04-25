//
// Created by muhammed on 25/04/18.
//

#include "line.h"

line::line(string non_terminal) : non_terminal(non_terminal) {}

line::line() {}


void line::add_element(element elem) {
    this->productions.emplace_back(elem);
}

vector<string> line::get_follows(string &val) {
    vector<string> follows;
    for(int i = 0 ; i < productions.size() ; i++){
        productions[i].add_follow(follows,val);
    }
    return follows;
}

void line::setNon_terminal(string non_terminal) {
    line::non_terminal = non_terminal;
}
