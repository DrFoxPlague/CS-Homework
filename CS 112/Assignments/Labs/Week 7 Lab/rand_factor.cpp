/*===
    signature: rand_factor: int int -> int
    purpose: attempts to use the C++11 <random>
        library to return a double in the range
        [0.1, 0.9]

        references:
        *   https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
        *   "A Tour of C++", Stroustrup, Addison-Wesley, 2014, Chapter 5, Section 5.6.3
        *   https://www.cplusplus.com/reference/random/mt19937/

    tests:
        for:
	double looky = rand_factor();

        (0.1 <= looky) && (looky <= 0.9)

        for:
	double val = rand_factor();

        (0.1 <= val) && (val <= 0.9)

    adapted by: Sharon Tuttle
    last modified: 2022-03-04
===*/

#include <random>
#include <iostream>
using namespace std;

double rand_factor()
{
    // question is it REALLY OK to re-create these each time
    //     this function is called?

    random_device rand_dev;

    // quoting from https://www.cplusplus.com/reference/random/mt19937/:
    // "A Mersenne Twister pseudo-random generator of 32-bit numbers
    //     with a state size of 19937 bits."

    mt19937 mt( rand_dev() );
    uniform_real_distribution<double> dist(0.1, 0.9);

    return dist(mt);
}