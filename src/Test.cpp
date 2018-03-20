//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include "FileRulesReader.h"

#include "RulesParser.h"
#include "Rules.h"

using namespace std;

int main() {

	RulesParser rp;
	FileRulesReader frr;
	string path("files/rules.txt");
	vector<string> lines = frr.read(path);
	for (std::vector<string>::iterator it = lines.begin(); it != lines.end();
			++it)
		std::cout << *it << '\n';
	Rules r = rp.parse_lines(lines);
	cout << "============== [1] keywords ===================" << '\n';
	for (unsigned int i = 0; i < r.keywords.size(); ++i) {
		vector<string> val = r.keywords[i];
		for (vector<string>::iterator it = val.begin();
				it != val.end(); ++it)
			cout << *it << '\n';
		cout << "====================================================" << '\n';
	}
	cout << "============== [2] punctuations ===================" << '\n';
	for (unsigned int i = 0; i < r.punctuations.size(); ++i) {
		vector<string> val = r.punctuations[i];
		for (vector<string>::iterator it = val.begin();
				it != val.end(); ++it)
			cout << *it << '\n';
		cout << "====================================================" << '\n';
	}
	cout << "============== [3] definitions ===================" << '\n';
	for (unsigned int i = 0; i < r.definitions.size(); ++i) {
		vector<string> val = r.definitions[i];
		for (vector<string>::iterator it = val.begin();
				it != val.end(); ++it)
			cout << *it << '\n';
		cout << "====================================================" << '\n';
	}
	cout << "============== [4] expressions ===================" << '\n';
	for (unsigned int i = 0; i < r.expressions.size(); ++i) {
		vector<string> val = r.expressions[i];
		for (vector<string>::iterator it = val.begin();
				it != val.end(); ++it)
			cout << *it << '\n';
		cout << "====================================================" << '\n';
	}

	for (vector<int>::iterator it = r.order.begin();
					it != r.order.end(); ++it)
				cout << *it << '\n';

	return 0;
}
