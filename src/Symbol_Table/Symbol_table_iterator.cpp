//
// Created by muhammed on 04/04/18.
//

#include "Symbol_table_iterator.h"

Symbol_table_iterator::Symbol_table_iterator(const Symbol_table *table) {
    this->table = table;
    this->index = 0;
}

bool Symbol_table_iterator::next(){

    if(index >= table->table.size()){
        return false;
    }
    index++;
    return true;
}

string Symbol_table_iterator::current_token(){
    return table->table[index].first;
}

string Symbol_table_iterator::current_symbol(){
    return  table->table[index].second;
}