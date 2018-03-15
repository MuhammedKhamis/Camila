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

using namespace std;

int main() {
//	char str[] = "letter = 0-9 | 4545-Z | a-z";
//
//	Parser p;
//	p.parse(str);
//	Parser p;
//	char* str2 = "letter = 0-9 | A-Z | a-z";
//	p.parse(str2);
//	char str2[] = "relop: == | != | > | >= | < | <=";
//	p.parse(str2);

//	for (std::vector<char*>::iterator it = result.begin();
//			it != result.end(); ++it)
//		std::cout << *it << '\n';
	FileRulesReader frr;
	string path ("files/rules.txt");
	vector<string> lines = frr.read(path);
	for (std::vector<string>::iterator it = lines.begin(); it != lines.end();
			++it)
		std::cout << *it << '\n';
	return 0;
}
