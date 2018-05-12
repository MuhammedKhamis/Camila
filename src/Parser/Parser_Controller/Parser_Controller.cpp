//
// Created by muhammed on 25/04/18.
//

#include "Parser_Controller.h"


Parsing_Table Parser_Controller::generate_table(string path) {

    // Rafaat's Part
    FF_Package rules = this->split_input(path);


    // generate first and follow, Murad's Part
    vector<Non_Terminal_Info> info = this->package_non_terminals(rules);
    string start_non_terminal = info.begin()->get_non_terminal();

    // Essam's Part
    Parsing_Table t = grammer_table(info, start_non_terminal);

    return t;

}


FF_Package Parser_Controller::split_input(string path){
    Input_reader reader;
    vector<string> input_str = reader.read(path);
    Input_parser ip;
    vector<Grammar_rule> res,input;
    input = ip.get_grammar_rules(input_str);
    LL1_handler ll1;

    res = ll1.convert_to_ll1(input);

    vector <string> res_str = ip.get_grammar_strings(res);
    FF_Package rules = ip.get_rules_map(input_str);
    return rules;
};

vector<Non_Terminal_Info> Parser_Controller::package_non_terminals(FF_Package rules){

    vector<Non_Terminal_Info> res;

    first_follow_generator ffg(rules.getProductions(),rules.getOrder_of_productions());

    ffg.generator();

    map<string,map<string,vector<string>>> first_production = ffg.get_firsts();
    map<string, set<string>> follows = ffg.get_follows();


    string first_non_terminal = *ffg.get_orders().begin();

    // For first non_terminal
    map<string,vector<string>> firsts = first_production[first_non_terminal];
    set<string> curr_follows = follows[first_non_terminal];
    Non_Terminal_Info ntf = package_non_terminal(first_non_terminal,firsts,curr_follows);
    res.emplace_back(ntf);

    // for the rest of them
    for(auto it = first_production.begin();it != first_production.end() ; it++){
        string non_terminal = it->first;
        if(non_terminal == first_non_terminal){
            continue;
        }
        map<string,vector<string>> firsts_loop = it->second;
        set<string> curr_follows_loop = follows[non_terminal];
        Non_Terminal_Info ntf_loop = package_non_terminal(non_terminal,firsts_loop,curr_follows_loop);
        res.emplace_back(ntf_loop);
    }
    return res;
}



Non_Terminal_Info Parser_Controller::package_non_terminal(string non_terminal, map<string, vector<string>> firsts,
                                                          set<string> follows) {
    vector<First_Production_Pair> fpps;
    for(auto it1 = firsts.begin() ; it1 != firsts.end() ; it1++){
        string first = it1->first;
        First f(first);

        vector<string> production = it1->second;
        Production p(production,non_terminal);

        First_Production_Pair fpp(p,f);

        fpps.emplace_back(fpp);
    }
    vector<Follow> fs;
    for(auto it1 = follows.begin() ; it1 != follows.end();it1++){
        Follow f(*it1);
        fs.emplace_back(f);
    }
    Non_Terminal_Info ntf(fpps,fs,non_terminal);
    return ntf;
}

Parsing_Table Parser_Controller::grammer_table(vector<Non_Terminal_Info> info,string start_non_terminal){

    Parsing_Table_Generator table_generator(info,start_non_terminal);
    return table_generator.generate_table();
}


