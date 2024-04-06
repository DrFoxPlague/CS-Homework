/*----
  signature: main: void -> int
  purpose: testing function accelerate

  by: Peter Ramos & Dakota Donner
  last modified: 2-25-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "accelerate.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "For speed1: " << endl;
    
    double speed1 = 50.0;
    cout << speed1 << endl;
         
    accelerate(speed1);
    
    cout << "speed1 should now be 55.0:" << endl;
    
    cout << "speed1: " << speed1 << endl;
         
         
    cout << "For speed2: " << endl;
    
    double speed2 = 36.0;
    cout << speed2 << endl;
         
    accelerate(speed2);
    
    cout << "speed2 should now be 39.6:" << endl;
    
    cout << "speed2: " << speed2 << endl;

    return EXIT_SUCCESS;
}

