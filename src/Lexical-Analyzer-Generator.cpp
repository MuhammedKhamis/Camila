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
#include "Machines/Machine.h"
#include "Machines/State.h"
#include "General/Enums.h"
#include "Files_Handler/FileReader.h"
using namespace std;


void scan_file(string src_code,Machine* m){

		State* current = m->get_start();
		State* last_correct_state = current;
		int last_correct_index = 0;

		for(unsigned int i = 0 ; i < src_code.size();i++){
			bool res = m->next(current,src_code[i]);
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

	File_Reader f;

	Builder& b = Builder::get_Instance();

	b.evaluate_expression({"kamel",":","a","h","m","e","d"});

	Thomson_Builder& t = Thomson_Builder::get_Instance();

	Node* start = t.assemble_saved_graphs();

	Subset_Builder *sb = new Subset_Builder();

	Machine* m = sb->convert_to_DFA(start);

	if(!f.read_file("a.txt")){
		cout << "error in reading file";
		return 0;
	}
	scan_file(f.src_code(),m);

	return 0;
}
