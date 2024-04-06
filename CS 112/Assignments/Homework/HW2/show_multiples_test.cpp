/*----
  signature: main: void -> int
  
  purpose: either:
           testing program for the function show_multiples

  by: Dakota Donner
  last modified: 2-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "show_multiples.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "--- TESTING show_multiples ---" << endl;
    
    cout << (show_multiples(5) == 390) << endl;
    cout << (show_multiples(2) == 156) << endl;

    return EXIT_SUCCESS;
}