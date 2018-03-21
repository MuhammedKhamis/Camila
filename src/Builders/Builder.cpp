/*
 * Builder.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: muhammed
 */

#include "Builder.h"

#include "Postfix_handler.h"



void Builder::evaluate_definition(vector<string> definition){
	// input example => { letter, =, A, -, Z, |, a, -, z}
	// 				 => { letters, =, letter,+}
	vector<char> new_def = simplify_vector(definition);
	// { letters, =, letter, + } => {letters, =, A, -, Z, |, a, -, z}
	to_val[*definition.begin()] = new_def;
}

void Builder::evaluate_expression(vector<string> expression){
	//remove all ranges ex:"a-z -> a|b|c...|z"
	expression = convert_range(expression);
	vector<char> new_exp = simplify_vector(expression);
	saver.add_token(*expression.begin());
	//TODO
	// call postfix generator for that new vector
	string token = *expression.begin();
	postfix_processing(new_exp,token);

}
void Builder::evaluate_keyword(vector<string> keywords){

	for(unsigned int i = 0 ; i < keywords.size() ; i++){
		vector<char> new_keyword;
		for(unsigned int j = 0 ; j < keywords[i].size(); j++){
			if(j){
				// to put # before next character
				new_keyword.push_back(concat_symbol);
			}
			new_keyword.push_back(keywords[i][j]);
		}
		saver.add_token(keywords[i]);

		// call postfix for this vector to generate, evaluate, create
		postfix_processing(new_keyword,keywords[i]);
	}
}

void Builder::evaluate_punctuation(vector<string> punc){
	evaluate_keyword(punc);
}

bool Builder::add_concat(char look_back, char current){
	return (isalnum(look_back) && isalnum(current)) ||
			(isalnum(look_back) && current == '(') ||
			(look_back == ')' && isalnum(current)) ||
			(look_back == ')' && current == '(' ) ||
			((look_back == '*' || look_back == '+') && ( isalnum(current)|| current == '('));
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

		if(add_concat(look_back,new_vec[i])){
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

/*
 converts each range sign to group of (or)s
*/
vector<string> Builder::convert_range(vector<string> str)
{
    string upper_case[] = {"A","|","B","|","C","|","D","|","E","|","F","|","G","|","H","|","I","|","J","|","K","|","L","|","M","|","N","|","O","|","P","|","Q","|","R","|","S","|","T","|","U","|","V","|","W","|","X","|","Y","|","Z"};
    string lower_case[] = {"a","|","b","|","c","|","d","|","e","|","f","|","g","|","h","|","i","|","j","|","k","|","l","|","m","|","n","|","o","|","p","|","q","|","r","|","s","|","t","|","u","|","v","|","w","|","x","|","y","|","z"};
    string digits []    = {"0","|","1","|","2","|","3","|","4","|","5","|","6","|","7","|","8","|","9"};
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == "-" && str[i-1] == "A") //range sign
        {   str.insert(str.begin()+i+2, upper_case, upper_case+51);
            str.erase(str.begin()+i-1,str.begin()+i+2);
        }else if(str[i] == "-" && str[i-1] == "a") //range sign
        {   str.insert(str.begin()+i+2,lower_case, lower_case+51);
            str.erase(str.begin()+i-1,str.begin()+i+2);
        }else if(str[i] == "-" && str[i-1] == "0") //range sign
        {   str.insert(str.begin()+i+2,digits, digits+19);
            str.erase(str.begin()+i-1,str.begin()+i+2);
        }
    }
    return str;
}

void Builder::postfix_processing(vector<char> exp , string token){
	Postfix_handler& post_handler = Postfix_handler::get_Instance();

	string postfix_exp = post_handler.to_postfix(exp);

	// get the postfix and evaluate it
	// build the thomson graph while evaluating
	post_handler.evaluate_postfix(postfix_exp, token);
}

Builder& Builder::get_Instance(){
	static Builder instance;
	return instance;
}



