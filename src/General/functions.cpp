/*
 * functions.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: muhammed
 */



#include "functions.h"


string char_to_string(char c){
	return string(1,c);
}

char string_to_char(string s){
	return *(s.begin());
}
