//============================================================================
// Name        : Lexical-Analyzer-Generator.cpp
// Author      : Muhammed Essam Khamis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include "Builders/Builder.h"

using namespace std;

int main() {

	Builder& b = Builder::get_Instance();

	vector<string> d1 = {"letter","=","A","-","Z","|","a","-","z"};
	vector<string> d2 = {"digit", "=", "0", "-", "9"};

	b.evaluate_definition(d1);
	b.evaluate_definition(d2);

	vector<string> ex1 = {"id", ":", "letter" , "digit","(" , "(" , "letter" , ")","|" , "(","digit", ")", ")" , "*" };
	b.evaluate_expression(ex1);


	return 0;
}
