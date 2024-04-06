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
#include "five_letter_word.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "--- Testing five_letter_word ---" << endl;

    cout << (five_letter_word("false") == true) << endl;
    cout << (five_letter_word("fork") == false) << endl;
    cout << (five_letter_word("fracking") == false) << endl;
    cout << (five_letter_word("ch1cke") == false) << endl;

    return EXIT_SUCCESS;
}