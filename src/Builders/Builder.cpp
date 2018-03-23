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
	vector<string> new_def = simplify_vector(definition);
	// { letters, =, letter, + } => {letters, =, A, -, Z, |, a, -, z}
	to_val[*definition.begin()] = new_def;
}

void Builder::evaluate_expression(vector<string> expression){

	//remove all ranges ex:"a-z -> a|b|c...|z"

	vector<string> new_exp = simplify_vector(expression);

	new_exp = convert_range(new_exp);

	saver.add_token(*expression.begin());

	// call postfix generator for that new vector

	string token = *expression.begin();

	postfix_processing(new_exp,token);

}
void Builder::evaluate_keyword(vector<string> keywords){

	for(unsigned int i = 0 ; i < keywords.size() ; i++){
		vector<string> new_keyword;
		for(unsigned int j = 0 ; j < keywords[i].size(); j++){
			if(j && keywords[i][j-1] != '\\'){
				// to put # before next character
				new_keyword.push_back(concat_symbol);
			}
			new_keyword.push_back(char_to_string(keywords[i][j]));
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
	return !( current == ')' || look_back == '('||
			  look_back == '|' || current == '|' ||
			  current == '-' || look_back == '-'  ||
			  current == '*' || current == '+' ||
			  look_back == '\\' || current == '#' ||
			  look_back == '#');

}


vector<string> Builder::simplify_vector(vector<string> vec){

	vector<string> new_vec;
	for(unsigned int i = type_index+1 ; i < vec.size() ; i++){
		if(vec[i] == lambda){
			new_vec.push_back(lambda);
			continue;
		}
		if(to_val.find(vec[i]) == to_val.end()){
			// not found before
			for(unsigned int j = 0 ; j < vec[i].size() ; j++){
				if(j && vec[i][j-1] != '\\'){
					new_vec.push_back(concat_symbol);
				}
				new_vec.push_back(char_to_string(vec[i][j]));
			}
		}else{
			// we saved that string before
			vector<string> temp = to_val[vec[i]];
			new_vec.push_back("(");
			for(unsigned int j = 0 ; j < temp.size() ; j++){
				new_vec.push_back(temp[j]);
			}
			new_vec.push_back(")");
		}
	}
	// put the hashes to indicate the concatenation
	vector<string> return_vec;
	string look_back = "\n";
	for(unsigned int i = 0 ; i < new_vec.size(); i++){

		if( i && add_concat(string_to_char(look_back),string_to_char(new_vec[i])) ){
			return_vec.push_back(concat_symbol);
		}

		return_vec.push_back(new_vec[i]);
		look_back = new_vec[i];
	}
	return return_vec;
}


/*
 converts each range sign to group of (or)s
*/
vector<string> Builder::convert_range(vector<string> str)
{
	string upper_case[] = {"(","A","|","B","|","C","|","D","|","E","|","F","|","G","|","H","|","I","|","J","|","K","|","L","|","M","|","N","|","O","|","P","|","Q","|","R","|","S","|","T","|","U","|","V","|","W","|","X","|","Y","|","Z",")"};
	string lower_case[] = {"(","a","|","b","|","c","|","d","|","e","|","f","|","g","|","h","|","i","|","j","|","k","|","l","|","m","|","n","|","o","|","p","|","q","|","r","|","s","|","t","|","u","|","v","|","w","|","x","|","y","|","z",")"};
	string digits []    = {"(","0","|","1","|","2","|","3","|","4","|","5","|","6","|","7","|","8","|","9",")"};
	    for(unsigned int i=0; i<str.size(); i++)
	    {
	        if(str[i] == "-" && str[i-1] == "A") //range sign
	        {   str.insert(str.begin()+i+2, upper_case, upper_case+53);
	            str.erase(str.begin()+i-1,str.begin()+i+2);
	        }else if(str[i] == "-" && str[i-1] == "a") //range sign
	        {   str.insert(str.begin()+i+2,lower_case, lower_case+53);
	            str.erase(str.begin()+i-1,str.begin()+i+2);
	        }else if(str[i] == "-" && str[i-1] == "0") //range sign
	        {   str.insert(str.begin()+i+2,digits, digits+21);
	            str.erase(str.begin()+i-1,str.begin()+i+2);
	        }
	    }
	    return str;
}

void Builder::postfix_processing(vector<string> exp , string token){

	Postfix_handler& post_handler = Postfix_handler::get_Instance();


	vector<string> postfix_exp = post_handler.to_postfix(exp);


	post_handler.evaluate_postfix(postfix_exp, token);

}

Builder& Builder::get_Instance(){
	static Builder instance;
	return instance;
}




