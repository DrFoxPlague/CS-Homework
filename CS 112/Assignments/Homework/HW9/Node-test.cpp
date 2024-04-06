/*----
  signature: main: void -> int
  purpose: testing program for the class Node

  compile using:
      g++ Node-test.cpp Node.cpp -o Node-test
  run using:
      ./Node-test

  by: Sharon Tuttle
  last modified: 2022-03-23
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Node.h"
#include "GameCard.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << endl;
    cout << "*** Testing class Node ***" << endl << endl;

    // call each of its constructors, and make
    //    sure each initializes the new object's
    //    data fields correctly

    cout << "constructors' tests: " << endl;

    GameCard tony_card;
    tony_card.set_name("Tony");
    GameCard nancy_card;
    nancy_card.set_name("Nancy");
    GameCard nigel_card;

    Node nigel;
    Node tony(tony_card);
    Node nancy(nancy_card, &nigel);

    // use accessors to test both constructors
    //    and the accessors also

    cout << "   (and also accessors' tests):"
         << endl;

    // these can be "bunched" or spread out...

    cout << ( (nigel.get_data() == nigel_card)
              && (nigel.get_next() == NULL) ) << endl;

    cout << ( (tony.get_data() == tony_card)
              && (tony.get_next() == NULL) ) << endl;

    cout << ( (nancy.get_data() == nancy_card)
              && (nancy.get_next() == &nigel) ) << endl;

    // test the mutators

    cout << "\nmutators' tests: " << endl;

    nigel_card.set_name("Nigel");
    nigel.set_data(nigel_card);

    cout << (nigel.get_data() == nigel_card) << endl;

    nigel.set_next(&tony);

    cout << (nigel.get_next() == &tony) << endl;

    // test Node's "other" methods

    cout << "\ntesting \"other\" methods:" << endl;

    cout << "\ntesting display:" << endl;

    // reset nigel to default

    nigel = Node();

    cout << "\ntest succeeds if see: Node: with data: GameCard(0, 0, , , , common, , 0, no) and next: NULL:"
         << endl;

    nigel.display();

    cout << "test succeeds if see: Node: with data: GameCard(0, 0, Nancy, , , common, , 0, no) and \n"
         << "    next: " << (&nigel) 
         << endl;

    nancy.display();

    return EXIT_SUCCESS;
}