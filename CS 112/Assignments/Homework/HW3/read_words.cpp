/*----
  signature: read_words: string string[] -> void

  purpose: expects the name of a file, assumed to have
           the same structure as a file created by function
           save_words, an array that can hold words, and
           the array's desired size, has the following side effects:

           1. reading from the desired file, grabbing the first
              line as an integer value, and if it does not match
              the given array size, it will print an error to
              the screen.

           2. if the integer value matches, it will have an additional
              side-effect of filling the given array with the contents
              of the file...

              ...and returns nothing

  tests: read_words("list-of-trees.txt", trees, 4)
         read_words("list-of-trees.txt", trees, 6)
         read_words("basic-school-subjects.txt", subjects, 5)
         read_words("basic-school-subjects.txt", subjects, 4)

  by: Dakota Donner
  last modified:
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

void read_words(string file_name, string word_arr[], int arr_size)
{
    string word_to_store;
    int first_line;

    ifstream storing_stream;
    storing_stream.open(file_name);

    storing_stream >> first_line;

    if (arr_size != first_line)
    {
        cout << "[ERROR!!!]\n"
             << "AMOUNT OF WORDS DOES NOT MATCH ARRAY SIZE!"
             << endl;

        return;
    }

    else
    {
        for(int c = 0; c < arr_size; c++)
        {
            storing_stream >> word_to_store;
            word_arr[c] = word_to_store;
        }
    }
}