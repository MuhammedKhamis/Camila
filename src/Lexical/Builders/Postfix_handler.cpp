/*
 * Postfix_handler.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: muhammed
 */

#include "Postfix_handler.h"

Postfix_handler& Postfix_handler::get_Instance(){
	static Postfix_handler instance;
	return instance;
}
string Postfix_handler::convert_operator(string c)
{
    if(c == "*")
    {
        return "%";
    }else if (c == "+")
    {
        return "?";
    }
    return c;
}

string Postfix_handler::convert_operator_back(string c)
{
    if(c == "%")
    {
        return "*";
    }else if (c == "?")
    {
        return "+";
    }
    return c;
}

/*
 * Check whether the operand is Letter or number
*/
bool Postfix_handler::is_operand(string c){
	return !is_normal_operator(c);
}

/*
 * Check the operators
 */
bool Postfix_handler::is_normal_operator(string c){
	return c == "+" || c == "*" || c == "#" || c == "|";
}

bool Postfix_handler::is_converted_operator(string c){
	return c == "?" || c == "%" || c == "#" || c == "|";
}


/*
 * Returns the priority of each operation
 */
int Postfix_handler::priority(string c){
	if(c == "%" || c == "?")
			return 3;
		else if(c == "#")//concatenation --> must be added before converting to Postfix
			return 2;
		else if(c == "|")
			return 1;
		else return -1;
}

/*
 * convert infix expression to postfix expression
 * */
vector<string> Postfix_handler::to_postfix(vector<string> exp)
{
	return to_postfix2(exp);

	stack<string> st;
	  st.push("@"); //Indicating the start
	  int n = exp.size();
	  vector<string> output;
	  for(int i=0; i<n; i++)
	  {
		 string c = exp[i];
		 if(c == "\\")
		 {
	        c = exp[i+1];
	        output .push_back(c);
	        output .push_back(" ");
	        i++;
	     }
		 //If token is operator check priority to
		 //make the token bigger than all the values in stack
		 else if(is_normal_operator(c))
		 {   c = convert_operator(c);
			 while(st.top() != "@" && st.top() != "(" &&(priority(c) <= priority(st.top())))
				{
					string temp = st.top();
				 	st.pop();
					output .push_back(temp);
					output .push_back(" ");
				}
				st.push(c);
		 }
		 //Push opening brackets to stack
		 else if(c == "(")
		 {
			 st.push("(");
		 }
		 //If closing bracket pop all the contents from stack until
		 //opening bracket is met
		 else if(c == ")")
		 {
			 while(st.top() != "@" && st.top() != "(")
			 {
				 string temp = st.top();
		         st.pop();
		         output .push_back(temp);
		         output .push_back(" ");
			 }
		     if(st.top() == "(")
	            {
	                string temp = st.top();
	                st.pop();
	            }

		 }	 //If token is operand print it to output
		 else if (c != " ")
		 {
			 output .push_back(c);
			 output .push_back(" ");
		 }
	  }
	  while(st.top() != "@")
	      {
	          string c = st.top();
	          st.pop();
	          output .push_back(c);
	          output .push_back(" ");
	      }
	 return output;

}

/*
 * Takes postfix expression and evaluate its NFA and return the starting Node of NFA
 * Hint: # is concatenation - % is (*) closure - ? is (+) closure
 * */
