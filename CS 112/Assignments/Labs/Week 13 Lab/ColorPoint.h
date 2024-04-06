/*----
  header file for class: ColorPoint

  a ColorPoint represents a point in a 2-dimensional
  coordinate space, and also has a string color
  associated with it

  by: Sharon Tuttle
  last modified: 2022-04-19 - marking display and to_string as virtual
                              methods (BUT that does REALLY depend on
                              this being done in Point.h, which has
                              also been done)
                 2022-04-14 - from Week 12 Lecture 2
                 2022-04-13 - our first version

    adapted by: Peter Ramos & Dakota Donner
----*/

#ifndef COLORPOINT_H
#define COLORPOINT_H

#include <string>
#include "Point.h"
#include "Rankable.h"
using namespace std;

class ColorPoint: public Point, public Rankable
{
    public:
        // constructors - SHOULD define all constructors for the
        //     derived class

        ColorPoint();
        ColorPoint(double init_x, double init_y,
                   string init_color);

        // ColorPoint's version of ==, to also consider if == colors

        bool operator==(const ColorPoint& rhs);

        // accessors - remember, only need new/redefined/overloaded, here!

        string get_color() const;

        // modifiers - remember, only need new/redefined/overloaded, here!

        void set_color(string new_color);

        // other methods - remember, only need new/redefined/overloaded, here!

        // REDEFINED version of display
        //    (to now also display the color) -
        //    note: REPLACES inherited display, has same number and type
        //    of arguments, and same return type

        /*---
            signature: display: void -> void
            purpose: expects nothing, has the side-
                effect of printing to the screen
                a tasteful display of the calling
                ColorPoint object, and returns nothing
        ---*/

        virtual void display() const;

        // OVERLOADED method display,
        //     that expects an argument, a string to
        //     serve as adesired preamble to the display:

        /*---
            signature: display: string -> void
            purpose: expects a desired preamble to be
                printed before the displayed colorpoint,
                prints that and then the colorpoint's data,
                and returns nothing
        ---*/

        void display(string preamble) const;

        // REDEFINED version of to_string
        //    (to now also include the color)
        //    note: REPLACES inherited to_string, has same number and type
        //    of arguments, and same return type

        /*---
            signature: to_string: void -> string
            purpose: expects nothing, and returns
                a string version of the calling
                ColorPoint object
        ---*/

        virtual string to_string() const;

        double compute_rank();

    private:
        string color;
};

#endif

