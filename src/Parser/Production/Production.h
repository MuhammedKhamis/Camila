//
// Created by muhammed on 16/04/18.
//

#ifndef LEXICAL_ANALYZER_GENERATOR_PRODUCTION_H
#define LEXICAL_ANALYZER_GENERATOR_PRODUCTION_H

#include <bits/stdc++.h>
using namespace std;

class Production {

public:

    Production( vector<string> &production,  string &non_terminal);

    virtual ~Production();

    //Production();

    Production(Production const& copy);

    Production& operator=(Production const& copy);

    Production(string &non_terminal);

    void add_part(string &part);

    vector<string> get_reversed_production();

    vector<string> get_production();

    string get_non_terminal();

protected:


private:

    vector<string> production;

    string non_terminal;


};


#endif //LEXICAL_ANALYZER_GENERATOR_PRODUCTION_H
