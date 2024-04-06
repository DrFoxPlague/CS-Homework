/*----
  signature: main: void -> int

  purpose: either: testing program for the function five_letter_str

  by: Dakota Donner
  last modified: 1-26-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "five_letter_str.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "---Testing five_letter_str---" << endl;
    cout << (five_letter_str("quark") == true) << endl;
    cout << (five_letter_str("string") == false) << endl;
    cout << (five_letter_str("wee") == false) << endl;

    return EXIT_SUCCESS;
}