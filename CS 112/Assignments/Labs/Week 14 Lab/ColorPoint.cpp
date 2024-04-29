/*----
  implementation file for class: ColorPoint

  a ColorPoint represents a point in a 2-dimensional
  coordinate space, and also has a string color
  associated with it

  by: Sharon Tuttle
  last modified: 2022-04-14 - modifications made Week 12 Lecture 2
                              (such as overloaded 1-argument display method)
                 2022-04-13 - our first version
  adapted by: Peter Ramos, Dakota Donner
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "Point.h"
#include "Rankable.h"
#include "ColorPoint.h"
using namespace std;

/*----
    constructors
----*/

// it is GOOD STYLE ti call the BASE class' constructor in the
//     derived class' constructors -- NOTE the syntax for this
//     used below!

// default color will be red

ColorPoint::ColorPoint(): Point()
{
    color = "red";
}

ColorPoint::ColorPoint(double init_x, double init_y,
    string init_color): Point(init_x, init_y)
{
    color = init_color;
}

/*----
    ColorPoint's version of ==
----*/

bool ColorPoint::operator==(const ColorPoint& rhs)
{
    return ( (Point::operator==(rhs))
             && (color == rhs.color) );

    /*return ( (abs(get_x() - rhs.get_x()) < 0.0000001)
             && (abs(get_y() - rhs.get_y()) < 0.0000001)
             && (color == rhs.color) );
    */
}

/*----
    new and/or redefined and/or overloaded accessors
----*/

string ColorPoint::get_color() const
{
    return color;
}

/*----
    new and/or redefined and/or overloaded modifiers
----*/

void ColorPoint::set_color(string new_color)
{
    color = new_color;
}

/*----
    other methods (new, redefined, overloaded as desired)
----*/

// REDEFINED version of display
//    (to now also display the color)
//    note: REPLACES inherited display, has same number and type
//    of arguments, and same return type

/*---
   signature: display: void -> void
   purpose: expects nothing, has the side-effect of printing
       to the screen the x and y coordinates and color
       of the calling ColorPoint, and returns nothing

    tests:
        for:
        ColorPoint c_point1;

        c_point1.display();
        ...should print to the screen:

ColorPoint(x: 0, y: 0, color: red)

        for:
        ColorPoint c_point2(3, 4.7, "blue");

        c_point2.display();
        ...should print to the screen:

ColorPoint(x: 3, y: 4.7, color: blue)

        for:
        ColorPoint c_point3(5, 7, "");

        c_point3.display();

        ...should print to the screen:
Point(x: 5, y: 7)

---*/

void ColorPoint::display() const
{
    if (color == "")
    {
        cout << "Color";
        Point::display();
    }
    else
    {
        cout << "ColorPoint(x: " << get_x()
             << ", y: " << get_y()
             << ", color: " << color << ")" << endl;
    }
}

/*---
    signature: display: string -> void
    purpose: expects a desired preamble to be
        printed before the displayed colorpoint,
        prints that and then the colorpoint's data,
        and returns nothing

    tests:
        for:
        ColorPoint c_point1;

        c_point1.display("Baa: ");
        ...should print to the screen:

Baa: ColorPoint(x: 0, y: 0, color: red)

        for:
        ColorPoint c_point2(3, 4.7, "blue");

        c_point2.display("Honk");
        ...should print to the screen:

HonkColorPoint(x: 3, y: 4.7, color: blue)

---*/

void ColorPoint::display(string preamble) const
{
    cout << preamble;
    display();
}


// REDEFINED version of to_string
//    (to now also include the color)
//    note: REPLACES inherited to_string, has same number and type
//    of arguments, and same return type

/*---
    signature: to_string: void -> string
    purpose: expects nothing, and returns
        a string version of the calling
        ColorPoint object

    tests:
        for:
        ColorPoint c_point1;

        c_point1.to_string() ==
            "ColorPoint(x: 0, y: 0, color: red)"

        for:
        ColorPoint c_point2(3, 4.7, "blue");

        c_point2.point_to_string() ==
            "ColorPoint(x: 3, y: 4.7, color: blue)"
---*/

string ColorPoint::to_string() const
{
    ostringstream cpoint_sstream;

    cpoint_sstream << "ColorPoint(x: " << get_x()
         << ", y: " << get_y()
         << ", color: " << color << ")";

    return cpoint_sstream.str();
}



double ColorPoint::compute_rank()
{
    double rank;
    rank = ( (get_x()*12) - (get_y()/6) );
    return rank;
}

