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

using namespace std;

int main() {


	Builder& b = Builder::get_Instance();

/*
	b.evaluate_keyword({"a","b"});

	b asdasd.evaluate_expression({"c*",":","c","*"});
*/
	b.evaluate_expression({"exp",":","(" , "b" , ")" ,"a"});


	Thomson_Builder& t = Thomson_Builder::get_Instance();

	Node* start = t.assemble_saved_graphs();

	Subset_Builder *sb = new Subset_Builder();

	sb->convert_to_DFA(start);

	return 0;
}
