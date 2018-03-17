/*
 * Builder.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: muhammed
 */

#include "Builder.h"



void Builder::evaluate_definition(vector<string> definition){
	// input example => { letter, =, A, -, Z, a, -, z}
	// 				 => { letters, =, letter,+}
	vector<string> new_def = simplify_vector(definition);
	// { letters, =, letter, + } => {letters, =, A, -, Z, a, -, z}
	to_val[*definition.begin()] = new_def;
}

void Builder::evaluate_expression(vector<string> expression){
	vector<string> new_exp = simplify_vector(expression);
	//TODO
	// call postfix generator for that new vector
	// get the postfix and evaluate it
	// build the thomson graph while evaluating
}
void Builder::evaluate_keyword(vector<string> keywords){

	for(unsigned int i = 0 ; i < keywords.size() ; i++){
		vector<string> new_keyword;
		for(unsigned int j = 0 ; j < keywords[i].size(); i++){
			if(j){
				// to put # before next character
				new_keyword.push_back(concat_symbol);
			}
			new_keyword.push_back(string(1,keywords[i][j]));
		}
		// call postfix for this vector to generate, evaluate, create
	}
}

void Builder::evaluate_punctuation(vector<string> punc){
	evaluate_keyword(punc);
}



vector<string> Builder::simplify_vector(vector<string> vec){

	vector<string> new_vec;
	for(unsigned int i = type_index+1 ; i < vec.size() ; i++){
		if(to_val.find(vec[i]) == to_val.end()){
			// not found before
			new_vec.push_back(vec[i]);
		}else{
			// we saved that string before
			vector<string> temp = to_val[vec[i]];
			for(unsigned int j = 0 ; j < temp.size() ; j++){
				new_vec.push_back(temp[j]);
			}
		}
	}
	return new_vec;
}

Builder& Builder::get_Instance(){
	static Builder instance;
	return instance;
}



