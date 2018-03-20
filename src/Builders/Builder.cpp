/*
 * Builder.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: muhammed
 */

#include "Builder.h"



void Builder::evaluate_definition(vector<string> definition){
	// input example => { letter, =, A, -, Z, |, a, -, z}
	// 				 => { letters, =, letter,+}
	vector<char> new_def = simplify_vector(definition);
	// { letters, =, letter, + } => {letters, =, A, -, Z, |, a, -, z}
	to_val[*definition.begin()] = new_def;
}

void Builder::evaluate_expression(vector<string> expression){
	vector<char> new_exp = simplify_vector(expression);
	saver.add_token(*expression.begin());
	//TODO
	// call postfix generator for that new vector
	// get the postfix and evaluate it
	// build the thomson graph while evaluating
}
void Builder::evaluate_keyword(vector<string> keywords){

	for(unsigned int i = 0 ; i < keywords.size() ; i++){
		vector<char> new_keyword;
		for(unsigned int j = 0 ; j < keywords[i].size(); i++){
			if(j){
				// to put # before next character
				new_keyword.push_back(concat_symbol);
			}
			new_keyword.push_back(keywords[i][j]);
		}
		saver.add_token(keywords[i]);

		// call postfix for this vector to generate, evaluate, create
	}
}

void Builder::evaluate_punctuation(vector<string> punc){
	evaluate_keyword(punc);
}



vector<char> Builder::simplify_vector(vector<string> vec){

	vector<char> new_vec;
	for(unsigned int i = type_index+1 ; i < vec.size() ; i++){
		if(to_val.find(vec[i]) == to_val.end()){
			// not found before
			new_vec.push_back(*vec[i].begin());
		}else{
			// we saved that string before
			vector<char> temp = to_val[vec[i]];
			for(unsigned int j = 0 ; j < temp.size() ; j++){
				new_vec.push_back(temp[j]);
			}
		}
	}
	// put the hashes to indicate the concatenation
	vector<char> return_vec;
	char look_back = 0;
	for(unsigned int i = 0 ; i < new_vec.size(); i++){
		if(is_operation(new_vec[i])){
			look_back = 0;
			return_vec.push_back(new_vec[i]);
			continue;
		}
		if(isalnum(look_back) && ( isalnum(new_vec[i]) || new_vec[i] == '(') ){
			return_vec.push_back(concat_symbol);
		}
		return_vec.push_back(new_vec[i]);
		look_back = new_vec[i];
	}
	return return_vec;
}

bool Builder::is_operation(char inp){
	return inp == concat_symbol || inp == plus_symbol || inp == star_symbol
		|| inp == or_symbol || inp == dash_symbol;
}

Builder& Builder::get_Instance(){
	static Builder instance;
	return instance;
}



