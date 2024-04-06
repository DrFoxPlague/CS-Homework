/*----
  signature: main: void -> int

  purpose: testing program for the class GameCard

  by: Dakota Donner
  last modified: 4-18-2022

  compile project with: g++ GameCard-test.cpp GameCard.cpp -o GameCard
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GameCard.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << endl;
    cout << "--- TESTING CLASS GameCard ---"
         << endl
         << endl;

    cout << "~ testing constructors & accessors ~" 
         << endl << endl;

    GameCard ferox;
    GameCard xath(10, 20, "Xa'Therium, Consumer of Galaxies",
                  "Eldritch Vulpine", "Deity", "legendary",
                  "colorless", 12, "yes");
    GameCard blank_card;

    cout << "= ferox =" << endl;
    cout << ( (ferox.get_attack() == 0) &&
              (ferox.get_defense() == 0) && 
              (ferox.get_name() == "") &&
              (ferox.get_species() == "") &&
              (ferox.get_subtype() == "") &&
              (ferox.get_rarity() == "common") &&
              (ferox.get_mana_type() == "") &&
              (ferox.get_mana_cost() == 0) &&
              (ferox.get_mythic_status() == "no") ) << endl;

    cout << "= xath =" << endl;
    cout << ( (xath.get_attack() == 10) &&
              (xath.get_defense() == 20) && 
              (xath.get_name() == "Xa'Therium, Consumer of Galaxies") &&
              (xath.get_species() == "Eldritch Vulpine") &&
              (xath.get_subtype() == "Deity") &&
              (xath.get_rarity() == "legendary") &&
              (xath.get_mana_type() == "colorless") &&
              (xath.get_mana_cost() == 12) &&
              (xath.get_mythic_status() == "yes") ) << endl;

    cout << endl << endl
         << "~ testing mutators ~"
         << endl << endl;

    ferox.set_name("Ferox");
    ferox.set_attack(4);
    ferox.set_species("Werewolf");
    ferox.set_subtype("Assassin");
    ferox.set_mana_type("fire");
    ferox.set_mana_cost(3);

    cout << (ferox.get_attack() == 4) << endl;
    cout << (ferox.get_name() == "Ferox") << endl;
    cout << (ferox.get_species() == "Werewolf") << endl;
    cout << (ferox.get_subtype() == "Assassin") << endl;
    cout << (ferox.get_rarity() == "common") << endl;
    cout << (ferox.get_mana_type() == "fire") << endl;
    cout << (ferox.get_mana_cost() == 3) << endl;

    cout << endl << endl
         << "~ testing others ~"
         << endl << endl;

    cout << "= display_card =" << endl;
    blank_card.display_card();

    cout << endl << endl
         << "We should see attack, defense, and mana cost values" << endl
         << "of 0, empty string values, and a mythic status of no" << endl;

    xath.display_card();

    cout << endl << endl
         << "We should see an attack of 10, " << endl
         << "defense of 20, the name of Xa'Therium, " << endl
         << "Consumer of Galaxies, a species of Eldritch Vulpine," << endl
         << "a subtype of Deity, a legendary rarity, a colorless" << endl
         << "mana type, a mana cost of 12, and a mythic status of yes" << endl;

    cout << endl
         << "= card_to_string =" << endl;
    cout << (blank_card.card_to_string() == 
             "GameCard(0, 0, , , , common, , 0, no)") << endl;
    cout << (xath.card_to_string() ==
           "GameCard(10, 20, Xa'Therium, Consumer of Galaxies, Eldritch Vulpine, Deity, legendary, colorless, 12, yes)") << endl;

     cout << "\n~ testing == operator ~" << endl <<endl;

     cout << "comparing one to itself...should see true: " << endl;
     cout << (xath == xath) << endl;

     cout << "\ncomparing one to unequal card...should see false: " << endl;
     cout << (xath == ferox) << endl;

    return EXIT_SUCCESS;
}