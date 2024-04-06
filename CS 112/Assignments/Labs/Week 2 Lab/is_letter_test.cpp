/*----
  signature: main: void -> int
  purpose: testing program for the function is_letter

  compile using:
      g++ is_letter_test.cpp is_letter.cpp -o is_letter_test
  run using:
      ./is_letter_test

  by: Sharon Tuttle
  last modified: 2022-01-28
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "is_letter.h"    
using namespace std;

int main()
{
    cout << boolalpha;

    cout << (is_letter('g') == true) << endl;
    cout << (is_letter('H') == true) << endl;
    cout << (is_letter(' ') == false) << endl;
    cout << (is_letter('.') == false) << endl;
    cout << (is_letter('4') == false) << endl;
    cout << (is_letter('A') == true) << endl;
    cout << (is_letter('a') == true) << endl;
    cout << (is_letter('Z') == true) << endl;
    cout << (is_letter('z') == true) << endl;      

    return EXIT_SUCCESS;
}