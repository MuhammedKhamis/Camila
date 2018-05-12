//
// Created by muhammed on 25/04/18.
//

#include "part.h"

part::part(const string &val, bool type) : val(val), terminal(type) {}

const string &part::getVal() const {
    return val;
}

bool part::isTerminal() const {
    return terminal;
}
