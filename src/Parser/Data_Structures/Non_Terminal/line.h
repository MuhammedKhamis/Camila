//
// Created by muhammed on 25/04/18.
//

#ifndef COMPILER_PROJECT_LINE_H
#define COMPILER_PROJECT_LINE_H

#include <bits/stdc++.h>
#include "../Production/Production.h"
#include "element.h"

using namespace std;

class line {

public:

    line();

    line( string non_terminal);


    void setNon_terminal( string non_terminal);

    void add_element(element elem);

    vector<string> get_follows(string &val);

private:
    string non_terminal;
    vector<element> productions;

};


#endif //COMPILER_PROJECT_LINE_H
