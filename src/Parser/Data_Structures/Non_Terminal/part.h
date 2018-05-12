//
// Created by muhammed on 25/04/18.
//

#ifndef COMPILER_PROJECT_PART_H
#define COMPILER_PROJECT_PART_H

#include <bits/stdc++.h>
using namespace std;

class part {

public:

    part(const string &val, bool type);

    const string &getVal() const;

    bool isTerminal() const;

private:
    string val;
    bool terminal;
};


#endif //COMPILER_PROJECT_PART_H
