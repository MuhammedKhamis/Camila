//
// Created by muhammed on 16/04/18.
//

#include "Parsing_Table_Generator.h"
#include "../../Lexical/General/functions.h"

Parsing_Table_Generator::Parsing_Table_Generator(vector<Non_Terminal_Info> &non_terminal_info,string &start_non_terminal):
        non_terminal_info(non_terminal_info), start_non_terminal(start_non_terminal) {}

Parsing_Table Parsing_Table_Generator::generate_table() {

    unordered_map<string,unordered_map<string,Production>> table;


    for (int i = 0; i < non_terminal_info.size() ; ++i) {

        string non_terminal_val = non_terminal_info[i].get_non_terminal();

        // make new table entry for the non_terminal node.
        table[non_terminal_val] = unordered_map<string,Production>();
        // get the first_production_pairs pair
        vector<First_Production_Pair> fpp =  non_terminal_info[i].get_first_production_pairs();

        // true if there is a lambda in the first
        bool put_follow = false;

        for(int j = 0; j < fpp.size(); ++j) {
            // terminal string.
            string input = fpp[j].getFirst().get_value();
            // check if the one of the first is lambda then we put the follow also in the table
            put_follow = put_follow | (input== "\\L");
            // put the production corresponding to its non_terminal and its input terminal
            table[non_terminal_val][input] = fpp[j].getProduction();
        }

        // follows of the non_terminal node.
        vector<Follow> follows = non_terminal_info[i].get_follows();
        // lambda production that contain lambda transition.
        vector<string> lambda_production = {lambda};
        for(int j = 0 ; j < follows.size() ; ++j){
            // if we will put the follow too.
            string follow_val = follows[j].get_value();
            if(put_follow){
                if(table[non_terminal_val].find(follow_val) != table[non_terminal_val].end()){
                    // that follow was found as first in this set then this Grammar is ambiguous
                    if(follow_val == "'\\L'"){
                        continue;
                    }
                    string msg = "This Given Grammar is ambiguous, "
                                 + follow_val + " was found as first and follow in the " + non_terminal_val + " line\n";
                    cout << msg;
                    exit(0);
                }
                // put new production with lambda transition and non_terminal as current non_terminal
                table[non_terminal_val][follow_val] = Production(lambda_production,non_terminal_val);
            }else{
                // put sync production
                if(table[non_terminal_val].find(follow_val) == table[non_terminal_val].end()){
                    table[non_terminal_val][follow_val] = Production();
                }
            }
        }


    }

    Parsing_Table pt(table,start_non_terminal);
    return pt;

}