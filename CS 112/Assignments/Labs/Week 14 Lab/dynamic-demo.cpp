/*----
  signature: main: void -> int

  purpose: seeing dynamic/late binding in action for
           the week 13 lab.


    g++ Point.cpp ColorPoint.cpp ThreeDPoint.cpp dynamic-demo.cpp -o dynamic-demo
    
    ./dynamic-demo

  by: Peter Ramos & Dakota Donner
  last modified: 4/22/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "ThreeDPoint.h"
#include "Point.h"
#include "ColorPoint.h"
using namespace std;

int main()
{
    cout << boolalpha;

    Point *pnt_arr[6];

    pnt_arr[0] = new Point;
    pnt_arr[1] = new Point(1, 1);
    pnt_arr[2] = new ColorPoint;
    pnt_arr[3] = new ColorPoint(2, 2, "pickle");
    pnt_arr[4] = new ThreeDPoint;
    pnt_arr[5] = new ThreeDPoint(3, 3, 3);

    for(int i= 0; i < 6; i++)
    {
        pnt_arr[i]->display();
    }

    for(int i= 0; i < 6; i++)
    {
        delete pnt_arr[i];
    }





    return EXIT_SUCCESS;
}