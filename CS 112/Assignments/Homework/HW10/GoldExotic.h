/*----
  header file for class: GoldExotic

  a GoldExotic is a very special edition of a GameCard.
  Gold exotic cards are the most powerful cards, and always has 
  a specialty perk that can greatly assist you in the battlefield.

  by: Dakota Donner
  last modified: 4-27-2022
----*/

#ifndef GOLDEXOTIC_H
#define GOLDEXOTIC_H

#include "GameCard.h"
#include <string>

using namespace std;

class GoldExotic: public GameCard
{
    public:

      // constructors

      GoldExotic();
      GoldExotic(int init_attack, int init_defense, string init_name,
             string init_species, string init_subtype, string init_rarity,
             string init_mana_type, int init_mana_cost, string init_mythic_status, 
             string init_exotic_perk);

      // accessors

      string get_exotic_perk() const;

      // mutators

      void set_exotic_perk(string new_exotic_perk);

      // overloaded ==

      bool operator==(const GoldExotic& rhs);

      // misc methods
      
      /*
        signature: display_card: void -> void

        purpose: expects nothing, prints all publicly accessible
                 card data to the screen, and returns nothing.
      */

      void display_card() const;

      /*
        signature: card_to_string: void -> string

        purpose: expects nothing, and returns a string value that
                 displays the calling of a chosen GoldExotic.
      */

      string card_to_string() const;


    private:

      string exotic_perk;
};

#endif