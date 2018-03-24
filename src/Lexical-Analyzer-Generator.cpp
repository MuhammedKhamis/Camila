//============================================================================
// Name        : Lexical-Analyzer-Generator.cpp
// Author      : Muhammed Essam Khamis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include "Builders/Thomson_Builder.h"
#include "Graph/Graph.h"
#include "Graph/Node.h"
#include "Builders/Subset_Builder.h"
#include "Data_Structure/Token_Saver.h"
#include "Builders/Builder.h"
#include "Machines/Transition_Table.h"
#include "Rules_Parser/Rules.h"
#include "Rules_Parser/FileRulesReader.h"
#include "Rules_Parser/RulesParser.h"
#include "Minimizer/Group.h"
#include "Minimizer/Groups.h"
#include "Minimizer/Minimizer.h"
#include "Machines/Machine.h"
#include "Machines/State.h"
#include "Files_Handler/FileReader.h"
#include "General/functions.h"

using namespace std;

File_Reader fr ;

string scan_file(string src_code,Machine* m){

		State* current = m->get_start();
		State* last_correct_state = current;
		int last_correct_index = 0;

		string output="";

		for(unsigned int i = 0 ; i < src_code.size();i++){
			bool res = m->next(current,char_to_string(src_code[i]));
			if(res){
				current = m->get_current();
				// correct transition
				if(current->get_priority() == valid){
					last_correct_state = current;
					last_correct_index = i;
				}
			}else{
				// bad transition
				if(last_correct_state->get_priority() == valid){
					output+= last_correct_state->get_token();
					output+= '\n';
					i = last_correct_index;
				}else{
					i = ++last_correct_index;
				}
				current = m->get_start();
				last_correct_state = current;
			}
		}
		return output;
}

string run(string rules_file , string input_file){

	string output = "";

	// reading Rules
	RulesParser rp;
	FileRulesReader frr;
	string path(rules_file);
	vector<string> lines = frr.read(path);

	if(lines.empty()){
		return output;
	}

	// NFA creation
	Rules r = rp.parse_lines(lines);
	Node* start = r.parse_nfa();


	// DFA creation.
	Subset_Builder *sb = new Subset_Builder();
	Transition_Table* table = sb->convert_to_DFA(start);

	// minimized DFA
	Minimizer * minimizer = new Minimizer(table);

	Transition_Table* minimized_table = minimizer->get_minimized();

	Machine* m = new Machine(minimized_table);


	//minimized_table->print_table();

  
	// try to read the src code.
	if(!fr.read_file(input_file)){
		perror("Source code file is not found.\n");
		return "";
	}
	 // scanning input file
  	 cout << "Scanning.........\n";

  	 string src_code = fr.src_code();

  	 output = scan_file(src_code,m);

  	 return output;
}


void terminal_output(string rules_file , string input_file){
	string output = run(rules_file,input_file);
	cout << output;

}

void file_output(string rules_file , string input_file, string output_file){
	string output = run(rules_file,input_file);
	if(!fr.write_file(output,output_file)){
		perror("Error in Writing to the file\n");
	}
}

int main(int argc, char** argv) {


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


	/*
		// Just Testing
		string rules_file = "src/files/rules.txt";
		string input_file = "a.txt";
		terminal_output(rules_file,input_file);
	*/
	return 0;
}
