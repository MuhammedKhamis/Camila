/*
 * Node.cpp
 * Class implementaion to define a node of a graph 
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */


#include "Node.h"

int Node::node_counter = 0;

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

void Node::set_node_number(){
	node_number = node_counter++;
}

int Node::get_node_number(){
	return node_number;
}

void Node::set_token(string token){
	this->token = token;
}

string Node::get_token(){
	return token;
}


