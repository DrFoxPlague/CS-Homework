/*---
CS 211 Fall 2022 – Week 02 Lab
Jonathan Thang and Dakota Donner
---*/

/*=====
 PlayerChar
    implementation of the constructors and methods for
    a class representing a simple character in a role-playing game;
    has a name, strength, agility, and role

    last modified: 29 Aug 2022
=====*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "PlayerChar.h"
using namespace std;

//=====
// implement PlayerChar's constructors

PlayerChar::PlayerChar(string a_name, int a_strength,
                       double an_agility, string a_role) {
    name = a_name;
    strength = a_strength;
    agility = an_agility;
    role = a_role;
}

// WRITE CODE FOR OTHER CONSTRUCTOR(S) HERE!

PlayerChar::PlayerChar()
{
    name = "Fred";
    strength = 250;
    agility = 5.0;
    role = "Ogre";
    hp = strength * agility;
}

PlayerChar::PlayerChar(string a_name, string a_role)
{
    name = a_name;
    role = a_role;
    strength = 250;
    agility = 5.0;
    hp = strength * agility;
}

//=====
// implement PlayerChar's accessors

string PlayerChar::getName() const {
    return name;
}

int PlayerChar::getStrength() const {
    return strength;
}

double PlayerChar::getAgility() const {
    return agility;
}

string PlayerChar::getRole() const {
    return role;
}

// WRITE CODE FOR OTHER ACCESSOR METHOD(S) HERE!

double PlayerChar::getHP() const
{
    return hp;
}

//=====
// implement PlayerChar's mutators

void PlayerChar::setName(string new_name) {
    name = new_name;
}

void PlayerChar::setRole(string new_role) {
    role = new_role;
}

// WRITE CODE FOR OTHER MUTATOR METHOD(S) HERE!

void PlayerChar::setHP(double new_hp)
{
    hp = new_hp;
}

void PlayerChar::resetHP()
{
    hp = strength * agility;
}



//=====
// implement PlayerChar's other methods

// method: printPlayerChar: void -> void
// purpose: expects nothing, has the side-effect of
//     printing to the screen the current data fields of the
//     calling PlayerChar instance, and returns nothing

void PlayerChar::printPlayerChar() const {
    cout << "PlayerChar name:       " << name  << endl
         << "           strength:   " << strength  << endl
         << "           agility:    " << agility  << endl
         << "           role:       " << role << endl;
}

// method: battle: PlayerChar -> void
// purpose: expects a PlayerChar (call by reference!), returns nothing
// side effects: calculates damage to each PlayerChar
//          reduces HP value of each PlayerChar
//          prints to the screen results of the battle
//          and declares a winner!

// WRITE CODE FOR BATTLE METHOD HERE!

void PlayerChar::battle(PlayerChar& opponent)
{
    cout << "Battle Begins" << endl;
    cout << endl;

    double p1_dmg = (hp * randPct());
    double opt_dmg = (opponent.getHP() * randPct());

    setHP(hp - opt_dmg);
    opponent.setHP(opponent.getHP() - p1_dmg);

    if(hp < 0.0)
    {
        setHP(0.0);
    }
    else if (opponent.getHP() < 0.0)
    {
        opponent.setHP(0.0);
    }

    cout << name << " has taken " << opt_dmg << ", " << name << " has " << hp << " hp left." << endl;

    cout << opponent.getName() << " has taken " << p1_dmg << ", " << opponent.getName() << " has " << opponent.getHP() << " hp left." << endl;
    cout << endl;



    if (hp == 0.0)
        {
            cout << name << " has Fainted!" << endl;
            cout << endl;
            cout << opponent.getName() << " is the Winner!" << endl;
        }
        else if (opponent.getHP() == 0.0)
        {
            cout << opponent.getName() << " has Fainted!" <<endl;
            cout << endl;
            cout << name << " is the Winner!" << endl;
        }
}


// randPct: void -> double
// purpose: expects nothing
// returns a value from 0.01 to 1.00 in increments
// of 0.01 -- for use in battles between PlayerChars

double randPct() {
    double return_val;
    return_val = (rand() % 100 + 1) * 0.01;
    return return_val;
}
