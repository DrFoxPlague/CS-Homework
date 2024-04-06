/*----
  implementation file for class: GoldExotic

  a GoldExotic is a very special edition of a GameCard.
  Gold exotic cards are the most powerful cards, and always has 
  a specialty perk that can greatly assist you in the battlefield.

  by: Dakota Donner
  last modified: 4-27-2022
----*/
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "GameCard.h"
#include "GoldExotic.h"
#include <string>

using namespace std;

// constructors

GoldExotic::GoldExotic(): GameCard()
{
    exotic_perk = "no perk...";
}

GoldExotic::GoldExotic(int init_attack, int init_defense, string init_name,
           string init_species, string init_subtype, string init_rarity,
           string init_mana_type, int init_mana_cost, string init_mythic_status, 
           string init_exotic_perk): GameCard(init_attack, init_defense, init_name,
           init_species, init_subtype, init_rarity,
           init_mana_type, init_mana_cost, init_mythic_status)
{
    exotic_perk = init_exotic_perk;
}

// accessors
      
string GoldExotic::get_exotic_perk() const
{
    return exotic_perk;
}

// mutators

void GoldExotic::set_exotic_perk(string new_exotic_perk)
{
    exotic_perk = new_exotic_perk;
}

// Overloaded ==

bool GoldExotic::operator==(const GoldExotic& rhs)
{
    return ( (GameCard::operator== (rhs)) && (exotic_perk == rhs.exotic_perk) );
}

// misc methods

/*
    signature: display_card: void -> void

    purpose: expects nothing, prints all publicly accessible
             card data to the screen, and returns nothing.

    tests: for:
           GoldExotic blank_card;

           blank_card.display_card();

           the following will print:
    GoldExotic:
        attack: 0
        defense: 0
        name: 
        species: 
        subtype: 
        rarity: common
        mana type: 
        mana cost: 0 
        mythic?: no
        exotic perk: no perk...


           for:
           GoldExotic hatchling(3, 5, "The Hatchling", "Hearthian", "Explorer", "legendary",
                                "water", 6, "no", "Time Loop")

           xath.display_card();

           the following will print:
    GoldExotic:
        attack: 3
        defense: 5
        name: The Hatchling
        species: Hearthian
        subtype: Explorer
        rarity: legendary
        mana type: water
        mana cost: 6
        mythic?: no
        exotic perk: Time Loop
*/

void GoldExotic::display_card() const
{
    cout << endl;
    cout << "GoldExotic:\n"
         << "   attack: " << get_attack() << endl
         << "   defense: " << get_defense() << endl
         << "   name: " << get_name() << endl
         << "   species: " << get_species() << endl
         << "   subtype: " << get_subtype() << endl
         << "   rarity: " << get_rarity() << endl
         << "   mana type: " << get_mana_type() << endl
         << "   mana cost: " << get_mana_cost() << endl
         << "   mythic?: " << get_mythic_status() << endl
         << "   exotic perk: " << exotic_perk << endl;
}

/*
    signature: card_to_string: void -> string

    purpose: expects nothing, and returns a string value that
             displays the calling of a chosen GoldExotic.
*/

string GoldExotic::card_to_string() const
{
    return "GoldExotic(" + to_string(get_attack()) + ", "
           + to_string(get_defense()) + ", "
           + get_name() + ", " 
           + get_species() + ", "
           + get_subtype() + ", "
           + get_rarity() + ", "
           + get_mana_type() + ", "
           + to_string(get_mana_cost()) + ", "
           + get_mythic_status() + ", "
           + exotic_perk + ")";
}