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

using namespace std;

int main() {

	RulesParser rp;
	FileRulesReader frr;
	string path("files/rules.txt");
	vector<string> lines = frr.read(path);

	Builder& b = Builder::get_Instance();

	Thomson_Builder& t = Thomson_Builder::get_Instance();

	Node* start = t.assemble_saved_graphs();

	Subset_Builder *sb = new Subset_Builder();

	Transition_Table* table = sb->convert_to_DFA(start);

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
