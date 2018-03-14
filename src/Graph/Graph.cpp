/*
 * Graph.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */



Graph::Graph(Node* start_node){
	this->start_node = start_node;
	this->end_node = 0;
	this->sz = 0;
}

Graph::Graph(Node* start_node, Node* end_node , int sz){
	this->start_node = start_node;
	this->end_node = end_node;
	this->sz = sz;
}

int Graph::get_graph_size(){
	return this->sz;
}

Node* Graph::get_end_node(){
	return this->end_node;
}

Node* Graph::get_start_node(){
	return this->start_node;
}

void Graph::set_end_node(Node* end_node){
	this->end_node = end_node;
}

void Graph::set_start_node(Node* start_node){
	this->start_node = start_node;
}

void Graph::set_graph_size(int sz){
	this->sz = sz;
}
