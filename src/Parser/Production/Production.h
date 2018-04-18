//
// Created by muhammed on 16/04/18.
//

#ifndef LEXICAL_ANALYZER_GENERATOR_PRODUCTION_H
#define LEXICAL_ANALYZER_GENERATOR_PRODUCTION_H

#include <bits/stdc++.h>
using namespace std;

/*
 *  Production class that have only one production of the non_terminal
 *  consists of vector of string that contain the parts of the production
 *  and the non_terminal that hold the non_terminal that cause this production
 *
 *  Ex A -> aBc | kDd
 *      then one Production will only contain:
 *             non_terminal = A, production = {a,B,c}
 *      second one will contain:
 *              non_terminal = A, production = {k,D,d}
 *
 *
 * */


class Production {

public:

    /*
     * Constructor used to build Production.
     *
     * */
    Production( vector<string> &production,  string &non_terminal);

    virtual ~Production();

    /*
     *
     *  Special constructor to build sync production for the parsing table.
     *
     * */

    Production();

    /*
     *  Other Constructors
     *
     * */
    Production(Production const& copy);

    Production& operator=(Production const& copy);

    Production(string &non_terminal);


    /*
     *
     *  Add part of the production to the object
     *
     * */

    void add_part(string &part);

    /*
     *  return reversed order elements of the production for the stack.
     *
     * */
    vector<string> get_reversed_production();

    /*
     * return elements of the production ordered by the calling of adding
     *
     * */
    vector<string> get_production();
    /*
     *
     *  get the non_terminal node value.
     * */
    string get_non_terminal();

protected:


private:

    vector<string> production;

    string non_terminal;


};


#endif //LEXICAL_ANALYZER_GENERATOR_PRODUCTION_H
