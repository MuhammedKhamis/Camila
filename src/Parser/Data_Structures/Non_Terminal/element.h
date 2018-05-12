//
// Created by muhammed on 25/04/18.
//

#ifndef COMPILER_PROJECT_ELEMENT_H
#define COMPILER_PROJECT_ELEMENT_H

#include <bits/stdc++.h>
#include "part.h"
#include "../../../Lexical/General/functions.h"

using namespace std;


class element {


public:


    element( vector<part> production,  string non_terminal);

    void add_part(part part);

    void add_follow(vector<string> &follows,string &elem);

private:

    vector<string> get_production_vals(vector<part> &prod);

    vector<part> production;

    string non_terminal;
};


#endif //COMPILER_PROJECT_ELEMENT_H
