//
// Created by muhammed on 04/04/18.
//

#ifndef LEXICAL_ANALYZER_GENERATOR_SYMBOL_TABLE_ITERATOR_H
#define LEXICAL_ANALYZER_GENERATOR_SYMBOL_TABLE_ITERATOR_H

#include <bits/stdc++.h>
#include "Symbol_table.h"

using namespace std;

class Symbol_table;

class Symbol_table_iterator {

public:

    Symbol_table_iterator(const Symbol_table *table);

    bool next();

    string current_token();

    string current_symbol();

private:
    int index;
    const Symbol_table* table;
};


#endif //LEXICAL_ANALYZER_GENERATOR_SYMBOL_TABLE_ITERATOR_H
