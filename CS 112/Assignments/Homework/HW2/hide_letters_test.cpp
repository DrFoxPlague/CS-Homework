/*----
  signature: main: void -> int
  
  purpose: either:
           testing program for the function hide_letters

  by: Dakota Donner
  last modified: 2-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "hide_letters.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "--- TESTING hide_letters ---" << endl;
    
    cout << (hide_letters("sneakers") == "________") << endl;
    cout << (hide_letters("brother-in-law") == "_______-__-___") << endl;

    return EXIT_SUCCESS;
}