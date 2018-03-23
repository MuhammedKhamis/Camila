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


void scan_file(string src_code,Machine* m){

		State* current = m->get_start();
		State* last_correct_state = current;
		int last_correct_index = 0;

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
					cout << last_correct_state->get_token() << endl;
					i = last_correct_index;
				}else{
					i = ++last_correct_index;
				}
				current = m->get_start();
				last_correct_state = current;
			}
		}
}

int main() {

	int start_s=clock();


	RulesParser rp;
	FileRulesReader frr;
	string path("src/files/rules.txt");
	vector<string> lines = frr.read(path);

	Rules r = rp.parse_lines(lines);

	Node* start = r.parse_nfa();


	Subset_Builder *sb = new Subset_Builder();


	Transition_Table* table = sb->convert_to_DFA(start);

	Minimizer * minimizer = new Minimizer(table);



	Machine* m = new Machine(minimizer->get_minimized());
  


	File_Reader fr ;

  if(!fr.read_file("a.txt")){
	  cout << "Error\n";
	  return 0;
  }
  	  scan_file(fr.src_code(),m);

  	  int stop_s=clock();

	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

	return 0;
}
