/*
 * Inputreader.h
 *
 *  Created on: Apr 15, 2018
 *      Author: mishors
 */

#ifndef INPUTREADER_H_
#define INPUTREADER_H_

#include <bits/stdc++.h>

class Input_reader {
public:
	Input_reader();
	virtual ~Input_reader();
	/*
	 *  Reads the CFG input file returns each Grammar rule as a string in the output
	 *  string vector
	 *
	 *  Hint: If the grammar rule spanning multiple lines the function handles it to be in
	 *  one string
	 */
	std::vector<std::string> read(std::string path);

private:
	bool SkipBOM(std::istream & in);
};

#endif /* INPUTREADER_H_ */
