/*----
  signature: main: void -> int
  purpose: testing program for the function guess_match

  compile using:
      g++ guess_match_test.cpp guess_match.cpp letter_match.cpp letter_elsewhere.cpp -o guess_match_test
  run using:
      ./guess_match_test

  by: Sharon Tuttle
  last modified: 2022-01-27
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "guess_match.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "*** Testing guess_match ***" << endl;

    cout << (guess_match("great", "brake") ==
          "gray green gold gray gold ") << endl;
    cout << (guess_match("false", "thyme") ==
          "gray gray gray gray green ") << endl;

    cout << endl;
    cout << "For fun: print the resulting match-string for " << endl;
    cout << "   word-of-day great and guess-word brake:" << endl;
    cout << "-------------------------------------------" << endl;
    
    cout << guess_match("great", "brakeeeee") << endl;
    cout << endl;
    
    return EXIT_SUCCESS;
}