/*
 * Def_Builder.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#include "Def_Builder.h"


static Builder* Builder::Instance(){
	static Def_Builder* instance;
	return instance;
}


void Def_Builder::evaluate_def(vector<string> definations){
	// input example => { letter, =, A, -, Z, a, -, z}
	// 				 => { letters, =, letter,+}

	vector<string> new_def;
	for(int i = 0 ; i <= defination_index ; i++){
		new_def.push_back(definations[i]);
	}
	for(int i = defination_index+1 ; i < definations.size() ; i++){
		if(to_val.find(definations[i]) == to_val.end()){
			// not found before
			new_def.push_back(definations[i]);
		}else{
			vector<string> temp = to_val[definations[i]];
			for(int j = 0 ; j < temp.size() ; j++){
				new_def.push_back(temp[j]);
			}
		}
	}
	// { letters, =, letter, + } => {letters, =, A, -, Z, a, -, z}
	to_val[definations.begin()] = new_def;
}

/**
 *  get the value of the definition
 *
 *  ex: digit => {0, -, 9}
 *  	digits => {digit, +} which is => {0, -, 9, +}
 *
 * */
vector<string> Def_Builder::get_def_value(string definition){
	vector<string> empty_vec;
	if(to_val.find(definition) == to_val.end()){
		return empty_vec ;
	}
	return to_val[definition];
}


