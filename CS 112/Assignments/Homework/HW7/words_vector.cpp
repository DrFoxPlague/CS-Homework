/*----
  signature: main: void -> int

  purpose: main function designed to store a file
           with a word on each line into a string vector.

  by: Dakota Donner
  last modified: 3-25-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    cout << boolalpha;

    // local variables

    string file_name;
    vector<string> words;
    string word_in_stream;
    bool exit = false;
    int count = 0;


    // body

    cout << "Enter the name of a file within the same directory as me: ";
    cin >> file_name;
    cout << endl;

    ifstream reading_stream;
    reading_stream.open(file_name);

    while (exit != true)
    {
        if (!reading_stream.eof())
        {
            reading_stream >> word_in_stream;
            words.push_back(word_in_stream);
            count++;
        }

        else
        {
            exit = true;
        }
    }

    reading_stream.close();

    cout << "Words added to vector: " << count << endl << endl;

    cout << "Contents of vector: " << endl;

    for (int c = 0; c < words.size(); c++)
    {
        cout << words[c] << endl;
    }

    cout << "\nLength of each word: " << endl;

    for (int c = 0; c < words.size(); c++)
    {
        cout << words[c] << ": " << words[c].length() << endl;
    }

    return EXIT_SUCCESS;
}