/*----
  signature: main: void -> int

  purpose: Program to create dynamically
           allocated arrays for Point class
           objects

  by: Dakota Donner
  last modified: 3-11-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
using namespace std;

int main()
{
    cout << boolalpha;

    // variables

    int size;
    double user_x;
    double user_y;
    Point *point_arr;

    // code

    cout << "Enter the desired number of points: ";
    cin >> size;

    point_arr = new Point[size];

    for (int c = 0; c < size; c++)
    {
        cout << "Enter point " << to_string(c + 1) << "'s x coordinate: ";
        cin >> user_x;

        cout << "Enter point " << to_string(c + 1) << "'s y coordinate: ";
        cin >> user_y;

        point_arr[c].set_pos(user_x, user_y);
    }

    cout << "If this was a path, the x distance will be: ";
    cout << ( (point_arr[(size - 1)].get_x()) - (point_arr[0].get_x()) ) << endl << endl;

    cout << "...and the y distance will be: ";
    cout << ( (point_arr[(size - 1)].get_y()) - (point_arr[0].get_y()) ) << endl << endl;

    delete [] point_arr; // freeing memory

    return EXIT_SUCCESS;
}