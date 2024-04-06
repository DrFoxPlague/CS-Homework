/*----
  signature: get_size: string -> int

  purpose: expects the name of a file with the same structure of
           any files created by function save_words, has the side-effect
           of reading into the specified file, and returns the first
           line as an integer value.

  tests: get_size("list-of-trees.txt") == 4
         get_size("basic-school-subjects.txt") == 5

  by: Dakota Donner
  last modified: 2-11-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int get_size(string name_of_file)
{
    int first_line;

    ifstream reading_stream;
    reading_stream.open(name_of_file);

    reading_stream >> first_line;
    reading_stream.close();

    return first_line;
}