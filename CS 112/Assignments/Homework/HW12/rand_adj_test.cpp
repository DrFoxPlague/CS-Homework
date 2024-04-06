/*----
  signature: main: void -> int

  purpose: either:
           testing program for the function <name>
           OR
           <describe the program being written --
           what it needs, if anything, and what it does>

  by: Dakota Donner
  last modified:
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "rand_adj.h"
using namespace std;

int main()
{
    cout << boolalpha;

    for(int c = 0; c < 10; c++)
    {
        rand_adj();
    }

    return EXIT_SUCCESS;
}