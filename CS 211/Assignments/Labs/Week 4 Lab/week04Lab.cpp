/* 
 * File:   week04Lab.cpp
 * Author: Jonathan Thang & Dakota Donner
 *
 * Modified on 14 Sep 2022
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "week04Lab.h"

/*----
  signature: sumDownBy2: unsigned int -> int

  purpose: expects an unsigned integer and returns
           the sum of the sum of that integer and
           2 less that integer, until it reaches 1 or 0
----*/

int sumDownBy2(unsigned int n)
{
    if ((n == 0) || (n == 1))
    {
        return n;
    }

    else
    {
        n = n + sumDownBy2((n - 2));
    }

    return n;
}

/*----
  signature: recursiveMult: unsigned int, unsigned int -> int

  purpose: expects two unsigned integers and uses recursion
           to return the product of those two.
----*/

int recursiveMult(unsigned int j, unsigned int k)
{
    if (j == 0)
    {
        return 0;
    }

    else if (j == 1)
    {
        return k;
    }

    else if (k == 1)
    {
        return j;
    }

    else
    {
        j = j + recursiveMult(j, (k - 1));
    }

    return j;
}

/*----
  signature: geometricSum: unsigned int -> double

  purpose: expects an unsigned integer and returns
           the sum of that integer and that integer
           divided by 2, and then plus 1.
----*/

double geometricSum(unsigned int n)
{
    if (n == 0)
    {
        return n + 1.0;
    }

    else
    {
       return 1.0 + geometricSum(n - 1) / 2.0;
    }
}