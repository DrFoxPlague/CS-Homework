/*----
  signature: rand_adj: void -> string

  purpose: expects nothing, has a side-effect of
           calling rand_int to return one of five
           adjectives:

           BRUTAL
           WHOPPING
           ABSOLUTELY UNBELIEVABLE
           DEVASTATING
           TERRIFYING

  tests:

  by: Dakota Donner
  last modified: 5-9-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "rand_int.h"
using namespace std;

string rand_adj()
{
    int value = (rand_int(1, 5));

    switch(value)
    {
        case 1:
            return "BRUTAL";
            break;

        case 2:
            return "WHOPPING";
            break;

        case 3:
            return "ABSOLUTELY UNBELIEVABLE";
            break;

        case 4:
            return "DEVASTATING";
            break;

        case 5:
            return "TERRIFYING";
            break;
    }
}