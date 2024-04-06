/*----
  signature: letter_match: string string int -> bool
  purpose: expects the word of the day, the guessed word,
      and a letter position within those words,
      and returns whether the letter at that position
      in both words is the same letter
  tests:
      letter_match("apple", "juice", 3) == false
      letter_match("apple", "juice", 4) == true

  by: Sharon Tuttle
  last modified: 2022-01-20
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool letter_match(string word_of_day,
                  string word_guess,
                  int pos)
{
    return (word_of_day.at(pos) == word_guess.at(pos));
}