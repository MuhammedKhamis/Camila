//
// Created by muhammed on 16/04/18.
//

#include "Parsing_Table_Generator.h"
#include "../../Lexical/General/functions.h"

Parsing_Table_Generator::Parsing_Table_Generator(vector<Non_Terminal_Info> &non_terminal_info):
        non_terminal_info(non_terminal_info) {}


Parsing_Table Parsing_Table_Generator::generate_table() {

    unordered_map<string,unordered_map<string,Production>> table;

    if(non_terminal_info.size() != non_terminals.size()){
        return table;
    }

    for (int i = 0; i < non_terminals.size() ; ++i) {

        // make new table entry for the non_terminal node.
        table[non_terminals[i]] = unordered_map<string,Production>();
        // get the first_production_pairs pair
        vector<First_Production_Pair> fpp =  non_terminal_info[i].get_first_production_pairs();

        // true if there is a lambda in the first
        bool put_follow = false;

        for(int j = 0; j < fpp.size(); ++j) {
            // terminal string.
            string input = fpp[j].getFirst().get_value();
            // check if the one of the first is lambda then we put the follow also in the table
            put_follow = put_follow | (input==lambda);
            // put the production corresponding to its non_terminal and its input terminal
            table[non_terminals[i]][input] = fpp[j].getProduction();
        }

        // follows of the non_terminal node.
        vector<Follow> follows = non_terminal_info[i].get_follows();
        // lambda production that contain lambda transition.
        vector<string> lambda_production = {lambda};
        for(int j = 0 ; j < follows.size() ; ++j){
            // if we will put the follow too.
            if(put_follow){
                // put new production with lambda transition and non_terminal as current non_terminal
                table[non_terminals[i]][follows[j].get_value()] = Production(lambda_production,non_terminals[i]);
            }else{
                // put sync production
                table[non_terminals[i]][follows[j].get_value()] = Production();
            }
        }


    }

    Parsing_Table pt(table);
    return pt;

}