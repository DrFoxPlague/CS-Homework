/*----
  signature: main: void -> int

  purpose: testing program for derived class GoldExotic

  by: Dakota Donner
  last modified: 4-27-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GoldExotic.h"
using namespace std;

int main()
{
    cout << boolalpha;

    // declaring instances

    GoldExotic john;
    GoldExotic hatchling(3, 5, "The Hatchling", "Hearthian", "Explorer", "legendary",
                         "water", 6, "no", "Time Loop");

    // testing accessors after initialization

    cout << "\n--- TESTING ACCESSORS(new) ---\n";
    cout << (john.get_exotic_perk() == "no perk...") << endl;
    cout << (hatchling.get_exotic_perk() == "Time Loop") << endl;

    cout << "\n--- TESTING ACCESSORS(inherited) ---\n";
    cout << ( (john.get_attack() == 0) &&
              (john.get_defense() == 0) && 
              (john.get_name() == "") &&
              (john.get_species() == "") &&
              (john.get_subtype() == "") &&
              (john.get_rarity() == "common") &&
              (john.get_mana_type() == "") &&
              (john.get_mana_cost() == 0) &&
              (john.get_mythic_status() == "no") ) << endl;
    cout << ( (hatchling.get_attack() == 3) &&
              (hatchling.get_defense() == 5) && 
              (hatchling.get_name() == "The Hatchling") &&
              (hatchling.get_species() == "Hearthian") &&
              (hatchling.get_subtype() == "Explorer") &&
              (hatchling.get_rarity() == "legendary") &&
              (hatchling.get_mana_type() == "water") &&
              (hatchling.get_mana_cost() == 6) &&
              (hatchling.get_mythic_status() == "no") ) << endl;

    // testing mutators

    cout << "\n--- TESTING MUTATORS --- \n";

    john.set_attack(5);
    john.set_defense(5);
    john.set_name("John Marston");
    john.set_species("Human");
    john.set_subtype("Cowboy");
    john.set_rarity("legendary");
    john.set_mana_type("earth");
    john.set_mana_cost(5);
    john.set_mythic_status("yes");
    john.set_exotic_perk("Deadeye");

    cout << "...testing for GoldExotic instance john:\n";
    cout << "new: " << (john.get_exotic_perk() == "Deadeye") << endl;
    cout << "inherited: " << ( (john.get_attack() == 5) &&
                               (john.get_defense() == 5) && 
                               (john.get_name() == "John Marston") &&
                               (john.get_species() == "Human") &&
                               (john.get_subtype() == "Cowboy") &&
                               (john.get_rarity() == "legendary") &&
                               (john.get_mana_type() == "earth") &&
                               (john.get_mana_cost() == 5) &&
                               (john.get_mythic_status() == "yes") ) << endl;

    cout << "\n--- TESTING MISC ---\n";

    cout << "\nSHOULD SEE: \n" << "GoldExotic:"
                             << "\n   attack: 3"
                             << "\n   defense: 5"
                             << "\n   name: The Hatchling"
                             << "\n   species: Hearthian"
                             << "\n   subtype: Explorer"
                             << "\n   rarity: legendary"
                             << "\n   mana type: water"
                             << "\n   mana cost: 6"
                             << "\n   mythic?: no"
                             << "\n   exotic perk: Time Loop\n" << endl;

    hatchling.display_card();
    cout << "\n...testing card_to_string on GoldExotic instance hatchling:\n";

    cout << (hatchling.card_to_string() == "GoldExotic(3, 5, The Hatchling, Hearthian, Explorer, legendary, water, 6, no, Time Loop)") << endl;

    cout << "\n--- TESTING OVERLOADED == ---\n";
    GoldExotic hatchling_EOTE_edit(3, 5, "The Hatchling", "Hearthian", "Explorer", "legendary",
                               "water", 6, "no", "Blinding Light");

    GoldExotic john_clone(5, 5, "John Marston", "Human", "Cowboy", 
                      "legendary", "earth", 5, "yes", "Deadeye");

    cout << ((hatchling == hatchling) == true) << endl;
    cout << ((hatchling == hatchling_EOTE_edit) == false) << endl;
    cout << ((john == john_clone) == true) << endl;
    cout << ((hatchling == john) == false) << endl;

    cout << "--- CALLING BASE CLASS VERS OF MISC METHODS --- \n";
    hatchling.GameCard::display_card();
    cout << endl << (hatchling.GameCard::card_to_string()) << endl;

    return EXIT_SUCCESS;
}