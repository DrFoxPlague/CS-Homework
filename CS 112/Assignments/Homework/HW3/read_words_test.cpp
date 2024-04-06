/*----
  signature: main: void -> int

  purpose: testing function read_words

  by: Dakota Donner
  last modified: 2-11-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "read_words.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "--- Testing read_words ---" << endl;

    string trees[4];
    string subjects[5];

    read_words("list-of-trees.txt", trees, 4);
    read_words("basic-school-subjects.txt", subjects, 5);

    cout << "Both of the following intentionally return errors:" << endl;
    read_words("list-of-trees.txt", trees, 6);
    read_words("basic-school-subjects.txt", subjects, 4);

    return EXIT_SUCCESS;
}