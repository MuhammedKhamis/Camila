//
// Created by muhammed on 26/04/18.
//

#include "FF_Package.h"

FF_Package::FF_Package(const map<string, set<string>> &productions, const vector<string> &order_of_productions)
        : productions(productions), order_of_productions(order_of_productions) {}

const map<string, set<string>> &FF_Package::getProductions() const {
    return productions;
}

const vector<string> &FF_Package::getOrder_of_productions() const {
    return order_of_productions;
}
