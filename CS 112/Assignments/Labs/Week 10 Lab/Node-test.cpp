/*----
  signature: main: void -> int
  purpose: testing program for the class Node

  compile using:
      g++ Node-test.cpp Node.cpp -o Node-test
  run using:
      ./Node-test

  by: Sharon Tuttle
  and: Dakota Donner & Peter Ramos
  last modified: 2022-04-01 - changing typedef of NodeDataType 
                              from int to Point
                 2022-03-23 - our first version
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Node.h"
#include "Point.h"
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

    Point tony_pnt(7, 3);
    Point nancy_pnt(1, 2);
    Point empty;
    
    Node nigel;
    Node tony(tony_pnt);
    Node nancy(nancy_pnt, &nigel);

    // use accessors to test both constructors
    //    and the accessors also

    cout << "   (and also accessors' tests):"
         << endl;

    // these can be "bunched" or spread out...

    cout << ( (nigel.get_data() == empty)
              && (nigel.get_next() == NULL) ) << endl;

    cout << ( (tony.get_data() == tony_pnt)
              && (tony.get_next() == NULL) ) << endl;

    cout << ( (nancy.get_data() == nancy_pnt)
              && (nancy.get_next() == &nigel) ) << endl;

    // test the mutators

    cout << "\nmutators' tests: " << endl;

    Point new_nigel_pt(1, 2);
    nigel.set_data(new_nigel_pt);

    cout << (nigel.get_data() == new_nigel_pt) << endl;

    nigel.set_next(&tony);

    cout << (nigel.get_next() == &tony) << endl;

    // test Node's "other" methods

    cout << "\ntesting \"other\" methods:" << endl;

    cout << "\ntesting display:" << endl;

    // reset nigel to default

    nigel = Node();

    cout << "\ntest succeeds if see: Node: with data: Point(x: 0, y: 0) and next: NULL:"
         << endl;

    nigel.display();

    cout << "test succeeds if see: Node: with data: Point(x: 1, y: 2) and \n"
         << "    next: " << (&nigel) 
         << endl;

    nancy.display();

    return EXIT_SUCCESS;
}

