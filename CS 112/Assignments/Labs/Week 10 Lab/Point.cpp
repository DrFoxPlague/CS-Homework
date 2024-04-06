/*----
  implementation file for class: Point

  a Point represents a point in a 2-dimensional
  coordinate space

  by: Sharon Tuttle
  and: Dakota Donner & Peter Ramos
  last modified: 2022-04-01 - adding an overloaded == operator
                 2022-03-31 - renaming some methods (based on our
                              later in-class examples) and improving
                              display and to_string methods
                 2022-02-15 - our first version
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>    // to use ostringstream for "nicer" display, to_string
#include "Point.h"
using namespace std;

// constructors

// for the 0-argument constructor, you get (0, 0)

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double init_x, double init_y)
{
    x = init_x;
    y = init_y;
}

// overloaded == operator

bool Point::operator==(const Point& rhs)
{
    return ((abs(x - rhs.get_x()) < 0.00001) && (abs(y - rhs.get_y())) < 0.00001);
}

// accessors

double Point::get_x() const
{
    return x;
}

double Point::get_y() const
{
    return y;
}

// modifiers

void Point::set_x(double new_x)
{
    x = new_x;
}

void Point::set_y(double new_y)
{
    y = new_y;
}

void Point::set_pos(double new_x, double new_y)
{
    x = new_x;
    y = new_y;
}

// "other" methods

/*---
    signature: display: void -> void
    purpose: expects nothing, has the side-
        effect of printing to the screen
        a tasteful display of the calling
        point, and returns nothing
    tests:
        for:
        Point point1;

        point1.display();
        ...should print to the screen:
Point(x: 0, y: 0)

        for:
        Point point2(3, 4.7);

        point2.display();
        ...should print to the screen:

Point(x: 3, y: 4.7)

---*/

void Point::display() const
{
    cout << "Point(x: " << x << ", y: " << y << ")"
         << endl;
}

/*---
    signature: to_string: void -> string
    purpose: expects nothing, and returns a string version of
        the calling point
    tests:
        for:
        Point point1;

        point1.to_string() == "Point(x: 0, y: 0)"

        for:
        Point point2(3, 4.7);

        point2.to_string() == "Point(x: 3, y: 4.7)"
---*/

string Point::to_string() const
{
    // declare an output stringstream for a "prettier" string
    //     depiction of our double x and y values than the
    //     to_string function happens to provide

    ostringstream point_sstream;

    point_sstream << "Point(x: " << x << ", y: " << y << ")";

    // remember: ostringstream's str method returns the string
    //    we've just "built" using point_sstream

    return point_sstream.str();
}

/*---
    signature: dist_from: Point -> double
    purpose: expects a Point, and returns
        the distance from the calling Point
        to the given Point
    tests:
        Point point1;
        Point point2(3, 4.7);
        Point point3(0, 4.7);
        Point point4(3, 0);

        point1.dist_from(point2) ==
            sqrt( (3*3) + (4.7 * 4.7) )
        point2.dist_from(point3) == 3.0
        point2.dist_from(point4) == 4.7
        point2.dist_from(point2) == 0

---*/

double Point::dist_from(Point a_point) const
{
    return sqrt( pow( (x - a_point.x), 2.0)
                 + pow( (get_y() - a_point.get_y()),
                        2.0)
               );
}

