/*----
  signature: addCommas: unsigned long long int -> void

  purpose: expects an integer, returns nothing, and prints
           that integer to the screen with commas in the 
           appropriate spaces.

  by: Dakota Donner
  last modified: 9-22-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "addCommas.h"

using namespace std;

void addCommas(unsigned long long int aNum)
{
    // variables for easy access

    unsigned long long int thous = 1000;
    unsigned long long int mill = 1000000;
    unsigned long long int bill = 1000000000;
    unsigned long long int trill = 1000000000000;
    unsigned long long int quad = 1000000000000000;
    unsigned long long int quint = 1000000000000000000;

    // hundreds, tens, and ones

    if ((to_string(aNum).length()) <= 3)
    {
        cout << aNum << endl;
    }

    
    // thousands

    else if ((to_string(aNum).length()) <= 6)
    {
        cout << (aNum / thous) << "," << (aNum % thous) << endl;
    }
    
    // millions

    else if ((to_string(aNum).length()) <= 9)
    {
        cout << (aNum / mill) << ",";
        addCommas((aNum % mill));
    }

    // billions

    else if ((to_string(aNum).length()) <= 12)
    {
        cout << (aNum / bill) << ",";
        addCommas((aNum % bill));
    }

    // trillions

    else if ((to_string(aNum).length()) <= 15)
    {
        cout << (aNum / trill) << ",";
        addCommas((aNum % trill));
    }

    // quadrillions

        else if ((to_string(aNum).length()) <= 18)
    {
        cout << (aNum / quad) << ",";
        addCommas((aNum % quad));
    }

    // quintillions

    else if ((to_string(aNum).length()) == 19)
    {
        cout << (aNum / quint) << ",";
        addCommas((aNum % quint));
    }

    // if all else fails (number has more than 19 digits)
    else
    {
        cout << "NUMBER IS TOO LARGE!!!" << endl;
    }
    
}