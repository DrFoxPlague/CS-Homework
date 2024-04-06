/*----
  signature: main: void -> int
  purpose: testing program for the function rand_factor

  by: Sharon Tuttle
  last modified: 2022-03-04
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "rand_factor.h"
using namespace std;

int main()
{
    cout << boolalpha;

    double looky;
    double val;

    for (int i=0; i < 10; i++)
    {
        looky = rand_factor();
        cout << ((0.1 <= looky) && (looky <= 0.9)) << endl;

        val = rand_factor();
        cout << ((0.1 <= val) && (val <= 0.9)) << endl;

        cout << "looky: " << looky << " val: " << val << endl;
    }

    return EXIT_SUCCESS;
}