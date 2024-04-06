/*----
    Designing of methods for class GameCard

    a GameCard is designed to store values for the 
    stats of a playable card in a creature-fighting
    trading card game.

  by: Dakota Donner
  last modified: 4-18-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GameCard.h"
using namespace std;

// constructors

GameCard::GameCard()
{
    attack = 0;
    defense = 0;
    name = "";
    species = "";
    subtype = "";
    rarity = "common";
    mana_type = "";
    mana_cost = 0;
    is_mythic = "no";
}

GameCard::GameCard(int init_attack, int init_defense, string init_name,
             string init_species, string init_subtype, string init_rarity,
             string init_mana_type, int init_mana_cost, string init_mythic_status)
{
    attack = init_attack;
    defense = init_defense;
    name = init_name;
    species = init_species;
    subtype = init_subtype;
    rarity = init_rarity;
    mana_type = init_mana_type;
    mana_cost = init_mana_cost;
    is_mythic = init_mythic_status;
}

// accessors

int GameCard::get_attack() const
{
    return attack;
}

int GameCard::get_defense() const
{
    return defense;
}

string GameCard::get_name() const
{
    return name;
}

string GameCard::get_species() const
{
    return species;
}

string GameCard::get_subtype() const
{
    return subtype;
}

string GameCard::get_rarity() const
{
    return rarity;
}

string GameCard::get_mana_type() const
{
    return mana_type;
}

int GameCard::get_mana_cost() const
{
    return mana_cost;
}

string GameCard::get_mythic_status() const
{
    return is_mythic;
}

// mutators

void GameCard::set_attack(int new_attack)
{
    attack = new_attack;
}

void GameCard::set_defense(int new_defense)
{
    defense = new_defense;
}

void GameCard::set_name(string new_name)
{
    name = new_name;
}

void GameCard::set_species(string new_species)
{
    species = new_species;
}

void GameCard::set_subtype(string new_subtype)
{
    subtype = new_subtype;
}

void GameCard::set_rarity(string new_rarity)
{
    rarity = new_rarity;
}

void GameCard::set_mana_type(string new_mana_type)
{
    mana_type = new_mana_type;
}

void GameCard::set_mana_cost(int new_mana_cost)
{
    mana_cost = new_mana_cost;
}

void GameCard::set_mythic_status(string new_mythic_status)
{
    is_mythic = new_mythic_status;
}

// Overloaded == Operator

bool GameCard::operator==(const GameCard& rhs)
{
    return ( (attack == rhs.attack) &&
             (defense == rhs.defense) &&
             (name == rhs.name) &&
             (species == rhs.species) &&
             (subtype == rhs.subtype) &&
             (rarity == rhs.rarity) &&
             (mana_type == rhs.mana_type) &&
             (mana_cost == rhs.mana_cost) &&
             (is_mythic == rhs.is_mythic));
}

// others

/*
    signature: display_card: void -> void

    purpose: expects nothing, prints all publicly accessible
             card data to the screen, and returns nothing.

    tests: for:
           GameCard blank_card;

           blank_card.display_card();

           the following will print:
    GameCard:
        attack: 0
        defense: 0
        name: 
        species: 
        subtype: 
        rarity: common
        mana type: 
        mana cost: 0 
        mythic?: no


           for:
           GameCard xath(10, 20, "Xa'Therium, Consumer of Galaxies",
                         "Eldritch Vulpine", "Deity", "legendary",
                         "colorless", 12, true)

           xath.display_card();

           the following will print:
    GameCard:
        attack: 10
        defense: 20
        name: Xa'Therium, Consumer of Galaxies
        species: Eldritch Vulpine
        subtype: Deity
        rarity: legendary
        mana type: colorless
        mana cost: 12
        mythic?: yes
*/

void GameCard::display_card() const
{
    cout << endl;
    cout << "GameCard:\n"
         << "   attack: " << attack << endl
         << "   defense: " << defense << endl
         << "   name: " << name << endl
         << "   species: " << species << endl
         << "   subtype: " << subtype << endl
         << "   rarity: " << rarity << endl
         << "   mana type: " << mana_type << endl
         << "   mana cost: " << mana_cost << endl
         << "   mythic?: " << is_mythic << endl;
}

/*
    signature: card_to_string: void -> string

    purpose: expects nothing, and returns a string value that
             displays the calling of a chosen GameCard.
    
    tests: for:
           GameCard blank_card;

           blank_card.card_to_string() == 
           "GameCard(0, 0, , , , common, , 0, no)"


           for:
           GameCard xath(10, 20, "Xa'Therium, Consumer of Galaxies",
                         "Eldritch Vulpine", "Deity", "legendary",
                         "colorless", 12, yes)

           xath.card_to_string() ==
           "GameCard(10, 20, Xa'Therium, Consumer of Galaxies, Eldritch Vulpine, Deity, legendary, colorless, 12, yes)"
*/

string GameCard::card_to_string() const
{
    return "GameCard(" + to_string(attack) + ", "
           + to_string(defense) + ", "
           + name + ", " 
           + species + ", "
           + subtype + ", "
           + rarity + ", "
           + mana_type + ", "
           + to_string(mana_cost) + ", "
           + is_mythic + ")";
}