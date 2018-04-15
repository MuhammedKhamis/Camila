//
// Created by muhammed on 04/04/18.
//

#include "Symbol_table.h"

void Symbol_table::add_token(string token, string symbol) {

    pair<string,string> item = make_pair(token,symbol);

    this->table.emplace_back(item);
}

void Symbol_table::print_table() {
    for(int i = 0 ; i < table.size() ; i++){
        cout << "Token: " << table[i].first << ", " << "Symbol: " << table[i].second;
        cout << endl;
    }
}

Symbol_table_iterator* Symbol_table::get_iterator() const {
    return new Symbol_table_iterator(this);
}

