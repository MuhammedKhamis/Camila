/*
 * prefix_handler.cpp
 *
 * 	prefix_handler class to represent disjoint set to group
 * 	expressions into sets according to their common prefix
 *
 *  Created on: Apr 23, 2018
 *      Author: Mohamed Raafat
 */

#include "prefix_handler.h"

prefix_handler::prefix_handler() {
	// TODO Auto-generated constructor stub

}

prefix_handler::~prefix_handler() {
	// TODO Auto-generated destructor stub
}


string prefix_handler::commonPrefixUtil(string str1, string str2)
{
    string result;
    int n1 = str1.length(), n2 = str2.length();

    int i,j;
    // Compare str1 and str2
    for (i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++)
    {
        if (str1[i] != str2[j])
            break;
        result.push_back(str1[i]);
    }

    if(str1[i-1] != ' ' && str2[j-1] != ' ') return "";

    return (result);
}

bool prefix_handler::has_common_prefix(string str1, string str2){
	string result = commonPrefixUtil(str1,str2);
	if(!result.compare("")) return false;
	return true;
}

set<string> prefix_handler::join (set<string> s1, set<string> s2){
	set<string> merged_set;
	std::set<string>::iterator it;
	for (it = s1.begin(); it != s1.end(); ++it)
	{
		merged_set.insert(*it);
	}

	for (it = s2.begin(); it != s2.end(); ++it)
	{
		merged_set.insert(*it);
	}
	return merged_set;
}

string prefix_handler::get_common_prefix(set<string> s){
	set<string> merged_set;
	std::set<string>::iterator it = s.begin();
	string prefix = *it;
	for (; it != s.end(); ++it)
	{
		prefix = commonPrefixUtil(prefix,*it);
	}
	return prefix;
}

void prefix_handler::generate_sets(){
	LOOP:
	for(int i=0; i<sets.size(); i++){
		std::set<string>::iterator it;
		it = sets[i].begin();
		string set_representative = *it;
		for(int j=i+1; j<sets.size(); j++){
			it = sets[j].begin();
			string curr_expr = *it;
			if(has_common_prefix(curr_expr,set_representative)){
				set<string> s1 = sets[i];
				set<string> s2 = sets[j];
				//remove them before merge
				sets.erase(sets.begin() + j);
				sets.erase(sets.begin() + i);
				set<string> merged_set = join(s1,s2);
				sets.push_back(merged_set);
				goto LOOP;
			}
		}
	}
}

void prefix_handler::set_expressions(set<string> expressions){
	std::set<string>::iterator it;
	for (it = expressions.begin(); it != expressions.end(); ++it)
	{
		set<string> new_set;
		new_set.insert(*it);
		sets.push_back(new_set);
	}
}

void prefix_handler::print_sets(){
	for(int i=0; i<sets.size(); i++){
		set<string> s = sets[i];
		cout<<"set "<<i+1<<" - prefix = "<<get_common_prefix(s)<<endl;
		std::set<string>::iterator it;
		for (it = s.begin(); it != s.end(); ++it)
		{
			cout<<*it<<endl;
		}
		cout<<endl;
	}
}

int prefix_handler::get_sets_number(){
	return sets.size();
}

int prefix_handler::get_rules_number(){
	//Initialized by 1 because there is at least on rule to be created
	int count = 1;
	for(int i=0; i<sets.size(); i++){
		if(sets[i].size() > 1) count++;
	}
	return count;
}

vector<set<string>> prefix_handler::get_sets(){
	return sets;
}

string prefix_handler::get_remove_prefix(string str, string prefix){
	int index_start = prefix.size();
	string result = "";
	for(int i=index_start; i<str.size(); i++){
		result += str[i];
	}
	//if empty string put it with epsilon value "\\L"
	if(result == "") result = "\\L";
	return result;
}

vector<string> prefix_handler::get_set_remove_prefix(set<string> s){
	string prefix = get_common_prefix(s);
	vector<string> result;
	std::set<string>::iterator it;
	for (it = s.begin(); it != s.end(); ++it)
	{
		result.push_back(get_remove_prefix(*it,prefix));
	}
	return result;
}
