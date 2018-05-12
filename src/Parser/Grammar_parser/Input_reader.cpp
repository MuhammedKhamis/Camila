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
bool Input_reader::SkipBOM(std::istream &in) {
        char test[4] = {0};
        in.read(test, 3);
        if (strcmp(test, "\xEF\xBB\xBF") == 0)
            return true;
        in.seekg(0);
        return false;
}

vector<string> Input_reader::read(string path) {
    vector<string> lines;
    string line;
    ifstream file(path);
    SkipBOM(file);
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
