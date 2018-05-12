//
// Created by muhammed on 25/04/18.
//

#ifndef COMPILER_PROJECT_PARSER_GROUP_H
#define COMPILER_PROJECT_PARSER_GROUP_H

#include <bits/stdc++.h>

using namespace std;

class Parser_group {
public:
    Parser_group(int id);

    void add_follows(vector<string> follows);

    void add_non_terminal_id(int id);

    bool in_my_group(int id);

private:

    set<string> follows;
    int id;
    set<int> my_non_terminal_ids;
};


#endif //COMPILER_PROJECT_PARSER_GROUP_H
