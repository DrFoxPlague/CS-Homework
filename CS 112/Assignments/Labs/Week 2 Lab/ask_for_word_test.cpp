/*----
  signature: main: void -> int
  purpose: either:
           testing program for the function <name>
           OR
           <describe the program being written --
           what it needs, if anything, and what it does>

  by: Dakota Donner
  last modified: 1-28-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "ask_for_word.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "*** Testing ask_for_word ***" << endl;

    cout << "Should see prompts to Jenna." << endl;
    cout << "Enter 1, moo, 12345, moo23, sandstone, and moons when prompted."
    << endl;
    cout << "Should see true at the end if test passed:" << endl;
    cout << (ask_for_word("Jenna") == "moons") << endl;
    cout << endl;


    cout << "Should see prompts to Carlos." << endl;
    cout << "Enter Slick when prompted." << endl;
    cout << "Should see true at the end if test passed:" << endl;
    cout << (ask_for_word("Carlos") == "Slick") << endl;

    return EXIT_SUCCESS;
}