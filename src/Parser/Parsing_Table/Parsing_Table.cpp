//
// Created by muhammed on 16/04/18.
//

#include "Parsing_Table.h"

Parsing_Table::Parsing_Table(unordered_map<string, unordered_map<string, Production>> &table, string &start_Non_Terminal)
        : table(table), start_Non_Terminal(start_Non_Terminal) {
    for(auto it = table.begin() ; it != table.end() ; it++){
        string non_terminal = it->first;
        non_terminals.insert(non_terminal);
    }
}

vector<string> Parsing_Table::get_production(string non_terminal, string input) {

    if( table.find(non_terminal) == table.end() ){
        // non terminal not found
        return {};
    }
    if(table[non_terminal].find(input) == table[non_terminal].end()){
        return {};
    }
    return table[non_terminal][input].get_reversed_production();

}

string Parsing_Table::get_start_Non_Terminal() {
    return start_Non_Terminal;
}

bool Parsing_Table::is_non_terminal(string &non_terminal) {
    return non_terminals.count(non_terminal);
}

Type Parsing_Table::get_production_type(string non_terminal, string input) {
    if( table.find(non_terminal) == table.end() ){
        // non terminal not found
        return invalid_node;
    }
    if(table[non_terminal].find(input) == table[non_terminal].end()){
        return invalid_node;
    }
     return (table[non_terminal][input].get_non_terminal() == sync_val) ? sync_node: valid_node;
}

void Parsing_Table::print_table() {

    for(auto it = table.begin() ; it != table.end() ; it++){
        string non_terminal = it->first;
        unordered_map<string,Production> productions = it->second;
        cout << "Non Terminal: " << non_terminal << ": \n";
        for(auto it1 = productions.begin() ; it1 != productions.end() ; it1++){
            cout << "\tIts terminals: " << it1->first << ", Production: ";
            vector<string> production = it1->second.get_production();
            for(int i = 0 ; i < production.size() ; i++){
                cout << production[i];
            }
            cout <<  endl;
        }
    }
    cout << "-------------------------------------------------------------------------\n";
}