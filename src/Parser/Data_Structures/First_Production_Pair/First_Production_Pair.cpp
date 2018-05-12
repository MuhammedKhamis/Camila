//
// Created by muhammed on 16/04/18.
//

#include "First_Production_Pair.h"

First_Production_Pair::First_Production_Pair(Production &p,  First &f) : p(p), f(f) {}

 Production &First_Production_Pair::getProduction()  {
    return p;
}

 First &First_Production_Pair::getFirst()  {
    return f;
}
