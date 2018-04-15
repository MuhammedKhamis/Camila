/*
 * FileRulesReader.cpp
 *
 *  Created on: 15/3/2018
 *      Author: Murad
 */

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "FileRulesReader.h"

using namespace std;

vector<string> FileRulesReader::read(string path) {
	vector<string> lines;
		string line;
		ifstream file(path);
		if (!file) {
			perror("Cannot open lexical rules file.\n");
			return lines;
		}
		while (getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
		std::reverse(lines.begin(), lines.end());
		return lines;
}

