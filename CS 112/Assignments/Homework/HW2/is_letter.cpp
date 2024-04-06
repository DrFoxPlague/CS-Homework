/*----
  signature: is_letter: char -> bool
  purpose: expects a character, and returns true if it is a
      letter (one of 'a' through 'z' or 'A' through 'Z')
  tests:
      is_letter('g') == true
      is_letter('H') == true
      is_letter(' ') == false
      is_letter('.') == false
      is_letter('4') == false
      is_letter('A') == true
      is_letter('a') == true
      is_letter('Z') == true
      is_letter('z') == true      

  by: Sharon Tuttle
  last modified: 2022-01-28
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool is_letter(char a_char)
{
    return ( (a_char >= 'a') && (a_char <= 'z')
             ||
	     (a_char >= 'A') && (a_char <= 'Z') );
}