/*----
  signature: main: void -> int

  purpose: testing program from function put_in_order

  by: Dakota Donner
  last modified: 3-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "put_in_order.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "--- TESTING put_in_order ---" << endl;

    double value_1 = 6.5;
    double value_2 = 4.3;

    put_in_order(value_1, value_2);

    cout << (value_1 == 4.3) << endl;
    cout << (value_2 == 6.5) << endl;

    double sq_area_1 = 16.7;
    double sq_area_2 = 16.8;

    put_in_order(sq_area_1, sq_area_2);

    cout << (sq_area_1 == 16.7) << endl;
    cout << (sq_area_2 == 16.8) << endl;

    return EXIT_SUCCESS;
}