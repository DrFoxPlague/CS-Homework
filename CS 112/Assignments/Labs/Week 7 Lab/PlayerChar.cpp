/*----
  Implementation of methods for class PlayerChar

  a PlayerChar represents a player in a game (for example, in a
      role-playing game)

  by: Sharon Tuttle
  last modified: 2022-03-02 (adding enthusiasm data field, and related
                             changes; also removing "excess" comments
                             from writing-ones-first-class)
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include "PlayerChar.h"
using namespace std;

/*---
   constructors
---*/

// CS 112 style: each constructor should give initial
//    values to all data fields

PlayerChar::PlayerChar()
{
    name = "";

    height = rand_ht(MAX_NON_GIANT_HT);

    level = INIT_LEVEL;
    speed = INIT_SPEED;
    role = "Barbarian";
    species = "Human";
    enthusiasm = INIT_ENTHUS;
}

PlayerChar::PlayerChar(string init_name, string init_role, string init_species)
{
    name = init_name;

    if (init_species == "Giant")
    {
        height = rand_ht(MAX_GIANT_HT);
    }
    else
    {
        height = rand_ht(MAX_NON_GIANT_HT);
    }

    level = INIT_LEVEL;
    speed = INIT_SPEED;
    role = init_role;
    species = init_species;
    enthusiasm = INIT_ENTHUS;
}

/*---
    accessors
---*/

string PlayerChar::get_name() const
{
    return name;
}

double PlayerChar::get_height() const
{
    return height;
}

int PlayerChar::get_level() const
{
    return level;
}

int PlayerChar::get_speed() const
{
    return speed;
}

string PlayerChar::get_role() const
{
    return role;
}

string PlayerChar::get_species() const
{
    return species;
}

int PlayerChar::get_enthusiasm() const
{
    return enthusiasm;
}

/*---
    mutators
---*/

void PlayerChar::set_name(string new_name)
{
    name = new_name;
}

void PlayerChar::set_role(string new_role)
{
    role = new_role;
}

/*---
    Note: user can set/change a PlayerChar's enthusiasm -- BUT if they
        try to set it OUTSIDE the range of [MIN_ENTHUS, MAX_ENTHUS],
        the calling's object's enthusiasm will be set to be *in* the
        range (to the nearest "endpoint") instead
---*/

void PlayerChar::set_enthusiasm(int new_enthus_level)
{
    if (new_enthus_level < MIN_ENTHUS)
    {
        enthusiasm = MIN_ENTHUS;
    }
    else if (new_enthus_level > MAX_ENTHUS)
    {
        enthusiasm = MAX_ENTHUS;
    }
    else
    {
        // if get here, know suggested new enthusiasm IS in
        //     "legal" range

       enthusiasm = new_enthus_level;
    }
}

/*---
    "other" methods
---*/

/*---
  signature: display_player: void -> void
  purpose: expects nothing, prints to the screen the
      characteristics of the calling PlayerChar,
      and returns nothing
  tests:
      for:
      PlayerChar a_player;

      a_player.display_player();

      ...has the side-effect of printing to the screen:
PlayerChar:
   name:
   height:     <a value in [MIN_HEIGHT, MAX_NON_GIANT_HT]>
   level:      1
   speed:      10
   role:       Barbarian
   species:    Human
   enthusiasm: 5

      for:
      PlayerChar angie("Angie", "Warrior", "Giant");

      angie.display_player();

      ...has the side-effect of printing to the screen:
PlayerChar:
   name:       Angie
   height:     <a value in [MIN_HEIGHT, MAX_GIANT_HT]>
   level:      1
   speed:      10
   role:       Warrior
   species:    Giant
   enthusiasm: 5

---*/

void PlayerChar::display_player() const
{
    cout << endl;
    cout << "PlayerChar\n"
         << "   name:       " << name << endl
         << "   height:     " << height << endl
         << "   level:      " << level << endl
         << "   speed:      " << speed << endl
         << "   role:       " << role << endl
         << "   species:    " << species << endl
         << "   enthusiasm: " << enthusiasm << endl;
}

/*---
    signature: player_to_string: void -> string
    purpose: expects nothing, returns a string depiction
        of the calling PlayerChar
    tests:
      for:
      PlayerChar a_player;

      a_player.player_to_string() ==
           "PlayerChar(, <a height in [MIN_HEIGHT, MAX_NON_GIANT_HT]>, 1, 10, Barbarian, Human, 5)"

      for:
      PlayerChar angie("Angie", "Warrior", "Giant");

      angie.player_to_string() ==
          "PlayerChar(Angie, <a height in [MIN_HEIGHT, MAX_GIANT_HT]>, 1, 10, Warrior, Giant, 5)"
---*/

string PlayerChar::player_to_string() const
{
    // to_string is a string library function with
    //    several overloaded versions, one that expects
    //    an int and another that expects a double,
    //    and each returns a string version of that number

    return "PlayerChar(" + name + ", "
           + to_string(height) + ", "
           + to_string(level) + ", "
           + to_string(speed) + ", "
           + role + ", " + species + ", "
           + to_string(enthusiasm) + ")";
}

/*---
    signature: rand_ht: double -> double
    purpose: expects a desired maximum height for a player,
        and attempts to use the C++11 <random>
        library to return a height in the range
        [MIN_HEIGHT, desired maximum height]
    tests:
        for:
        PlayerChar junior;

        junior.get_height() >= MIN_HEIGHT
        junior.get_height() <= MAX_NON_GIANT_HT

        for:
        PlayerChar fofum("FoFum", "Lurker", "Giant");

        fofum.get_height() >= MIN_HEIGHT
        fofum.get_height() <= MAX_GIANT_HT
---*/

double PlayerChar::rand_ht(double desired_max)
{
    random_device height_rand_dev;

    mt19937 mt( height_rand_dev() );
    uniform_real_distribution<double> dist(MIN_HEIGHT, desired_max);

    return dist(mt);
}