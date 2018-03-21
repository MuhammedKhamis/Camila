/*
 * Token_Saver.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: muhammed
 */

#include "Token_Saver.h"


void Token_Saver::add_token(string token){
	token_lvl[token] = level--;
}

int Token_Saver::get_token_level(string token){
	if(token_lvl.find(token) == token_lvl.end()){
		return INT_MIN;
	}
	return token_lvl[token];
}


Token_Saver& Token_Saver::get_Instance(){
	static Token_Saver instance;
	return instance;
}

