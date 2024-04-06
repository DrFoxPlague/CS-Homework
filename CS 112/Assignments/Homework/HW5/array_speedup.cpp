/*----
  signature: main: void -> int

  purpose: program designed for a dynamically allocated
           array for accelerated speeds and printing said
           array to the screen.

  by: Dakota Donner
  last modified: 3-9-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "accelerate.h"
#include "print_nums.h"
using namespace std;

int main()
{
    cout << boolalpha;

    // local variables

    int arr_size;
    double des_speed;

    // code

    cout << "Enter the desired number of speeds: ";
    cin >> arr_size;
    cout << endl;

    double *speedups;
    speedups = new double[arr_size];

    for(int c = 0; c < arr_size; c++)
    {
        cout << "Entering speed " + to_string(c) + ": ";
        cin >> des_speed;
        speedups[c] = des_speed;
    }

    cout << endl;
    cout << "Original speeds: " << endl;
    print_nums(speedups, arr_size);
    cout << endl;

    cout << "Accelerated speeds: " << endl;
    for(int c = 0; c < arr_size; c++)
    {
        accelerate(speedups[c]);
    }
    print_nums(speedups, arr_size);
    cout << endl;

    delete [] speedups;
    speedups = NULL;

    return EXIT_SUCCESS;
}