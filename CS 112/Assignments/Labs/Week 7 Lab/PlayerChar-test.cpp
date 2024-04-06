/*----
  signature: main: void -> int
  purpose: testing program for the class PlayerChar

  compile using:
      (on CS50 IDE)
      g++ PlayerChar-test.cpp PlayerChar.cpp -o PlayerChar-test

      (on my Mac...! or if your C++ compiler's default is not C++11 or later?)
      g++ -std=c++11 PlayerChar-test.cpp PlayerChar.cpp -o PlayerChar-test

  run using:
      ./PlayerChar-test

  by: Sharon Tuttle
  last modified: 2022-03-02 (adding tests of new enthusiasm data field
                             and related changes)
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "PlayerChar.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << endl;
    cout << "*** Testing class PlayerChar ***"
         << endl << endl;

    //-----
    // testing constructors and accessors

    cout << "constructors' and accessors' tests:" << endl;

    PlayerChar sven;
    PlayerChar angie("Angie", "Warrior", "Giant");
    PlayerChar ang("Ang", "Wizard", "Elf");

    // FUN FACT: to refer to a public static named constant from
    //    a class, you can precede that constant with the class
    //    name and ::

    cout << ( (sven.get_name() == "")
              && (sven.get_height() >= PlayerChar::MIN_HEIGHT)
              &&  (sven.get_height() <= PlayerChar::MAX_NON_GIANT_HT)
              && (sven.get_level() == 1)
              && (sven.get_speed() == 10)
              && (sven.get_role() == "Barbarian")
              && (sven.get_species() == "Human")
              && (sven.get_enthusiasm() == 5) ) << endl;

    cout << ( (angie.get_name() == "Angie")
              && (angie.get_height() >= PlayerChar::MIN_HEIGHT)
              &&  (angie.get_height() <= PlayerChar::MAX_GIANT_HT)
              && (angie.get_level() == 1)
              && (angie.get_speed() == 10)
              && (angie.get_role() == "Warrior")
              && (angie.get_species() == "Giant")
              && (angie.get_enthusiasm() == 5) ) << endl;

    cout << ( (ang.get_name() == "Ang")
              && (ang.get_height() >= PlayerChar::MIN_HEIGHT)
              &&  (ang.get_height() <= PlayerChar::MAX_NON_GIANT_HT)
              && (ang.get_level() == 1)
              && (ang.get_speed() == 10)
              && (ang.get_role() == "Wizard")
              && (ang.get_species() == "Elf")
              && (ang.get_enthusiasm() == 5) ) << endl;

    //-----
    // test mutators

    cout << "\nmutators' tests: " << endl;

    sven.set_name("Sven");

    cout << (sven.get_name() == "Sven") << endl;

    sven.set_role("Cinnamon Roll");

    cout << (sven.get_role() == "Cinnamon Roll") << endl;

    // set_enthusiasm needs more tests, to make sure it
    //     handles attempts at too-high and too-low enthusiasm levels
    //     correctly

    // cannot set to less than MIN_ENTHUS

    sven.set_enthusiasm(PlayerChar::MIN_ENTHUS - 4);
    cout << (sven.get_enthusiasm() == PlayerChar::MIN_ENTHUS) << endl;

    // cannot set to more than MAX_ENTHUS

    sven.set_enthusiasm(PlayerChar::MAX_ENTHUS + 8);
    cout << (sven.get_enthusiasm() == PlayerChar::MAX_ENTHUS) << endl;

    // testing boundaries

    sven.set_enthusiasm(PlayerChar::MIN_ENTHUS);
    cout << (sven.get_enthusiasm() == PlayerChar::MIN_ENTHUS) << endl;
    sven.set_enthusiasm(PlayerChar::MAX_ENTHUS);
    cout << (sven.get_enthusiasm() == PlayerChar::MAX_ENTHUS) << endl;

    // testing a "good" value in between boundaries

    sven.set_enthusiasm(7);
    cout << (sven.get_enthusiasm() == 7) << endl;

    //-----
    // then, test your "other" methods

    cout << "\ntesting \"other\" methods:" << endl;

    cout << "\ntesting display_player:" << endl;

    cout << "\ntest succeeds if you see empty name, "
         << "\n height between " << PlayerChar::MIN_HEIGHT
         << " and " << PlayerChar::MAX_NON_GIANT_HT
         << "\n    level of 1, speed of 10, role of Barbarian, "
         << "\n    species of Human, and enthusiasm of 5: " << endl;

    PlayerChar a_player;

    a_player.display_player();

    cout << "\ntest succeeds if you see name of Angie, "
         << "\n height between " << PlayerChar::MIN_HEIGHT
         << " and " << PlayerChar::MAX_GIANT_HT
         << "\n    level of 1, speed of 10, role of Warrior, "
         << "\n    species of Giant, and enthusiasm of 5: " << endl;

    angie.display_player();

    cout << "\ntesting player_to_string:" << endl;

    cout << "\n   Should see a string that looks like: \n"
         << "PlayerChar(, <some height>, 1, 10, Barbarian, Human, 5)"
         << endl;
    cout << a_player.player_to_string() << endl;

    cout << "\n   Should see a string that looks like: \n"
         << "PlayerChar(Angie, <some height>, 1, 10, Warrior, Giant, 5)"
         << endl;
    cout << angie.player_to_string() << endl;

    // adding explicit tests of rand_ht

    cout << "\ntesting rand_ht: " << endl;

    PlayerChar junior;

    cout << (junior.get_height() >= PlayerChar::MIN_HEIGHT) << endl;
    cout << (junior.get_height() <= PlayerChar::MAX_NON_GIANT_HT) << endl;

    PlayerChar fofum("FoFum", "Lurker", "Giant");

    cout << (fofum.get_height() >= PlayerChar::MIN_HEIGHT) << endl;
    cout << (fofum.get_height() <= PlayerChar::MAX_GIANT_HT) << endl;

    cout << endl;

    return EXIT_SUCCESS;
}