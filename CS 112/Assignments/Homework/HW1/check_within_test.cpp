/*----
  signature: main: void -> int
  
  purpose: testing program for the function check_within

  by: Dakota Donner
  last modified: 1-26-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "check_within.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "---Testing check_within---" << endl;
    cout << (check_within(sqrt(4), 2.0, 0.1) == true) << endl;
    cout << (check_within(sqrt(2), 1.4, 0.001) == false) << endl;
    cout << (check_within(sqrt(9), 3.0, 0.0) == false) << endl;

    return EXIT_SUCCESS;
}