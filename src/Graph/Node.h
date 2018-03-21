/*
 * Node.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>
#include "../General/Enums.h"
#include "Edge.h"

using namespace std;

class Edge;

class Node{
public:
	Node();
	vector<Edge> get_edges();
	priority get_priority();
	void set_priority(priority p);
	void add_edge(Node* end, string value);
	void set_node_number();
	int get_node_number();
	void set_token(string token);
	string get_token();
	static int node_counter;
private:
	vector<Edge> edges;
	priority p;
	int node_number;
	string token;
};



#endif /* NODE_H_ */
