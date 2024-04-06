/*----
  signature: main: void -> int
  
  purpose: either:
           testing program for the function get_winner

  by: Dakota Donner
  last modified: 2-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "get_winner.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "--- TESTING get_winner ---" << endl;
    
    cout << (get_winner('v', 'r') == -1) << endl;
    cout << (get_winner('p', 'x') == -1) << endl;
    cout << (get_winner('q', 't') == -1) << endl;
    cout << (get_winner('r', 'r') == 0) << endl;
    cout << (get_winner('p', 'p') == 0) << endl;
    cout << (get_winner('s', 's') == 0) << endl;
    cout << (get_winner('p', 'r') == 1) << endl;
    cout << (get_winner('r', 's') == 1) << endl;
    cout << (get_winner('s', 'p') == 1) << endl;
    cout << (get_winner('r', 'p') == 2) << endl;
    cout << (get_winner('p', 's') == 2) << endl;
    cout << (get_winner('s', 'r') == 2) << endl;

    return EXIT_SUCCESS;
}