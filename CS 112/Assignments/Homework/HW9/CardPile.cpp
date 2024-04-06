/*----
  implementation file for class: CardPile

  by: Dakota Donner 
  last modified: 4-19-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "CardPile.h"
#include "Node.h"
#include "GameCard.h"
using namespace std;


        // constructors

        CardPile::CardPile()
        {
            name = "UNSPECIFIED";
            size = 0;
            cards = NULL;
        }

        CardPile::CardPile(string init_name)
        {
            name = init_name;
            size = 0;
            cards = NULL;
        }

        // accessors

        string CardPile::get_name() const
        {
            return name;
        }

        int CardPile::get_size() const
        {
            return size;
        }
        
        /*
            signature: get_top_card: void -> string

            purpose: expects nothing and returns the GameCard on
                     the very top.
        */

        GameCard CardPile::get_top_card() const
        {
            if(cards == NULL)
            {
                return GameCard();
            }

            else
            {
                return cards->get_data();
            }
            
        }

        // mutators

        void CardPile::set_name(string new_name)
        {
            name = new_name;
        }

        // misc methods

        /*
            signature: display: void -> void

            purpose: expects nothing, has the side effect
                     of printing each GameCard object to
                     the screen, by calling GameCard's 
                     display method, within the pile, and
                     returns nothing.
        */

       void CardPile::display() const
       {
           cout << "\nCard Pile: " << endl
                << "------" << endl;

           cout << "SIZE: " << size << endl;
           cout << "NAME: " << name << endl;
           Node *temp_ptr = cards;

           while (temp_ptr != NULL)
           {
               (temp_ptr->get_data()).display_card();
               temp_ptr = temp_ptr->get_next();
           }
    
           cout << "------" << endl;
       }

       /*
            signature: add_card: GameCard -> void

            purpose: expects a GameCard object has the 
                     side-effect of adding a newly-allocated 
                     Node containing that card object at the 
                     top/beginning of the calling CardPile object, 
                     and returns nothing          
        */

       void CardPile::add_card(GameCard card_to_add)
       {
            Node* temp_ptr;

            temp_ptr = new Node(card_to_add);

            temp_ptr->set_next(cards);
            cards = temp_ptr;
            size++;
       }

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

       GameCard CardPile::remove_card()
       {
           Node *temp_ptr = cards;

           if (temp_ptr == NULL)
           {
               cout << "EMPTY LIST!  NOTHING TO DELETE!" << endl;
               return GameCard();
           }

           else
           {
               cards = cards->get_next();
               GameCard del_value = temp_ptr->get_data();
               delete temp_ptr;
               size--;
               return del_value;
           }
       }

       // copy constructor

       CardPile::CardPile(const CardPile& a_pile)
       {
           name = a_pile.name;
           size = a_pile.size;

           Node* temp_ptr = a_pile.cards;
           cards = temp_ptr;
       }

       // destructor

       CardPile::~CardPile()
       {
           Node* temp_ptr = cards;

           while(temp_ptr != NULL)
           {
               cards->get_next();

               delete temp_ptr;

               temp_ptr = cards;
           }
       }

       // OAO

       CardPile& CardPile::operator=(const CardPile& rhs)
       {
           if (this == &rhs)
           {
               return *this;
           }

           delete cards;

           name = rhs.name;
           size = rhs.size;

           Node* temp_ptr = rhs.cards;
           cards = temp_ptr;
       }