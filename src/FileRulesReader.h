/*
 * FileRulesReader.h
 *
 *  Created on: 15/3/2018
 *      Author: Murad
 */

#ifndef FILERULESREADER_H_
#define FILERULESREADER_H_

#include <vector>
#include <string>
#include <fstream>

class FileRulesReader {
public:
	/**
	 * read the lexical rules from the rules file.
	 * return a vector of string, each string represent a line from the file.
	 */
	std::vector<std::string> read(std::string path);
};

#endif /* FILERULESREADER_H_ */
