/*
 * Postfix_generator.h
 *
 *  Created on: Mar 16, 2018
 *      Author: Mohamed Raafat
 */

#ifndef POSTFIX_GENERATOR_H_
#define POSTFIX_GENERATOR_H_
#include <bits/stdc++.h>

/*
 * Check whether the operand is Letter or number
 * Hint:
 * Will be edited to accept regular definitions later
*/
bool is_operand(char c);

/*
 * Returns the priority of each operation
 */
int priority(char c);

/*
 * convert infix expression to postfix expression
 * */
string to_postfix(vector<char> exp);



#endif /*POSTFIX_GENERATOR_H_*/
