/*
 * Node.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */


#include "Node.h"

Node::Node(){
	this->p = in_valid;
}

vector<Edge>* Node::get_edges(){
	return &this->edges;
}

void Node::set_priority(priority p){
	this->p=p;
}

priority Node::get_priority(){
	return this->p;

}

void Node::add_edge(Node* end, string value){
	Edge e(this,end,value);

	this->edges.push_back(e);
}





