/*----
  signature: main: void -> int

  purpose: testing function get_size

  by: Dakota Donner
  last modified: 2-11-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "get_size.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << (get_size("list-of-trees.txt") == 4) << endl;
    cout << (get_size("basic-school-subjects.txt") == 5) << endl;

    return EXIT_SUCCESS;
}