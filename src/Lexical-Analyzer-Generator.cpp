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

using namespace std;

int main() {

	Builder& b = Builder::get_Instance();

	//b.evaluate_expression({"relop",":", "\=\=" ,"|" ,"!\=" ,"|", ">", "|" ,">\=" ,"|" ,"<" ,"|" ,"<\="});

	b.evaluate_expression({"mulop",":" ,"\\*" ,"|" ,"/"});

	/*
	RulesParser rp;
	FileRulesReader frr;
	string path("src/files/rules.txt");
	vector<string> lines = frr.read(path);

	Rules r = rp.parse_lines(lines);

	Node* start = r.parse_nfa();

	Subset_Builder *sb = new Subset_Builder();

	Transition_Table* table = sb->convert_to_DFA(start);



	/*
	Group accepted_group,non_accepted_group;

	unordered_map<int,unordered_map<char,int>> tab = table->get_table();

	for(auto it = tab.begin() ; it != tab.end();it++){

		int id = it->first;

		if(table->get_state(id)->get_priority() == valid){
			accepted_group.add(id);
		}else{
			non_accepted_group.add(id);
		}
	}
/*
	Groups g;
	g.add(accepted_group);
	g.add(non_accepted_group);
	*/

	/*

	// divide into 2 grups ac , not ac

	//  put them in group data structure
	Group accepted_group, non_accepted_group;
	//fill groups

	//add groups to Groups
	Groups g;
	g.add(accepted_group);
	g.add(non_accepted_group);
	*/
	return 0;
}
