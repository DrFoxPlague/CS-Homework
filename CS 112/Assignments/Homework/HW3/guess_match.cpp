/*----
  signature: guess_match: string string -> string
  purpose: expects a word of the day and a guessed word
      and returns a string giving the match-color-results
      for the guessed word as follows:
      *   if letter in a position matches, append "green "
      *   if a letter in a position does not match,
          but is elsewhere in the word of the day,
          append "gold "
      *   otherwise, append "gray "
  tests:
      guess_match("great", "brake") ==
          "gray green gold gray gold "
      guess_match("false", "thyme") ==
          "gray gray gray gray green "

  by: Sharon Tuttle
  last modified: 2-11-2022

  edited by: Dakota Donner
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "letter_match.h"
#include "letter_elsewhere.h"
using namespace std;

string guess_match(string word_of_day, string word_guess)
{
    string match_result = "";

    // for each letter in word_guess, determine its "match-status"
    //     compared to word_of_day
    
    if (word_guess.length() > word_of_day.length())
    {
        for (int i=0; i < word_of_day.length(); ++i)
        {
        // does letter at position i of word_guess match, or exist elsewhere,
	    //     or is it not in word_of_day at all?
      
            if (letter_match(word_of_day, word_guess, i))
            {
                match_result += "green ";
            }
            else if (letter_elsewhere(word_of_day, word_guess, i))
            {
                match_result += "gold ";
            }
            else
            {
                match_result += "gray ";
            }
        }

    }

    else
    {
        for (int i=0; i < word_guess.length(); ++i)
        {
            // does letter at position i of word_guess match, or exist elsewhere,
	        //     or is it not in word_of_day at all?
      
            if (letter_match(word_of_day, word_guess, i))
            {
                match_result += "green ";
            }
            else if (letter_elsewhere(word_of_day, word_guess, i))
            {
                match_result += "gold ";
            }
            else
            {
                match_result += "gray ";
            }
        }
    }

    return match_result;
}