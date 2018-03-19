/*
 * Builder.h
 *
 *  Created on: Mar 16, 2018
 *      Author: muhammed
 */

#ifndef BUILDER_H_
#define BUILDER_H_

#include <bits/stdc++.h>
using namespace std;


class Builder{

public:
		/*
		 *  Singleton Class
		 * */
		 static Builder& get_Instance();
		 /*
		  *  it save the simplified definition in the to_val map
		  *   key = the definition name
		  *   value = the value of the definition
		  *   ex : { digit , =, 0,-,9}
		  *   saved as key = digit , value = {0,-,9}
		  *
		  *   if the definition is defined by another one then we substitute
		  *   in the current definition by the value of the defined before
		  *   definition
		  *   ex : { digits, :, digit,+}
		  *   saved as key = digits, value = {0,-,9,+}
		  * */
		 void evaluate_definition(vector<string> definition);
		 /**
		  * generate vector of the string that contains the simplest form of the
		  * expression
		  *  ex : { id, :, digits, |, letter } => { 0,-,9,|,A,-,Z,|,a,-,z}
		  *
		  *  then it will give it to the postfix object to process and evaluate
		  *   to create the NFA machine
		  * */
		 void evaluate_expression(vector<string> expression);
		 /*
		  *  get vector of string each item represent a keyword
		  *
		  *  ex : { int , float , char } => { {i,#,n,#,t}, {f,#,l,#,o,#,a,#,t},
		  *   {c,#,h,#,a,#,r} }
		  *
		  *  it evaluate each sub-vector and create its machine using the postfix
		  *  object like any expression
		  *
		  * */
		 void evaluate_keyword(vector<string> keywords);
		 /*
		  *  same as the keywords but for the punctuation
		  *
		  * */
		 void evaluate_punctuation(vector<string> punc);

protected:

private:
		 /*
		  * used to simplify the vector given by check the map if that string
		  * is saved before in the map or not
		  * */
		vector<char> simplify_vector(vector<string> vec);

		bool is_operation(char inp);

		/*
		 converts each range sign to group of (or)s
		*/
		vector<string> Builder::convert_range(vector<string> str);

		/*
		 *  Singleton handling
		 * */
        Builder(){};
        // Stop the compiler generating methods of copy the object
        Builder(Builder const& copy);            // Not Implemented
        Builder& operator=(Builder const& copy); // Not Implemented

        /*
         *  helping data structure to save the definitions
         * */
		unordered_map<string,vector<char>> to_val;

		/*
		 *  const number to tell us where the = or the : will be put in
		 *  the expression or in the definition
		 * */
		static const int type_index = 1;

		/*
		 *  general operations' symbols
		 * */
		 const char concat_symbol = '#';
		 const char or_symbol = '|';
		 const char star_symbol = '*';
		 const char plus_symbol = '+';
		 const char dash_symbol = '-';


};


#endif /* BUILDER_H_ */
