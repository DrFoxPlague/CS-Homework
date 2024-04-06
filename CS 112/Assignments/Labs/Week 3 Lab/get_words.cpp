/*----
  signature: get_words : string string[] int -> int
  purpose: Expects a file name that contains words, one on each line, a string array and that array size 
           then has the side effect of reading from that file, filling the array and closing output stream
           and returns the number of words it thinks it read. 
  tests:
        get_words("lab3-1", things, 3) == 3
        get_words("lab3-2", question, 5) == 5

  by: Dakota Donner, Peter Ramos
  last modified: 2/4/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "show_words.h"
using namespace std;

int get_words(string file_name, string word_array[], int size)
{
    ifstream reading_stream;
    reading_stream.open(file_name);
    
    string word_in_file;
    int count = 0;
    
    
    for (int i = 0; i < size; i++)
    {
        reading_stream >> word_in_file;
        word_array[i] = word_in_file;
        count++;
    }
    
    reading_stream.close();
    
    cout << show_words(word_array, size) << endl;
    return count;
}

