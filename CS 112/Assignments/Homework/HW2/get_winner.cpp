/*----
  signature: get_winner: char char -> int

  purpose: expects a rock-paper-scissors move, in
           the form of a single character, from two different
           players, and returns an integer value that depends
           on who the winner is:

           -1 if one or both players choose an invalid move,
           0 if they tie,
           1 if player 1 wins, or
           2 if player 2 wins.

  tests: get_winner('v', 'r') == -1
         get_winner('p', 'x') == -1
         get_winner('q', 't') == -1
         get_winner('r', 'r') == 0
         get_winner('p', 'p') == 0
         get_winner('s', 's') == 0
         get_winner('p', 'r') == 1
         get_winner('r', 's') == 1
         get_winner('s', 'p') == 1
         get_winner('r', 'p') == 2
         get_winner('p', 's') == 2
         get_winner('s', 'r') == 2

  by: Dakota Donner
  last modified: 2-4-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "legal_move.h"
using namespace std;

int get_winner(char p1_choice, char p2_choice)
{
    if (!legal_move(p1_choice) || !legal_move(p2_choice))
    {
        return -1;
    }

    else if (p1_choice == p2_choice)
    {
        return 0;
    }

    else if (p1_choice == 'r')
    {
        switch (p2_choice)
        {
            case 's':
                return 1;
                break;

            case 'p':
                return 2;
                break;
        }
    }

    else if (p1_choice == 'p')
    {
        switch (p2_choice)
        {
            case 'r':
                return 1;
                break;

            case 's':
                return 2;
                break;
        }
    }

    else if (p1_choice == 's')
    {
        switch (p2_choice)
        {
            case 'p':
                return 1;
                break;

            case 'r':
                return 2;
                break;
        }
    }
}