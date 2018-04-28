//
// Created by muhammed on 25/04/18.
//

#include "Parser_group.h"

Parser_group::Parser_group(int id) : id(id) {}


void Parser_group::add_follows(vector<string> follows) {
    for(int i = 0 ; i < follows.size();i++){
        this->follows.insert(follows[i]);
    }
}

void Parser_group::add_non_terminal_id(int id) {
    my_non_terminal_ids.insert(id);
}

bool Parser_group::in_my_group(int id) {
    return my_non_terminal_ids.count(id);
}