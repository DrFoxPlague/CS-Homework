/*----
  purpose: implementation file for class CardPack
           
           CardPack is designed to build dynamically
           allocated arrays, or "packs", of GameCard
           instances.

  by: Dakota Donner
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GameCard.h"
#include "CardPack.h"
using namespace std;

// constructors

CardPack::CardPack()
{
    name = "UNSPECIFIED";
    size = DEFAULT_SIZE;
    cards = new GameCard[size];
}

CardPack::CardPack(string init_name, int init_size)
{
    name = init_name;
    size = init_size;
    cards = new GameCard[size];
}

// copy constructor

CardPack::CardPack(const CardPack& a_pack)
{
    cout << "COPY CONSTRUCTOR CALLED -- " << endl;

    name = a_pack.name;
    size = a_pack.size;

    cards = new GameCard[size];

    for (int c = 0; c < size; c++)
    {
        cards[c] = a_pack.cards[c];
    }
}

// destructor

CardPack::~CardPack()
{
    cout << "DELETING CardPack '" << name << "' -- " << endl;
    cout << "...defined at address: " << this << endl << endl; 

    delete [] cards;
}

// overloaded assignment operator

CardPack& CardPack::operator=(const CardPack& rhs)
{
    cout << "OVERLOADED ASSIGNMENT OPERATOR CALLED -- " << endl;

    if (this == &rhs)
    {
        return *this;
    }

    delete [] cards;

    name = rhs.name;
    size = rhs.size;

    cards = new GameCard[size];

    for (int c = 0; c < size; c++)
    {
        cards[c] = rhs.cards[c];
    }

    return *this;
}

// accessors

string CardPack::get_name() const
{
    return name;
}

int CardPack::get_size() const
{
    return size;
}

GameCard CardPack::get_card(int pos) const
{
    if (pos > size)
    {
        cout << "OUT OF BOUNDS!" << endl;
    }

    else
    {
        return cards[pos];
    }
}

// mutators

void CardPack::set_name(string new_name)
{
    name = new_name;
}

void CardPack::set_card(GameCard des_card, int des_pos)
{
    if (des_pos > size)
    {
        cout << "OUT OF BOUNDS!" << endl;
    }

    else
    {
        cards[des_pos] = des_card;
    }
}

// misc methods

/*----
    signature: display: void -> void

    purpose: expects nothing, prints to the screen the 
             data of each card in the pack, in the order
             they appear, and returns nothing.

    tests: 
           for:
           CardPack test_hand2;

           test_hand1.display();

           we will see the following printed:

           GameCard(0, 0, , , , common, , 0, no)
           GameCard(0, 0, , , , common, , 0, no)
           GameCard(0, 0, , , , common, , 0, no)
           GameCard(0, 0, , , , common, , 0, no)
           GameCard(0, 0, , , , common, , 0, no)
           GameCard(0, 0, , , , common, , 0, no)
           GameCard(0, 0, , , , common, , 0, no)


           for:
           CardPack test_hand1;

           test_hand2.display("Fire Kingdom Hand", 8);

           we will see the following printed:


----*/

void CardPack::display() const
{
    cout << endl;
    cout << name << ": " << endl;
    cout << "Cards in pack: " << size << endl;

    for (int c = 0; c < size; c++)
    {
        cout << (cards[c].card_to_string()) << endl;
    }
    cout << endl;
}