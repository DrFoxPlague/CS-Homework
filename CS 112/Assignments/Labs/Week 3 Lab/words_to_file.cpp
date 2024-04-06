/*----
  signature: words_to_file: string int -> int
  purpose: expects a name of a file and the number of words desired, and has the 
           side effect of creating a file with the desired name and asks the user
           enter that many words into the file and returns the number of words it
           thinks it wrote to that file. 
  tests:
        words_to_file("lab3-1.txt", 3)
        
        then if the user enters 
        
        cabbage
        potato
        armadillo

        this will create a file with those three words written in it on seperate lines and return 3
        
        words_to_file("lab3-2.txt", 5)
        
        then if the user enters 
        
        What
        are
        we
        gonna
        do?

        this will create a file with those three words written in it on seperate lines and return 5
        
  by: Dakota Donner, Peter Ramos
  last modified: 2/4/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int words_to_file(string file_name, int num_of_words)
{
    ofstream writing_stream;
    writing_stream.open(file_name);
    
    string entered_word;
    int words_written = 0;
    
    for (int i = 0; i < num_of_words; i++)
    {
        cin >> entered_word;
        writing_stream << entered_word << endl;
        words_written ++;
    }
    
    writing_stream.close();
    
    return words_written;
}

