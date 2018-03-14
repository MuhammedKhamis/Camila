/*
 * Graph.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <bits/stdc++.h>
using namespace std;

class Graph{

public:
	Graph(Node* start_node);
	Graph(Node* start_node, Node* end_node,int sz);
	~Graph();

	int get_graph_size();

	Node* get_start_node();

	Node* get_end_node();

	void set_end_node(Node* end_node);

	void set_start_node(Node* start_node);

	void set_graph_size(int sz);

private:

	Node* start_node;
	Node* end_node;
	int sz;



};



#endif /* GRAPH_H_ */
