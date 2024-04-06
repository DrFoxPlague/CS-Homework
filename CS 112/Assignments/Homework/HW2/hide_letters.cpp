/*----
  signature: hide_letters: string -> string
  
  purpose: expects a word or phrase, and returns
           all valid letters as underscores, and
           any non-letter is left as it is.
      
  tests: hide_letters("sneakers") == "________"
         hide_letters("brother-in-law") == "_______-__-___"

  by: Dakota Donner
  last modified: 2-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "is_letter.h"
using namespace std;

string hide_letters(string des_phrase)
{
    string hidden_phrase = "";

    for (int c = 0; c < des_phrase.length(); c++)
    {
        if (!is_letter(des_phrase.at(c)))
        {
          hidden_phrase = hidden_phrase + des_phrase.at(c);
        }

        else
        {
          hidden_phrase = hidden_phrase + "_";
        }
    }

    return hidden_phrase;
}