Node* Postfix_handler::evaluate_postfix(vector<string> exp, string token)
{

	return evaluate_postfix2(exp,token);

	//Initialzing stack
    stack<Graph*> st
    ;
    //Intitializing Thomson builder

    Thomson_Builder& T_builder = Thomson_Builder::get_Instance();

    int n = exp.size();

    // Scan all characters one by one


    for (int i = 0; i < n; i++)
    {   string c = exp[i];

        if (is_converted_operator(c))

        {
           if(c == "#"){
        	   Graph* g1 = st.top(); //Operand 1
        	   st.pop();
        	   Graph* g2 = st.top(); //Operand 2
        	   st.pop();
        	   Graph* result;
               result = T_builder.concat_operation(g2,g1);
               st.push(result);
           }else if(c == "|"){
               Graph* g1 = st.top(); //Operand 1
        	   st.pop();
        	   Graph* g2 = st.top(); //Operand 2
        	   st.pop();
        	   Graph* result;
               result = T_builder.or_operation(g2,g1);
               st.push(result);
           }else if(c == "%"){ // % = *
               Graph* g = st.top(); //Operand
        	   st.pop();
        	   Graph* result;
               result = T_builder.star_operation(g);
               st.push(result);
           }else if(c == "?"){ // ? = +
               Graph* g = st.top(); //Operand
        	   st.pop();
        	   Graph* result;
               result = T_builder.plus_operation(g);
               st.push(result);
           }
        }
        else if(c != " ") //Operand
        {
          string temp = "";
          temp += c;
          Graph* g = T_builder.initialize_graph(temp);
          st.push(g);
        }
    }

    Graph* final_graph = st.top();
    st.pop();
    Node* start_node = final_graph->get_start_node();

    T_builder.save_graph(final_graph,token);

    return start_node;
}

int Postfix_handler::precedence(string c) {
    if(c == "*" || c == "+"){
        return 4;
    }
    if(c == "-"){
        return 3;
    }
    if(c == "#"){
        return 2;
    }
    if(c == "|"){
        return 1;
    }
    return 0;
}


bool Postfix_handler::is_operation(string c) {
	return is_normal_operator(c) || c == "-";
}

vector<string> Postfix_handler::to_postfix2(vector<string> exp) {

	stack<string> st;

	int n = (int)exp.size();

	vector<string> output;

	bool look_ahead = false;

	for(int i=0; i < n ; i++)
	{
		string s = exp[i];
		if(s == "\\L"){
			output.emplace_back(s);
		}
		else if(look_ahead){
			look_ahead = false;
			output.emplace_back(s);
		}else{
			look_ahead = false;
			if(s == "("){
				st.push(s);
			}else if(s == ")"){
				while(!st.empty() &&  st.top() != "("){
					output.emplace_back(st.top());
					st.pop();
				}
				st.pop();
			}else if(is_operation(s)){
				while(!st.empty() && precedence(st.top()) >= precedence(s)){
					output.emplace_back(st.top());
					st.pop();
				}
				st.push(s);
			}else{
				output.emplace_back(s);
				if(s == "\\"){
					look_ahead = true;
				}
			}
		}
	}
	while(!st.empty()){
		output.emplace_back(st.top());
		st.pop();
	}
	return output;
}

Node* Postfix_handler::evaluate_postfix2(vector<string> exp, string token) {

	stack<Graph*> st;

	//Intitializing Thomson builder
	Thomson_Builder& T_builder = Thomson_Builder::get_Instance();

	int n = (int)exp.size();

	bool look_ahead = false;

	// Scan all characters one by one
	for (int i = 0; i < n; i++){
		string c = exp[i];

		if(look_ahead){
			look_ahead = false;
			Graph* g = T_builder.initialize_graph(c);
			st.push(g);
		}else if(c == "\\"){
			look_ahead = true;
		}else if(is_operation(c)){
			look_ahead = false;
			// apply operation
			apply_operation(c,st,T_builder);
		}else{
			look_ahead = false;
			// normal string
			Graph* g = T_builder.initialize_graph(c);
			st.push(g);
		}

	}
	Graph* final_graph = st.top();
	st.pop();
	Node* start_node = final_graph->get_start_node();

	T_builder.save_graph(final_graph,token);

	return start_node;
}

Graph* Postfix_handler::apply_operation(string operation, stack<Graph *> &st,Thomson_Builder& tb) {

	Graph* g1 = st.top();
	st.pop();
	Graph* res;

	if(operation == "*"){
		res = tb.star_operation(g1);
	}else if(operation == "+"){
		res = tb.plus_operation(g1);
	}else if(operation == "-"){
		Graph* g2 = st.top();
		st.pop();
		res = tb.range_operation(g2,g1);
	}else if(operation == "#"){
		Graph* g2 = st.top();
		st.pop();
		res = tb.concat_operation(g2,g1);
	}else{
		Graph* g2 = st.top();
		st.pop();
		res = tb.or_operation(g2,g1);
	}
	st.push(res);
	return res;
}