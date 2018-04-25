//
// Created by muhammed on 25/04/18.
//

#include "element.h"



element::element(vector<part> production,  string non_terminal) : production(production),
                                                                               non_terminal(non_terminal) {}

void element::add_follow(vector<string> &follows, string &elem) {
    for(int i = 0 ; i < production.size() ; i++){
        if(production[i].getVal() == elem && !production[i].isTerminal()){
            // found elem
            if(i == production.size()-1){
                // last element
                follows.emplace_back(lambda);
            }else{
                follows.emplace_back(production[i+1].getVal());
            }
        }
    }
}


void element::add_part(part part){
    this->production.emplace_back(part);
}

vector<string> element::get_production_vals(vector<part> &prod) {
    vector<string> parts_vals;
    for(int i = 0 ; i < prod.size();i++){
        parts_vals.emplace_back(prod[i].getVal());
    }
    return parts_vals;
}