//============================================================================
// Name        : Lexical-Analyzer-Generator.cpp
// Author      : Muhammed Essam Khamis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

#include "Parser/Grammar_parser/Input_reader.h"

#include "Parser/Grammar_parser/Input_parser.h"

using namespace std;

int main(int argc, char** argv) {

	/*TESTING THE INPUT PARSER*/

	Input_reader ir;

	vector<string> v =	ir.read("../test.txt");

	Input_parser ip;

	map<string,set<string>> rules = ip.get_rules_map(v);

	int n = v.size();

	cout<<"Rules before map"<<endl<<endl;

    for(int i=0; i<n; i++)
    {
    	cout << v[i] << '\n';
    }

    cout<<"Rules After map"<<endl<<endl;

    map<string,set<string>> :: iterator itr;
    int i=1;
    for(itr = rules.begin(); itr !=rules.end(); ++itr)
    {
        	string rule_name = itr->first;
        	set<string> expressions = itr->second;
        	cout<<"rule "<<i<<": "<<rule_name<<" ";
        	set<string>:: iterator sitr;
        	for(sitr = expressions.begin(); sitr !=expressions.end(); ++sitr)
        	{
        		cout<< *sitr << " , ";
        	}
        	i++;
        	cout<<endl;
    }
	return 0;
}

