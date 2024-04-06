/*----
  signature: accelerate: double -> void
  
  purpose: expects a speed as a double value and
           returns that speed increased by 10%
      
  tests: For:
         double speed1 = 50.0;
         
         accelerate(speed1);
         
         speed1 should now be:
         55.0
         
         
         for:
         double speed2 = 36.0
         
         accelerate(speed2);
         
         speed2 should now be:
         39.6

  by: Dakota Donner & Peter Ramos
  last modified: 2-25-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void accelerate(double &des_speed)
{
    des_speed *= 1.10;
}

