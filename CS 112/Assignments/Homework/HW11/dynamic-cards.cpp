/*----
  signature: main: void -> int

  purpose: testing dynamic/late binding for classes
           GoldExotic and GameCard

  by: Dakota Donner
  last modified: 5-3-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "GoldExotic.h"
using namespace std;

int main()
{
    cout << boolalpha;

    vector<GameCard*> dyn_card_set;

    dyn_card_set.push_back(new GameCard(10, 10, "Dark Bramble Anglerfish", "alien", 
                                        "creature", "rare", "dark", 8, "no"));
    dyn_card_set.push_back(new GoldExotic(3, 5, "The Hatchling", "Hearthian", 
                                          "Explorer", "legendary", "water", 6, "no", "Time Loop"));
    dyn_card_set.push_back(new GameCard(5, 6, "Owlelk Guard", "Owlelk", "Guard", 
                                        "uncommon", "earth", 5, "no"));
    dyn_card_set.push_back(new GoldExotic(7, 9, "The Prisoner", "Owlelk", "Prisoner", 
                                          "legendary", "earth", 7, "yes", "Alternate Reality"));
    dyn_card_set.push_back(new GameCard(2, 3, "Nomai Scientist", "Nomai", "Scientist", 
                                        "uncommon", "fire", 3, "no"));
    dyn_card_set.push_back(new GoldExotic(3, 6, "Solanum, the Quantum Pilgrim", "Nomai", "Pilgrim",
                                          "legendary", "fire", 5, "no", "Quantum"));
    dyn_card_set.push_back(new GameCard(2, 2, "Hearthian Scientist", "Hearthian",
                                         "Scientist", "common", "water", 3, "no"));
    dyn_card_set.push_back(new GoldExotic(6, 5, "Feldspar, the Daredevil", "Hearthian",
                                        "Pilot", "legendary", "water", 5, "no", "Crash Landing"));
 
    for (int c = 0; c < dyn_card_set.size(); c++)
    {
        dyn_card_set[c]->display_card();
    }

    for (int c = 0; c < dyn_card_set.size(); c++)
    {
        cout << endl << (dyn_card_set[c]->card_to_string()) << endl;
    }

    for (int c = 0; c < dyn_card_set.size(); c++)
    {
        delete dyn_card_set[c];
    }

    return EXIT_SUCCESS;
}