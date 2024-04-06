/*----
  signature: main: void -> int

  purpose: program to test vectors containing both
           GameCard and GoldExotic instances.

  by: Dakota Donner
  last modified: 4-27-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GoldExotic.h"
#include <vector>
using namespace std;

int main()
{
    cout << boolalpha;

    // declaring instances

    GoldExotic hatchling(3, 5, "The Hatchling", "Hearthian", "Explorer", "legendary",
                         "water", 6, "no", "Time Loop");

    GoldExotic solanum(3, 6, "Solanum, the Quantum Pilgrim", "Nomai", "Pilgrim",
                       "legendary", "fire", 5, "no", "Quantum");

    GoldExotic prisoner(7, 9, "The Prisoner", "Owlelk", "Prisoner", "legendary",
                        "earth", 7, "yes", "Alternate Reality");

    GameCard anglerfish(10, 10, "Dark Bramble Anglerfish", "alien", 
                        "creature", "rare", "dark", 8, "no");

    GameCard nomai(2, 3, "Nomai Scientist", "Nomai", "Scientist", "uncommon",
                   "fire", 3, "no");

    GameCard owlelk(5, 6, "Owlelk", "Owlelk", "Guard", "uncommon",
                    "earth", 5, "no");

    // building vector

    vector<GameCard> card_set;

    card_set.push_back(hatchling);
    card_set.push_back(anglerfish);
    card_set.push_back(solanum);
    card_set.push_back(nomai);
    card_set.push_back(prisoner);
    card_set.push_back(owlelk);

    for (int c = 0; c < card_set.size(); c++)
    {
        card_set[c].display_card();
        cout << endl;
    }

    return EXIT_SUCCESS;
}