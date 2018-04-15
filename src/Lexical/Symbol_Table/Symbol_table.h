//
// Created by muhammed on 04/04/18.
//

#ifndef LEXICAL_ANALYZER_GENERATOR_SYMBOL_TABLE_H
#define LEXICAL_ANALYZER_GENERATOR_SYMBOL_TABLE_H

#include <bits/stdc++.h>

#include "Symbol_table_iterator.h"

using namespace std;

class Symbol_table_iterator;

class Symbol_table{
public:

    friend class Symbol_table_iterator;

    void add_token(string token , string symbol);

    void print_table();

    // symbol_table_iterator
    Symbol_table_iterator *get_iterator() const ;

protected:

private:
    vector<pair<string,string>> table;
};


#endif //LEXICAL_ANALYZER_GENERATOR_SYMBOL_TABLE_H
