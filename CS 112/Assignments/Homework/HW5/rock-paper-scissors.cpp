/*----
  signature: main: void -> int

  purpose: either:
           testing program for the function <name>
           OR
           <describe the program being written --
           what it needs, if anything, and what it does>

  by: Dakota Donner
  last modified:
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "rand_int.h"
#include "get_winner.h"
#include "legal_move.h"
using namespace std;

int main()
{
    cout << boolalpha;

    // local variables

    int play_count;
    char p2_dec;
    char p1_dec;

    // code

    cout << "welcome to..." << endl;

    cout << "=== ROCK, PAPER, SCISSORS ===" << endl << endl;

    cout << "How many times would you like to play? ";
    cin >> play_count;

    char *p2_plays;
    p2_plays = new char[play_count];

    for (int c = 0; c < play_count; c++)
    {
        switch (rand_int(1, 3))
        {
            case 1:
                p2_dec = 'r';
                break;

            case 2:
                p2_dec = 'p';
                break;

            case 3:
                p2_dec = 's';
                break;
        }

        p2_plays[c] = p2_dec;
    }

    for (int c = 0; c < play_count; c++)
    {
        cout << endl;
        cout << "Okay, what's your move? ";
        cin >> p1_dec;

        cout << "Player 1: " << p1_dec << endl;
        cout << "Player 2: " << p2_plays[c] << endl;

        switch (get_winner(p1_dec, p2_plays[c]))
        {
            case -1:
                cout << "Whoops...Illegal move :/" << endl;
                break;

            case 0:
                cout << "Tie." << endl;
                break;

            case 1:
                cout << "Player 1 wins!" << endl;
                break;

            case 2:
                cout << "Player 2 wins!" << endl;
                break;
        }
    }

    delete [] p2_plays;
    p2_plays = NULL;

    return EXIT_SUCCESS;
}