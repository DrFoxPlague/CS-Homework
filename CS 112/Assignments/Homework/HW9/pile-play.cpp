/*----
  signature: main: void -> int

  purpose: testing file for class CardPile

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

int main()
{
    cout << boolalpha;

    // constructing some cards...

    GameCard card1;
    card1.set_name("Card 1");
    GameCard card2;
    card2.set_name("Card 2");
    GameCard card3;
    card3.set_name("Card 3");

    // testing CardPile

    cout << "TESTING CLASS CardPile\n" << endl << endl;

    CardPile pile1;
    CardPile pile2("Pile 2");

    pile2.add_card(card1);
    pile2.add_card(card2);
    pile2.add_card(card3);

    cout << "SHOULD SEE...\n" 
         << "'Card Pile:' followed by the size, name,\n"
         << "and three callings of GameCard's display method, \n"
         << "which should show three GameCard instances with names: \n"
         << "'Card 3', 'Card 2', and 'Card 1', each without any added stats.\n" << endl;

    pile2.display();

    cout << "\ntesting accessors for pile1: \n";
    cout << "get_name: " << (pile1.get_name() == "UNSPECIFIED") << endl;
    cout << "get_size: " << (pile1.get_size() == 0) << endl;
    cout << "get_top_card: " << ((pile1.get_top_card().card_to_string()) == "GameCard(0, 0, , , , common, , 0, no)") << endl;
    
    cout << "\ntesting accessors for pile2: \n";
    cout << "get_name: " << (pile2.get_name() == "Pile 2") << endl;
    cout << "get_size: " << (pile2.get_size() == 3) << endl;
    cout << "get_top_card: " << ((pile2.get_top_card().card_to_string()) == "GameCard(0, 0, Card 3, , , common, , 0, no)") << endl;
    
    cout << "\nAFTER calling set_name for pile1 (...should see true):" << endl;
    pile1.set_name("Pile 1");
    cout << (pile1.get_name() == "Pile 1") << endl;

    cout << "\ntesting remove_card on pile2: " << endl;
    pile2.remove_card();

    cout << "SHOULD SEE...\n"
         << "the same display method but with\n"
         << "Card 3 removed and the size as 2.\n" << endl;

    pile2.display();

    cout << "\ntesting copy constructor: \n" << endl;
    CardPile pile3 = pile2;

    GameCard card4;
    card4.set_name("Card 4");
    pile3.add_card(card4);

    cout << "CHECKING SIZE ON pile2 AND NEW COPIED INSTANCE, pile3" << endl;
    cout << "pile2: " << (pile2.get_size() == 2) << endl;
    cout << "pile3: " << (pile3.get_size() == 3) << endl;

    cout << "\nSHOULD SEE...\n"
         << "pile2 displayed as last time and\n"
         << "pile3 with an extra card and a size of 3\n" << endl;

    pile2.display();
    pile3.display();

    cout << "\ntesting the OAO: \n" << endl;
    pile1 = pile3;

    GameCard card5;
    card5.set_name("THE OAO WORKS!!! :D");

    pile1.add_card(card5);

    cout << "CHECKING SIZE ON pile1 AND pile3 AFTER USING OAO" << endl;
    cout << "pile3: " << (pile3.get_size() == 3) << endl;
    cout << "pile1: " << (pile1.get_size() == 4) << endl;

    cout << "\nSHOULD SEE...\n"
         << "pile3 displayed as last time and\n"
         << "pile1 with an extra card and a size of 4\n" << endl;

    pile1.display();
    pile3.display();
    return EXIT_SUCCESS;
}