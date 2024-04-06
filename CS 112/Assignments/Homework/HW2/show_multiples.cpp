/*----
  signature: show_multiples: int -> int
  
  purpose: expects an integer, has the side effect of
           printing that number multiplied by numbers 1
           through 12, each on their own line, to the screen,
           and returns the sum of all of the products.
      
  tests: show_multiples(5) == 390
         show_multiples(2) == 156

  by: Dakota Donner
  last modified: 2-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int show_multiples(int chsn_num)
{
    int sum = 0;

    for (int c = 1; c <= 12; c++)
    {
        cout << c << " x " << chsn_num << " = " << (c * chsn_num) << endl;
        sum = sum + (c * chsn_num);
    }

    return sum;
}