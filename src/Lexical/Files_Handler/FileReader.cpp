/*
 * FileReader.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: muhammed
 */

#include "FileReader.h"

File_Reader::File_Reader() {
	// TODO Auto-generated constructor stub
}

File_Reader::~File_Reader() {
	// TODO Auto-generated destructor stub
}
bool File_Reader::read_file(const string path){
	is.open(path,ifstream::in);
	return !!is;
}

bool File_Reader::write_file(string file , string path){
	os.open(path,ofstream::out);

	if(!os.is_open()){
		return false;
	}

	os << file;
	os.close();

	return true;
}

string File_Reader::src_code(){
	string s;
	char c;
	while(is.get(c)){
		s+=c;
	}
	is.close();
	return s;
}
