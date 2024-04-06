/*----
  signature: save_words: string[] int string -> void

  purpose: expects an array of words, the array's size,
           a desired file name, and has a side-effect
           of writing the following contents to the
           named file:

           on the first line, the number of words to be 
           written,

           and the contents of the array, with each word
           on their own line.
  
  tests: string trees[4] = {"birch", "spruce", "pine", "oak"};

         save_words(trees, 4, "list-of-trees.txt");

         There should now be a file list-of-trees.txt in the same directory.
         It should read:
         4
         birch
         spruce
         pine
         oak


         string basic_school_subj[5] = {"math", "science", "history", "english", "art"};

         save_words(basic_school_subj, 5, "basic-school-subjects.txt");

         There should now be a file basic-school-subjects.txt in the same directory.
         It should read:
         5
         math
         science
         history
         english
         art


  by: Dakota Donner
  last modified: 2-11-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

void save_words(string word_arr[], int arr_size, string file_name)
{
  ofstream writing_stream;
  writing_stream.open(file_name);
  writing_stream << arr_size << endl;

  for (int c = 0; c < arr_size; c++)
  {
    writing_stream << word_arr[c] << endl;
  }

  writing_stream.close();
}