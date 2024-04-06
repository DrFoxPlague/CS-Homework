/*----
  signature: main: void -> int

  purpose: program designed to fill a dynamically 
           allocated array of GameCard class objects.

  by: Dakota Donner
  last modified:
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

    // variables

    GameCard *card_hand;
    int size;
    int user_attack;
    int user_defense;
    string user_name;
    string user_species;
    string user_subtype;
    string user_rarity;
    string user_mana_type;
    int user_mana_cost;
    string mythic_status;
    int attack_ctr;

    
    // code

    cout << "Summoner, state your hand size...";
    cin >> size;

    card_hand = new GameCard[size];

    cout << "\nBegin summoning your army!\n";

    for (int c = 0; c < size; c++)
    {
        cout << "Who shall come forth? ";
        cin.ignore();
        getline(cin, user_name);
        cout << endl;

        cout << "What is " << user_name << "'s attack? ";
        cin >> user_attack;
        cout << endl;

        cout << "What is " << user_name << "'s defense? ";
        cin >> user_defense;
        cout << endl;

        cout << "What creature is " << user_name << "? ";
        cin >> user_species;
        cout << endl;

        cout << "What is " << user_name << "? ";
        cin >> user_subtype;
        cout << endl;

        cout << "What is " << user_name << "'s rarity? ";
        cin >> user_rarity;
        cout << endl;

        cout << "What is " << user_name << "'s mana element? ";
        cin >> user_mana_type;
        cout << endl;

        cout << "What is " << user_name << "'s mana cost? ";
        cin >> user_mana_cost;
        cout << endl;

        cout << "And finally...is " << user_name << " a mythic? ";
        cin >> mythic_status;
        cout << endl;

        card_hand[c] = GameCard(user_attack, user_defense, user_name, 
                                user_species, user_subtype, user_rarity,
                                user_mana_type, user_mana_cost, mythic_status);
    }

    cout << "BEHOLD! YOUR ARMY!" << endl;

    for (int c = 0; c < size; c++)
    {
        card_hand[c].display_card();
    }

    cout << "\nAHA! It seems " << (card_hand[0].get_name()) << " has a special ability!" << endl;
    cout << "They can raise every card's attack by a number of your choice!\n" << endl;

    cout << "Choose wisely, Summoner... ";
    cin >> attack_ctr;
    cout << endl;

    for (int c = 0; c < size; c++)
    {
        card_hand[c].set_attack(card_hand[c].get_attack() + 1);
        cout << "COUNTER APPLIED TO " << card_hand[c].get_name() << "!" << endl;
        cout << "New attack value: " << card_hand[c].get_attack() << endl << endl;
    }

    delete [] card_hand;
    card_hand = NULL;

    return EXIT_SUCCESS;
}