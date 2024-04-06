/*----
  signature: five_letter_word: string -> bool

  purpose: expects a word and returns whether or not
           word is exactly five letters or not; a true 
           if it is and a false if it is not.

  tests: five_letter_word("false") == true
         five_letter_word("fork") == false
         five_letter_word("fracking") == false
         five_letter_word("ch1cke") == false

  by: Dakota Donner
  last modified: 1-28-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "is_letter.h"
using namespace std;

bool five_letter_word(string des_word)
{
    int letters = 0;

    for(int c = 0; c < des_word.length(); c++)
    {
        if (!is_letter(des_word.at(c)))
        {
            return false;
        }

        letters++;
    }

    return (letters == 5);
}