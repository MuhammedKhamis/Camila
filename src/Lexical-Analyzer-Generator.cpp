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

using namespace std;

int main() {

	Thomson_Builder& t = Thomson_Builder::get_Instance();

	Graph* g1 = t.initialize_graph("a");
	t.save_graph(g1,"a");

	Graph* g2 = t.initialize_graph("b");
	t.save_graph(g2,"b");

	Graph* g3 = t.initialize_graph("c");
	g3 = t.star_operation(g3);

	t.save_graph(g3,"c*");

	Node* start = t.assemble_saved_graphs();

	Subset_Builder *sb = new Subset_Builder();

	Token_Saver& saver = Token_Saver::get_Instance();

	saver.add_token("");
	saver.add_token("a");
	saver.add_token("b");
	saver.add_token("c*");

	sb->convert_to_DFA(start);

	return 0;
}
