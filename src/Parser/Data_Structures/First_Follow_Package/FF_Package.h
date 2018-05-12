//
// Created by muhammed on 26/04/18.
//

#ifndef COMPILER_PROJECT_FF_PACKAGE_H
#define COMPILER_PROJECT_FF_PACKAGE_H

#include <bits/stdc++.h>
using namespace std;

class FF_Package {
public:

    FF_Package(const map<string, set<string>> &productions, const vector<string> &order_of_productions);

    const map<string, set<string>> &getProductions() const;

    const vector<string> &getOrder_of_productions() const;

private:

    map<string, set<string>> productions;

    vector<string> order_of_productions;
};


#endif //COMPILER_PROJECT_FF_PACKAGE_H
