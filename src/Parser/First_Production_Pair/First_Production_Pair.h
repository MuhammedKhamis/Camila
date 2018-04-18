//
// Created by muhammed on 16/04/18.
//

#ifndef COMPILER_PROJECT_FIRST_PRODUCTION_PAIR_H
#define COMPILER_PROJECT_FIRST_PRODUCTION_PAIR_H

#include <bits/stdc++.h>
#include "../First/First.h"
#include "../Production/Production.h"

using namespace std;

/*
 *
 *  class to hold each first and its corresponding production
 *
 *  Ex:- when first = x then production xYz is produced
 *
 * */
class First_Production_Pair {

public:

    First_Production_Pair( Production &p,  First &f);

    /*
     *
     *  getter for the production
     *
     * */
     Production &getProduction();

     /*
      *
      * getter for the first
      *
      */

     First &getFirst();

private:

    Production p;
    First f;
};


#endif //COMPILER_PROJECT_FIRST_PRODUCTION_PAIR_H
