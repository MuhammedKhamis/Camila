//============================================================================
// Name        : Lexical-Analyzer-Generator.cpp
// Author      : Muhammed Essam Khamis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

#include "Parser/Grammar_parser/Input_reader.h"

using namespace std;

int main(int argc, char** argv) {

	Input_reader ir;

	vector<string> v =	ir.read("../test.txt");

    int n = v.size();

    for(int i=0; i<n; i++)
    {
    	cout << v[i] << '\n';
    }

	return 0;
}

