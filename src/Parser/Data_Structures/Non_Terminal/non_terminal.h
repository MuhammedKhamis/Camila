//
// Created by muhammed on 25/04/18.
//

#ifndef COMPILER_PROJECT_NON_TERMINAL_H
#define COMPILER_PROJECT_NON_TERMINAL_H

#include <bits/stdc++.h>
#include "line.h"

using namespace std;

class Non_Terminal {


public:

    Non_Terminal( line lne,  string non_terminal,  int id);

    void set_group_id(int g_id);

    const string &getNon_terminal() const;

    int getGroup_id() const;

    int getId() const;

    vector<string> get_follows(string &val);

private:
    line lne;
    string non_terminal;
    int group_id;
    int id;
};


#endif //COMPILER_PROJECT_NON_TERMINAL_H
