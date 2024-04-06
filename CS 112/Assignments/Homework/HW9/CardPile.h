/*----
  header file for class: CardPile

  by: Dakota Donner 
  last modified: 4-19-2022
----*/

#ifndef CARDPILE_H    // replace X with the NAME of your function in all-caps
#define CARDPILE_H

#include <string>
#include "GameCard.h"
#include "Node.h"
using namespace std;

class CardPile
{
    public:

        // constructors

        CardPile();
        CardPile(string init_name);

        // accessors

        string get_name() const;
        int get_size() const;
        
        /*
            signature: get_top_card: void -> string

            purpose: expects nothing and returns the GameCard on
                     the very top.
        */

        GameCard get_top_card() const;

        // mutators

        void set_name(string new_name);

        // misc methods

        /*
            signature: display: void -> void

            purpose: expects nothing, has the side effect
                     of printing each GameCard object to
                     the screen, by calling GameCard's 
                     display method, within the pile, and
                     returns nothing.
        */

       void display() const;

       /*
            signature: add_card: GameCard -> void

            purpose: expects a GameCard object has the 
                     side-effect of adding a newly-allocated 
                     Node containing that card object at the 
                     top/beginning of the calling CardPile object, 
                     and returns nothing          
        */

       void add_card(GameCard card_to_add);

       /*
            signature: remove_card: void -> GameCard

            purpose: expects nothing, has a side effect of 
                     removing the top/beginning Node object 
                     from the calling CardPile object, or if
                     the pile is empty, has a side effect of
                     printing an error message to the screen, and 
                     returns the card object in that removed Node or
                     a blank instance if there is nothing to delete.
        */

       GameCard remove_card();

       // copy constructor

       CardPile(const CardPile& a_pile);

       // destructor

       ~CardPile();

       // OAO

       CardPile& operator=(const CardPile& rhs);


    private:

        string name;
        int size;
        Node *cards;
};

#endif