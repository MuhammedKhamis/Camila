//
// Created by muhammed on 25/04/18.
//

#include "Parser_Controller.h"


Parsing_Table Parser_Controller::generate_table(string path) {

    // Rafaat's Part
    map<string,set<string>> rules = this->split_input(path);


    // generate first and follow, Murad's Part
    vector<Non_Terminal_Info> info = this->package_non_terminals(rules);
    string start_non_terminal = info.begin()->get_non_terminal();

    // Essam's Part
    Parsing_Table t = grammer_table(info, start_non_terminal);

    return t;

}


map<string,set<string>> Parser_Controller::split_input(string path){
    Input_reader reader;
    vector<string> input_lines = reader.read(path);
    Input_parser ip;
    map<string,set<string>> rules = ip.get_rules_map(input_lines);
    return rules;
};

vector<Non_Terminal_Info> Parser_Controller::package_non_terminals(map<string,set<string>> rules){
    // TODO by Murad
    first_follow_generator ffg(rules);
    // Pack the non_terminal info for essam's part
}

Parsing_Table Parser_Controller::grammer_table(vector<Non_Terminal_Info> info,string start_non_terminal){

    Parsing_Table_Generator table_generator(info,start_non_terminal);
    return table_generator.generate_table();
}


