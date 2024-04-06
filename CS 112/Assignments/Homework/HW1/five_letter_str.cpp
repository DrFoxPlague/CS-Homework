/*----
  signature: five_letter_str: string -> bool

  purpose: expects a desired string and returns
           true if it is exactly 5 characters or
           false if it is not.

  tests: five_letter_str("quark") == true
         five_letter_str("string") == false
         five_letter_str("wee") == false

  by: Dakota Donner
  last modified: 1-26-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool five_letter_str(string des_str)
{
    return ((des_str.length()) == 5);
}