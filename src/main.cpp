//============================================================================
// Name        : Lexical-Analyzer-Generator.cpp
// Author      : Muhammed Essam Khamis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

#include "Lexical/Scanner/Scanner.h"

using namespace std;

int main(int argc, char** argv) {

/*
	if(argc != 3 && argc != 4){
		string err = "Error Invalid size of the arguments\n";
			   err += "you may run it like this: ";
			   err += "./program rules_file input_file [output_file]";

		 perror(err.c_str());
		 return 0;
	}
	cout << "Running Program.......\n";

	int start_s=clock();

	// running....
	if(argc == 3){
		terminal_output(argv[1],argv[2]);
	}else{
		file_output(argv[1],argv[2],argv[3]);
	}

  	int stop_s=clock();

 	cout << "Done :D\n";

	cout << "total time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
*/
		// Just Testing
		string rules_file = "Lexical/files/rules.txt";
		string input_file = "../test_2.txt";
        Scanner *s = new Scanner;
    long long start_s=clock();

    s->terminal_output(rules_file,input_file);

    long long stop_s=clock();

    cout << "total time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    cout << "Input Parser Commit";


	return 0;
}

