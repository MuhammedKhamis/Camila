//
// Created by muhammed on 25/04/18.
//

#include "Non_Terminal_mapper.h"

void Non_Terminal_mapper::add_nonTerminal(string &non_terminal, int id) {
    nonTerminal_to_id[non_terminal] = id;
}

int Non_Terminal_mapper::get_id(string &non_terminal) {
    if(nonTerminal_to_id.find(non_terminal) == nonTerminal_to_id.end()){
        return -1;
    }
    return nonTerminal_to_id[non_terminal];
}