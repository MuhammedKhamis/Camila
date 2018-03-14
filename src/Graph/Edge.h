/*
 * Edge.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <bits/stdc++.h>
using namespace std;


class Edge{

public:
	Edge(Node* start , Node* end , string value);
	~Edge();
	Node* get_from_Node();
	Node* get_to_Node();
	string get_value();

private:
	Node* to_node;
	Node* from_node;
	string value;
};



#endif /* EDGE_H_ */
