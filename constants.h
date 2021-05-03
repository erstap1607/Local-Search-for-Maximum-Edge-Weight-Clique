#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <math.h>

const long double EPS = 0.000000000001;
const int TRY_STEP = 10;
const int PRIME_NUM = 1000000007; //10^9+7
//ADDITION TO IMPROVE ALGORITHM - EMILY EHRLICH
const int NEW_PRIME = sqrt(PRIME_NUM) - 15;

const int SEARCH_DEPTH = 4000;
const float RAND_WALK_P = 1.0;
#endif
