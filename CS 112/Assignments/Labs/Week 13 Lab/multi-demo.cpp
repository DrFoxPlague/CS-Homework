/*----
  signature: main: void -> int

  purpose: testing file for ColorPoint
           after new adaptation




    g++ Point.cpp ColorPoint.cpp multi-demo.cpp -o multi-demo

    ./multi-demo

  by: Dakota Donner & Peter Ramos
  last modified: 4-22-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "ColorPoint.h"
using namespace std;

int main()
{
    cout << boolalpha;

    ColorPoint fred;
    ColorPoint freds_hot_sister(3, 5, "4");

    cout << (fred.compute_rank() == 0) << endl;
    cout << (freds_hot_sister.compute_rank() == 35.1667) << endl;

    Rankable *rnk_arr[4];

    for(int i = 0; i < 4; i++)
    {
        rnk_arr[i] = new ColorPoint(i, i, to_string(i));
        cout << (rnk_arr[i]->compute_rank()) << endl;
    }

    for(int i = 0; i < 4; i++)
    {
     delete rnk_arr[i];
    }


    return EXIT_SUCCESS;
}