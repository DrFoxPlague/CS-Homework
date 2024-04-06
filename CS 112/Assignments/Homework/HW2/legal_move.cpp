/*----
  signature: legal_move: char -> bool
  
  purpose: expects a non-case sensitive(can be lowercase or capital)
           char that is either 'r', 'p', or 's', to represent a
           move in Rock Paper Scissors, and returns true 
           if that char is one of the three in the list, 
           and false if it is not.
      
  tests: legal_move('p') == true
         legal_move('P') == true
         legal_move('r') == true
         legal_move('R') == true
         legal_move('s') == true
         legal_move('S') == true
         legal_move('v') == false

  by: Dakota Donner
  last modified: 2-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool legal_move(char des_move_char)
{
  switch(des_move_char)
  {
    case 'r':
    case 'R':
      return true;
      break;
    
    case 'p':
    case 'P':
      return true;
      break;
    
    case 's':
    case 'S':
      return true;
      break;
    
    default:
      return false;
  }
}