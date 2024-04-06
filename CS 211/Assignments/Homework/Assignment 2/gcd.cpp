/*----
  signature: gcd: unsigned int, unsigned int -> int

  purpose: expects two integers and returns the greatest
           common divisor between the two.

  by: Dakota Donner
  last modified: 9-22-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "addCommas.h"

using namespace std;

int gcd(unsigned int num1, unsigned int num2)
{
    if (num1 < num2)
    {
        unsigned int swap;
        swap = num1;
        num1 = num2;
        num2 = swap;
    }

    if ((num1 % num2) == 0)
    {
        return num2;
    }

    else
    {
        gcd(num2, (num1 % num2));
    }
}