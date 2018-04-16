//
// Created by muhammed on 16/04/18.
//

#include "Parsing_Table_Generator.h"

Parsing_Table_Generator::Parsing_Table_Generator( vector<string> &non_terminals,
                                                  vector<Non_Terminal_Info> &non_terminal_info) : non_terminals(
        non_terminals), non_terminal_info(non_terminal_info) {}


Parsing_Table Parsing_Table_Generator::generate_table() {

    unordered_map<string,unordered_map<string,Production>> table;

    if(non_terminal_info.size() != non_terminals.size()){
        return table;
    }

    for (int i = 0; i < non_terminals.size() ; ++i) {

        table[non_terminals[i]] = unordered_map<string,Production>();
        vector<First_Production_Pair> fpp =  non_terminal_info[i].get_first_production_pairs();

        for (int j = 0; j < fpp.size(); ++j) {
            string input = fpp[j].getFirst().get_value();
            table[non_terminals[i]].find(input)->second = fpp[j].getProduction();
        }
    }

    Parsing_Table pt(table);
    return pt;

}