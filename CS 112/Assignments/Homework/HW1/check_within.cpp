/*---
    For CS 112 - Homework 1 - Problem 3

    compile using:
        g++ 112prob3.cpp -o 112prob3
    run using:
        ./112prob3

    by: Sharon Tuttle
    modified by: Dakota Donner
    last modified: 2022-01-26
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*---
  signature: check_within: double double double -> bool

  purpose: expects a function call, its expected value,
      and how close is "close enough" (delta), and returns
      true if the absolute value of the difference of
      the function call and its expected value is less than
      the "close enough"/delta value
      
  tests:
      check_within(sqrt(4), 2.0, 0.1) == true
      check_within(sqrt(2), 1.4, 0.001) == false

      // attempt at a a boundary test -- if equal to delta,
      //    check_within will return false

      check_within(sqrt(9), 3.0, 0.0) == false
---*/

bool check_within(double funct_call, double expected_val,
                  double delta)
{
    return abs(funct_call - expected_val) < delta;
}