//
// Created by muhammed on 25/04/18.
//

#include "FF_Generator.h"


vector<Non_Terminal_Info> FF_Generator::get_Non_Terminals_info(vector<pair<string, set<string>>> ms) {

    normalize_input(ms);


}

void FF_Generator::normalize_input(vector<pair<string,set<string>>> ms) {
    start_non_terminal = ms.begin()->first;
    for(int i  = 0 ; i < ms.size() ; i++){
        line ln(ms[i].first);
        vector<part> parts;
        for(auto it = ms[i].second.begin() ; it != ms[i].second.end() ; it++){
            get_parts(parts, *it);
        }
        element elem(parts,ms[i].first);
        ln.add_element(elem);
    }
}

void FF_Generator::get_parts(vector<part> &parts, string elem) {
    for(int i = 0 ; i < elem.size() ; i++){

    }
}

void FF_Generator::get_firsts() {

}

void FF_Generator::get_follows() {

}

