/*
 * Rules.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: muhammed
 */
#include "Rules.h"


Rules::Rules(){
	 order_order = 0;
	keywords_order = 0 ;
	punctuations_order = 0;
	definitions_order = 0;
	expressions_order = 0;
}

	void Rules::add_keyword(vector<string> keyword){
		order.push_back(keyword_index);
		keywords.push_back(keyword);
	}

	void Rules::add_punctuations(vector<string> punc){
		order.push_back(punctuations_index);
		punctuations.push_back(punc);
	}

	void Rules::add_definitions(vector<string> def){
		order.push_back(definitions_index);
		definitions.push_back(def);

	}

	void Rules::add_expressions(vector<string> exp){
		order.push_back(expressions_index);
		expressions.push_back(exp);
	}

	Node* Rules::parse_nfa(){

		return parse_nfa_priority();

	}
	Node* Rules::parse_nfa_ordered(){

		for(unsigned int i = 0 ; i < order.size();i++){
			if(order[i] == keyword_index){
				b.evaluate_keyword(keywords[keywords_order++]);
			}else if(order[i] == punctuations_index){
				b.evaluate_punctuation(punctuations[punctuations_order++]);
			}else if(order[i] == definitions_index){
				b.evaluate_definition(definitions[definitions_order++]);
			}else{
				b.evaluate_expression(expressions[expressions_order++]);
			}
		}
		return t.assemble_saved_graphs();
	}

	Node* Rules::parse_nfa_priority(){

		for(unsigned int i = 0 ; i < keywords.size();i++){
			b.evaluate_keyword(keywords[i]);
		}

		for(unsigned int i = 0 ; i < punctuations.size();i++){
				b.evaluate_punctuation(punctuations[i]);
		}

		for(unsigned int i = 0 ; i < definitions.size();i++){
				b.evaluate_definition(definitions[i]);
		}
		for(unsigned int i = 0 ; i < expressions.size();i++){
				b.evaluate_expression(expressions[i]);
		}

		return t.assemble_saved_graphs();

	}
