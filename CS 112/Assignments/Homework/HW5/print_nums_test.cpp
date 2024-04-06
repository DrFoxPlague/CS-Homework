/*----
  signature: main: void -> int
  purpose: testing program for the function print_nums

  compile using:
      g++ print_nums_test.cpp print_nums.cpp -o print_nums_test
  run using:
      ./print_nums_test

  by: Sharon Tuttle
  last modified: 2022-02-03
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "print_nums.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "*** Testing print_nums ***" << endl;

    // for a void function -- one that returns NOTHING --
    //    cannot put it in a cout, no returning value
    //    to COMPARE in a bool expression!
    //
    // so, how test?
    // DESCRIBE in a cout what side-effects SHOULD
    //    result if the function works,
    //    enough that you can tell from the program's
    //    output alone if those side-effects are
    //    happening

    double worm_wts[3] = {1.1, 2.2, 3.3};

    cout << "should see 0: 1.1, 1: 2.2, 2: 3.3, each on own line:"
         << endl;

    print_nums(worm_wts, 3);

    double measures[4] = {0.5, 1.0, 1.50, 2.05};

    cout << "\nShould see 0: 0.5, 1: 1, 2: 1.5, 3: 2.05, each on own line:"
         << endl;

    print_nums(measures, 4);

    return EXIT_SUCCESS;
}