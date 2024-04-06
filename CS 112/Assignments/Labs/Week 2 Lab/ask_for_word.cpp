/*----
  signature: ask_for_word: string -> string

  purpose: expects a user's name, has a side effect of
           asking the user, by name, to enter a five letter
           word and reading in what they enter until they do so,
           and returns the resulting five letter word.

  tests: if the user Jenna enters:
            1
            moo
            12345
            moo23
            sandstone
            moons
         when prompted, then:
            ask_for_word("Jenna") == "moons"

         if the user Carlos enters
            Slick
         when prompted, then:
            ask_for_word("Carlos") == "Slick"


  by: Dakota Donner
  last modified: 1-28-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "five_letter_word.h"
using namespace std;

string ask_for_word(string user_name)
{
    string user_entry;

    cout << "Hello, " + user_name + "." << endl;
    cout << "Please enter a string: " << endl;

    cin >> user_entry;

    while (!five_letter_word(user_entry))
    {
        cout << "Not 5 letters!  Try again!" << endl;
        cin >> user_entry;
    }

    return user_entry;
}