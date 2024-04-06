/*----
  signature: main: void -> int

  purpose: testing program for class CardPack

  by: Dakota Donner
  last modified: 4-1-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GameCard.h"
#include "CardPack.h"
using namespace std;

int main()
{
    cout << boolalpha;

    // constructors & accessors

    cout << "--- TESTING CONSTRUCTORS AND ACCESSORS ---" << endl << endl;

    CardPack test_hand1;
    CardPack test_hand2("Test Hand #2", 8);

    cout << ( (test_hand1.get_name() == "UNSPECIFIED") &&
              (test_hand1.get_size() == 7) &&
              (test_hand1.get_card(0).get_attack() == 0) &&
              (test_hand1.get_card(1).get_attack() == 0) &&
              (test_hand1.get_card(2).get_attack() == 0) &&
              (test_hand1.get_card(3).get_attack() == 0) &&
              (test_hand1.get_card(4).get_attack() == 0) &&
              (test_hand1.get_card(5).get_attack() == 0) &&
              (test_hand1.get_card(6).get_attack() == 0) ) << endl;

    cout << ( (test_hand2.get_name() == "Test Hand #2") &&
              (test_hand2.get_size() == 8) &&
              (test_hand2.get_card(0).get_attack() == 0) &&
              (test_hand2.get_card(1).get_attack() == 0) &&
              (test_hand2.get_card(2).get_attack() == 0) &&
              (test_hand2.get_card(3).get_attack() == 0) &&
              (test_hand2.get_card(4).get_attack() == 0) &&
              (test_hand2.get_card(5).get_attack() == 0) &&
              (test_hand2.get_card(6).get_attack() == 0) &&
              (test_hand2.get_card(7).get_attack() == 0) ) << endl << endl;

    // mutators

    cout << "--- TESTING MUTATORS ---" << endl << endl;

    test_hand1.set_name("testhand1");
    cout << (test_hand1.get_name() == "testhand1") << endl;

    GameCard filler_hero(1, 1, "Filler", "Human", "Civilian", "common", "earth", 0, "no");
    test_hand1.set_card(filler_hero, 4);

    cout << "Should see: 'GameCard(1, 1, Filler, Human, Civilian, common, earth, 0, no)'" << endl;
    cout << (test_hand1.get_card(4).card_to_string()) << endl << endl;

    // copy constructor

    cout << "--- TESTING COPY CONSTRUCTOR ---" << endl << endl;

    cout << "Should see a confirmation message for the copy constructor followed by true." << endl;
    CardPack test2_copy = test_hand2;

    cout << (test_hand2.get_name() == test2_copy.get_name()) << endl << endl;

    // OAO

    cout << "--- TESTING OAO ---" << endl << endl;
    cout << "Should see a confirmation message for the OAO followed by true." << endl;

    CardPack test1_OAO;
    test1_OAO = test_hand1;
    cout << (test1_OAO.get_name() == "testhand1") << endl << endl;

    // misc

    cout << "--- TESTING MISC ---" << endl << endl;

    cout << "SHOULD SEE: " << endl;
    cout << test_hand2.get_name() << endl;
    cout << "Cards in pack: 8" << endl;
    cout << "and 'GameCard(0, 0, , , , common, , 0, no)'" << " printed 8 times." << endl << endl;

    test_hand2.display();

    cout << "SHOULD SEE: " << endl;
    cout << test_hand1.get_name() << endl;
    cout << "Cards in pack: 7" << endl;
    cout << "GameCard(0, 0, , , , common, , 0, no)" << endl;
    cout << "GameCard(0, 0, , , , common, , 0, no)" << endl;
    cout << "GameCard(0, 0, , , , common, , 0, no)" << endl;
    cout << "GameCard(0, 0, , , , common, , 0, no)" << endl;
    cout << "GameCard(1, 1, Filler, Human, Civilian, common, earth, 0, no)" << endl;
    cout << "GameCard(0, 0, , , , common, , 0, no)" << endl;
    cout << "GameCard(0, 0, , , , common, , 0, no)" << endl;

    test_hand1.display();

    return EXIT_SUCCESS;
}