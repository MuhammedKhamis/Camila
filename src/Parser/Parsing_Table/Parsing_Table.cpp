//
// Created by muhammed on 16/04/18.
//

#include "Parsing_Table.h"

Parsing_Table::Parsing_Table(unordered_map<string, unordered_map<string, Production>> &table) : table(table) {}

vector<string> Parsing_Table::get_production(string non_terminal, string input) {

    if( table.find(non_terminal) == table.end() ){
        // non terminal not found
        return {};
    }
    if(table[non_terminal].find(input) == table[non_terminal].end()){
        return {};
    }
    return table.find(non_terminal)->second.find(input)->second.get_reversed_production();

}