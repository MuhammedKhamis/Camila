//
// Created by muhammed on 25/04/18.
//

#include "Parser_Controller.h"
#include "../Grammar_parser/Input_reader.h"


Parsing_Table Parser_Controller::generate_table(string path) {

    // parse lines, Rafaat's Part
    Input_reader reader;
    vector<string> input_lines = reader.read(path);
    map<string,vector<string>> ms = this->split_input(input_lines);

    // generate first and follow, Murad's Part
    map<string,set<string>> follow;
    map<string, map<string, vector<string>>> first;

    // packing them in one object, Essam's Part
    vector<Non_Terminal_Info> info = this->package_non_terminals(follow,first);
    string start_non_terminal;
    Parsing_Table t = grammer_table(info, start_non_terminal);

    return t;

}


map<string,vector<string>> Parser_Controller::split_input(vector<string> &input_lines){
    //TODO by Rafaat
};

vector<Non_Terminal_Info> Parser_Controller::package_non_terminals(map<string,set<string>>follows, map<string, map<string, vector<string>>> firsts){
    // TODO by Murad
    //
}

Parsing_Table Parser_Controller::grammer_table(vector<Non_Terminal_Info> info,string start_non_terminal){
    // TODO by Essam
    Parsing_Table_Generator table_generator(info,start_non_terminal);

    return table_generator.generate_table();
}


