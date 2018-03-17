/*
 * Edge.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#include "Edge.h"



Edge::Edge(Node* start, Node* end , string value){
	this->from_node = start;
	this->to_node = end;
	this->value = value;
}
Edge::~Edge(){

}

Node* Edge::get_from_Node(){
	return this->from_node;
}

Node* Edge::get_to_Node(){
	return this->to_node;
}

string Edge::get_value(){
	return this->value;
}




