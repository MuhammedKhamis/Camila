/*
 * Thomson_Builder.h
 *
 *  Created on: Mar 17, 2018
 *      Author: muhammed
 */

#ifndef THOMSON_BUILDER_H_
#define THOMSON_BUILDER_H_

#include <bits/stdc++.h>

#include "../Graph/Graph.h"
#include "../Graph/Node.h"
#include "../General/Enums.h"

using namespace std;


/* this class is used to build the graph of the NFA using the defined operations
 * in the pdf  => { +, *, #, | }
 *
 * */

class Thomson_Builder{

public:
	/*
	 *  generate the start graph
	 *  only start and end node with 1 edge with value = val
	 * */
	Graph* initialize_graph(string val);
	/*
	 *  the # operation between 2 graphs
	 * */
	Graph* concat_operation(Graph* g1 , Graph* g2);
	/*
	 *  the | operation between 2 graphs
	 * */
	Graph* or_operation(Graph* g1 , Graph* g2);
	/*
	 *  the * operation for 1 graph
	 * */
	Graph* star_operation(Graph* g1);
	/*
	 * the + operation for 1 graph
	 * */
	Graph* plus_operation(Graph* g1);
	/*
	 *  after finish building one expression we save it in vector and give its
	 *  last node a token as if we reached this node and want to know the type
	 *
	 *  Note that : any node must give only one token due to priority
	 *
	 *
	 * */
	void save_graph(Graph* g, string token);

	/*
	 *  after processing all the expression and keywords it assembles all saved
	 *  graphs by adding start node and connect it to every start node in other graphs
	 *  the return that node as the result graph may have many ends but only one start
	 *
	 *  check the TA.Reham Osama solution of the NFA
	 *  for the last problem in the sheet
	 *
	 * */
	Node* assemble_saved_graphs();
	/*
	 * Singleton Class
	 * */
	static Thomson_Builder& get_Instance();
protected:

private:
	/*
	 *  singleton definitions
	 * */
	Thomson_Builder(){};
    // Stop the compiler generating methods of copy the object
	Thomson_Builder(Thomson_Builder const& copy);            // Not Implemented
	Thomson_Builder& operator=(Thomson_Builder const& copy); // Not Implemented

	/*
	 *  vector of the saved graphs
	 * */
	vector<Graph*> saved_graphs;

	/*
	 * the epsilon or lambda ( lambda is cooler by the way :"D )
	 * */
	const string lambda = "\\L";
};



#endif /* THOMSON_BUILDER_H_ */
