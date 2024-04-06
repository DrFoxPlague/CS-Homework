/*----
  signature: main: void -> int
  
  purpose: testing function save_words

  by: Dakota Donner
  last modified: 2-11-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "save_words.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "--- Testing save_words ---" << endl;

    string trees[4] = {"birch", "spruce", "pine", "oak"};

    save_words(trees, 4, "list-of-trees.txt");

    cout << "There should now be a file list-of-trees.txt in the same directory." << endl;
    cout << "It should read: " << endl;
    cout << "4\n"
         << "birch\n"
         << "spruce\n"
         << "pine\n"
         << "oak" << endl;

    string basic_school_subj[5] = {"math", "science", "history", "english", "art"};

    save_words(basic_school_subj, 5, "basic-school-subjects.txt");

    cout << "There should now be a file basic-school-subjects.txt in the same directory." << endl;
    cout << "It should read:" << endl;
    cout << "5\n"
         << "math\n"
         << "science\n"
         << "history\n"
         << "english\n"
         << "art" << endl;

    return EXIT_SUCCESS;
}