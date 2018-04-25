//
// Created by muhammed on 25/04/18.
//

#include "non_terminal.h"


Non_Terminal::Non_Terminal( line lne,  string non_terminal,  int id) :
        lne(lne), non_terminal(non_terminal), id(id) {}


void Non_Terminal::set_group_id(int g_id) {
    group_id = g_id;
}

const string &Non_Terminal::getNon_terminal() const {
    return non_terminal;
}

int Non_Terminal::getGroup_id() const {
    return group_id;
}

int Non_Terminal::getId() const {
    return id;
}

vector<string> Non_Terminal::get_follows(string &val) {
    return lne.get_follows(val);
}