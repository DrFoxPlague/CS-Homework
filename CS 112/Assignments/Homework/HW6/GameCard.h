/*----
  header file for class: GameCard

  by: Dakota Donner
  last modified: 2-25-2022
----*/

#ifndef GAMECARD_H    // replace X with the NAME of your function in all-caps
#define GAMECARD_H

#include <string>
using namespace std;

class GameCard
{
    public:
    // constructor methods

    GameCard();

    GameCard(int init_attack, int init_defense, string init_name,
             string init_species, string init_subtype, string init_rarity,
             string init_mana_type, int init_mana_cost, string init_mythic_status);

    // accessor methods

    int get_attack() const;
    int get_defense() const;
    string get_name() const;
    string get_species() const;
    string get_subtype() const;
    string get_rarity() const;
    string get_mana_type() const;
    int get_mana_cost() const;
    string get_mythic_status() const;

    // mutator methods

    void set_attack(int new_attack);
    void set_defense(int new_defense);
    void set_name(string new_name);
    void set_species(string new_species);
    void set_subtype(string new_subtype);
    void set_rarity(string new_rarity);
    void set_mana_type(string new_mana_type);
    void set_mana_cost(int new_mana_cost);
    void set_mythic_status(string new_mythic_status);

    // other methods

    /*
        signature: display_card: void -> void

        purpose: expects nothing, prints all publicly accessible
                 card data to the screen, and returns nothing.
    */

   void display_card() const;

   /*
        signature: card_to_string: void -> string

        purpose: expects nothing, and returns a string value that
                 displays the calling of a chosen GameCard.
   */

  string card_to_string() const;


    private:
    // data fields

    int attack;
    int defense;
    string name;
    string species;
    string subtype;
    string rarity;
    string mana_type;
    int mana_cost;
    string is_mythic;
};

#endif