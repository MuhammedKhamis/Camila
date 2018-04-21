//
// Created by muhammed on 16/04/18.
//

#ifndef COMPILER_PROJECT_FIRST_H
#define COMPILER_PROJECT_FIRST_H

#include <bits/stdc++.h>
using namespace std;

class First {
    // to be implemented by Murad and Rafaat
public:
    virtual ~First(){};

    First(const string &value);

    string get_value()  ;

private:

    string value;
};


#endif //COMPILER_PROJECT_FIRST_H
