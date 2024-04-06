/*----
  header file for class: CardPack

  by: Dakota Donner
  last modified: 3/30/2022
----*/

#ifndef CARDPACK_H
#define CARDPACK_H

#include <string>
#include "GameCard.h"
using namespace std;

class CardPack
{
    public:
    // constructors

    CardPack();
    CardPack(string init_name, int init_size);

    // copy constructor

    CardPack(const CardPack&a_pack);

    // destructor

    ~CardPack();

    // overloaded assignment operator

    CardPack& operator=(const CardPack& rhs);

    // accessors

    string get_name() const;
    int get_size() const;
    GameCard get_card(int pos) const;

    // mutators

    void set_name(string new_name);
    void set_card(GameCard des_card, int des_pos);

    // misc methods

    /*----
        signature: display: void -> void

        purpose: expects nothing, prints to the screen the 
                 data of each card in the pack, in the order
                 they appear, and returns nothing.
    ----*/

    void display() const;

    private:

    string name;
    int size;
    GameCard *cards;

    // default size of a pack, if unspecified
    static const int DEFAULT_SIZE = 7;
};

#endif