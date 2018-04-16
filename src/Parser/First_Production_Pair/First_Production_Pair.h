//
// Created by muhammed on 16/04/18.
//

#ifndef COMPILER_PROJECT_FIRST_PRODUCTION_PAIR_H
#define COMPILER_PROJECT_FIRST_PRODUCTION_PAIR_H

#include <bits/stdc++.h>
#include "../First/First.h"
#include "../Production/Production.h"

using namespace std;

class First_Production_Pair {

public:
    First_Production_Pair( Production &p,  First &f);

     Production &getProduction();

     First &getFirst();

private:

    Production p;
    First f;
};


#endif //COMPILER_PROJECT_FIRST_PRODUCTION_PAIR_H
