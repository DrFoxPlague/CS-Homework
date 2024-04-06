/*----
  signature: letter_elsewhere: string string int -> bool
  purpose: expects the word of the day, the guessed word,
      and a letter position in the guessed word,
      and returns whether the letter in that position
      of the guessed word is in the word of the day,
      BUT in a DIFFERENT position
  tests:
      letter_elsewhere("fruit", "shark", 3) == true
      letter_elsewhere("quark", "quick", 0) == false
      letter_elsewhere("ambidextrous", "cow", 0) == false

  by: Sharon Tuttle
  last modified: 2022-01-25
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "letter_match.h"
using namespace std;

bool letter_elsewhere(string word_of_day,
                      string word_guess,
                      int pos)
{
    // if both words have the same letter at this position,
    //     it is not ONLY elsewhere in the word_of_day

    if (letter_match(word_of_day, word_guess,
                     pos))
    {
        return false;
    }

    // if both do NOT have the same letter at this position,
    //     it is worth seeing if the letter at pos in
    //     word_guess is anywhere else in word_of_day

    else
    {
        char match_letter = word_guess.at(pos);
        bool found_yet = false;
        int word_len = word_of_day.length();
        int next_pos = 0;

        // while we haven't found the match_letter yet
        //    and we haven't run out of word_of_day,
        //    look for match_letter in word_of_day

        while ((!found_yet) && (next_pos < word_len))
        {
            // we already know match_letter is not in word_of_day's
            //     pos position

            if (next_pos != pos)
            {
                if (word_of_day.at(next_pos) ==
                    match_letter)
                {
                    found_yet = true;
                }
            }
            next_pos += 1;
        }

        return found_yet;
    }
}