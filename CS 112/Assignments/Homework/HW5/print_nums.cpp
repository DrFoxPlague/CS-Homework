/*---
    signature: print_nums: double[] int -> void
    purpose: expects an array of numbers and its size,
        and has the side-effect of printing those
        to the screen, one per line,
        and returns NOTHING.
    tests:
        for:
        double worm_wts[3] = {1.1, 2.2, 3.3};

        print_nums(worm_wts, 3);

        ...should print to the screen:
0: 1.1
1: 2.2
2: 3.3

        for:
        double measures[4] = {0.5, 1.0, 1.50, 2.05};

        print_nums(measures, 4);

        ...should print to the screen:
0: 0.5
1: 1
2: 1.5
3: 2.05

  by: Sharon Tuttle
  last modified: 2022-02-03
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void print_nums(const double my_nums[], int size)
{
    // prints the contents of my_nums, one per line

    for (int i=0; i < size; i++)
    {
        cout << i << ": " << my_nums[i] << endl;
    }
}