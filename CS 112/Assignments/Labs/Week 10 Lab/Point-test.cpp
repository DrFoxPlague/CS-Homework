/*----
  signature: main: void -> int
  purpose: testing program for the class Point

  compile using:
      g++ Point-test.cpp Point.cpp -o Point-test
  run using:
      ./Point-test

  by: Sharon Tuttle
  and: Dakota Donner & Peter Ramos
  last modified: 2022-04-01 - adding an overloaded == operator
                 2022-03-31 - renaming some methods (based on our
                              later in-class examples) and improving
                              display and to_string methods
                 2022-02-17 - our first version
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << endl;
    cout << "*** Testing class Point ***" << endl;

    // call each of its constructors, and make
    //    sure each initializes the new object's
    //    data fields correctly

    cout << "constructors' tests: " << endl;

    Point point1;
    Point point2(3, 4.7);

    // use accessors to test both constructors
    //    and the accessors also

    cout << "   (and also accessors' tests):"
         << endl;

    // these can be "bunched" or spread out...

    cout << ( (point1.get_x() == 0)
              && (point1.get_y() == 0) ) << endl;

    cout << ( (point2.get_x() == 3)
              && (point2.get_y() == 4.7) ) << endl;

    // test the mutators

    cout << "\nmutators' tests: " << endl;

    point1.set_x(12);

    cout << (point1.get_x() == 12) << endl;

    point1.set_y(18.14);

    cout << (point1.get_y() == 18.14) << endl;

    point1.set_pos(114, 85);

    cout << ((point1.get_x() == 114)
             && (point1.get_y() == 85)) << endl;

    // test Point's "other" methods

    cout << "\ntesting \"other\" methods:" << endl;

    cout << "\ntesting display:" << endl;

    Point a_point;

    cout << "\ntest succeeds if see: Point(x: 0, y: 0)"
         << endl;

    a_point.display();

    cout << "\ntest succeeds if see: Point(x: 3, y: 4.7)"
         << endl;

    point2.display();

    cout << "\ntesting to_string:" << endl;

    cout << (a_point.to_string() ==
               "Point(x: 0, y: 0)") << endl;
    cout << (point2.to_string() ==
               "Point(x: 3, y: 4.7)" ) << endl;

    cout << "\ntesting dist_from:" << endl;

    Point point3(0, 4.7);
    Point point4(3, 0);

    cout << (a_point.dist_from(point2) ==
            sqrt( (3*3) + (4.7 * 4.7) ) ) << endl;
    cout << (point2.dist_from(point3) == 3.0) << endl;
    cout << (point2.dist_from(point4) == 4.7) << endl;
    cout << (point2.dist_from(point2) == 0) << endl;

    cout << "\ntesting == operator:" << endl;

    Point point5(5, 6);
    Point point6(6, 7);
    
    cout << "comparing point with itself: " << endl;
    cout << (point5 == point5) << endl;
    
    cout << "comparing two unequal points to a bool value of false: " << endl;
    cout << ((point5 == point6) == false) << endl;

    return EXIT_SUCCESS;
}

