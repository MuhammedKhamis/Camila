/*
 * Inputreader.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: mishors
 */

#include "Input_reader.h"

using namespace std;

Input_reader::Input_reader() {
	// TODO Auto-generated constructor stub

}

Input_reader::~Input_reader() {
	// TODO Auto-generated destructor stub
}

vector<string> Input_reader::read(string path) {
    vector<string> lines;
    string line;
    ifstream file(path);
    if (!file) {
        perror("Cannot open CFG input file.\n");
        return lines;
    }
    while (getline(file, line)) {

        //Handling rule spanning multiple lines
        if(line[0] != '#')
        {
        	lines.back().append(" ");
            lines.back().append(line);
        }
        else{
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}
