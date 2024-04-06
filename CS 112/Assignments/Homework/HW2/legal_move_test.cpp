/*----
  signature: main: void -> int
  
  purpose: either:
           testing program for the function legal_move

  by: Dakota Donner
  last modified: 2-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "legal_move.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "--- TESTING legal_move ---" << endl;
    
    cout << (legal_move('p') == true) << endl;
    cout << (legal_move('P') == true) << endl;
    cout << (legal_move('r') == true) << endl;
    cout << (legal_move('R') == true) << endl;
    cout << (legal_move('s') == true) << endl;
    cout << (legal_move('S') == true) << endl;
    cout << (legal_move('v') == false) << endl;

    return EXIT_SUCCESS;
}