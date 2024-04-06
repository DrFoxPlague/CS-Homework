/*----
  signature: put_in_order: double& double& -> void

  purpose: expects two pass-by-reference double parameters, has
           the side effect of comparing the two values, and
           seeing which one is greater, and if the first one is
           greater, then the two values are swapped, and returns
           nothing.

  tests: for:

         double value_1 = 6.5;
         double value_2 = 4.3;

         put_in_order(value_1, value_2);

         value_1 == 4.3
         value_2 == 6.5


         for:

         double sq_area_1 = 16.7;
         double sq_area_2 = 16.8;

         put_in_order(sq_area_1, sq_area_2);

         sq_area_1 == 16.7
         sq_area_2 == 16.8

  by: Dakota Donner
  last modified: 3-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void put_in_order(double &num_1, double &num_2)
{
  if (num_1 > num_2)
  {
    double storing_var;

    storing_var = num_1;
    num_1 = num_2;
    num_2 = storing_var;
  }

  else
  {
    num_1 = num_1;
    num_2 = num_2;
  }
}