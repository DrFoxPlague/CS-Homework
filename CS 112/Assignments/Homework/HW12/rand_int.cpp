/*===
    signature: rand_int: int int -> int
    purpose: expects a desired minimum integer and a desired
        maximum integer, and attempts to use the C++11 <random>
        library to return an integer in the range
        [desired minimum integer, desired maximum integer]

        references:
        *   https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
        *   "A Tour of C++", Stroustrup, Addison-Wesley, 2014, Chapter 5, Section 5.6.3
        *   https://www.cplusplus.com/reference/random/mt19937/

    tests:
        for:
	int looky = rand_int(1, 10);

        (1 <= looky) && (looky <= 10)

        for:
	int val = rand_int(-5, 3);

        (-5 <= val) && (val <= 3)

    adapted by: Sharon Tuttle
    last modified: 2022-02-04
===*/

#include <random>
#include <iostream>
using namespace std;

int rand_int(int desired_min, int desired_max)
{
    // question is it REALLY OK to re-create these each time
    //     this function is called?

    random_device rand_dev;

    // quoting from https://www.cplusplus.com/reference/random/mt19937/:
    // "A Mersenne Twister pseudo-random generator of 32-bit numbers
    //     with a state size of 19937 bits."

    mt19937 mt( rand_dev() );
    uniform_int_distribution<int> dist(desired_min, desired_max);

    return dist(mt);
}