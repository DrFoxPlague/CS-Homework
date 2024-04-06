/*----
  signature: main: void -> int

  purpose: main function
           which does the following:

           1. Asks the user for a file in the structure
              provided by function save_words

           2. calls get_size to read the number of words
              in that file, and then declares an array of
              that size.

           3. calls read_words to read the words in that array

           4. calls rand_int to get a pseudo-random choice of
              index, and makes the word at that index the
              word of the day.

           5. asks the user to enter their guess of a word
              or to just type enter to quit.

           6. calls guess_match to display how close their 
              guess is.

           7. gives a farewell message appropriate to the situation.

  by: Dakota Donner
  last modified: 2-11-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "get_size.h"
#include "read_words.h"
#include "rand_int.h"
#include "guess_match.h"
using namespace std;

int main()
{
    cout << boolalpha;

    string desired_file;
    ifstream guessing_stream;

    cout << "Give me a .txt file: ";
    cin >> desired_file;
    guessing_stream.open(desired_file);

    int word_amt = get_size(desired_file);
    string guess_array[word_amt];

    read_words(desired_file, guess_array, word_amt);

    guessing_stream.close();

    int array_index = rand_int(0, (word_amt - 1));
    string word_of_day = guess_array[array_index];

    string guessed_word;

    cout << "Allrighty, enter a guess or type enter to quit: ";
    cin.ignore();
    getline(cin, guessed_word);

    while ((guessed_word != word_of_day) && (guessed_word != ""))
    {
        cout << "Hmm...Well, here's your results so far:"
             << endl
             << endl;

        cout << (guess_match(word_of_day, guessed_word))
             << endl
             << endl;

        cout << "Give it another try!  Or type enter to quit...I guess... ";
        getline(cin, guessed_word);
    }

    if (guessed_word == word_of_day)
    {
        cout << "YOOOOO, YOU GOT IT!!!  CONGRATZZZ!!" << endl;
    }

    else
    {
        cout << "Fine...Go >:T" << endl;
    }

   


    return EXIT_SUCCESS;
}