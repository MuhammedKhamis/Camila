/*
 * State.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: muhammed
 */

#include "State.h"
#include "../General/Enums.h"


State::State(priority p , string token,int id){
	this->p = p;
	this->token = token;
	this->id = id;
}

priority State::get_priority(){
	return p;
}

string State::get_token(){
	return token;
}

int State::get_id(){
	return id;
}

