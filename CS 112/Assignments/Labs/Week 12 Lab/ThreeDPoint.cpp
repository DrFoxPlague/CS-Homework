/*----
  implementation file for class: ThreeDPoint

  a ThreeDPoint represents a point in a 3-dimensional
  coordinate space using class Point as parent class
  by: Peter Ramos, Dakota Donner
  last modified: 4/15/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "ThreeDPoint.h"
#include <sstream>
using namespace std;

    ThreeDPoint::ThreeDPoint(): Point()
    {
        z = 0;


    }


    ThreeDPoint::ThreeDPoint(double init_x, double init_y, double init_z): Point(init_x, init_y)
    {
        z = init_z;
    }


    double ThreeDPoint::get_z() const
    {
        return z;
    }

    void ThreeDPoint::set_z(double new_z)
    {
        z = new_z;
    }

    bool ThreeDPoint::operator==(const ThreeDPoint& rhs)
    {
        return ( (Point::operator == (rhs)) && (z == rhs.z) );
    }


    /*
       Signature: display: void -> void
        Purpose: This expects nothing and has the side effect of
                 printing to the screen a gorgeous display of
                 ThreeDPoints coordinates using parent class Point
        test:
            for point
                ThreeDPoint blank_pt;

                blank_pt.display();

                should display

                ThreeDPoint(x: 0, y: 0, z: 0)

            for point
                ThreeDPoint pt_2(5, 5, 5);

                pt_2.display();

                should display

                ThreeDPoint(x: 5, y: 5, z: 5)
    */

    void ThreeDPoint::display()
    {
        cout << "ThreeDPoint(x: " << get_x() << ", y: " << get_y() << ", z: " << z << ")" << endl;
    }


    /*
        Signature: to_string: void -> string
        Purpose: This expects nothing and returns the
                 ThreeDPoint coordinates as a string
            Tests:
                for point

                    ThreeDPoint blank_pt;

                    pt_2.to_string() == ThreeDPoint(x: 0, y: 0, z: 0)

            for point
                    ThreeDPoint pt_2(5, 5, 5);

                    pt_2.to_string() == ThreeDPoint(x: 5, y: 5, z: 5)
    */

    string ThreeDPoint::to_string() const
    {
        ostringstream temp_stream;

        temp_stream << "ThreeDPoint: (x: " << get_x() << ", y: " << get_y() << ", z: " << z << ")";

        return temp_stream.str();
    }
    /*
        Signature: dist_from: ThreeDPoint -> double
        Purpose: This expects a ThreeDPoint Object and compares the
                 distance between the calling object and expected
                 object using very confusing math

            tests:
            for point

                    ThreeDPoint blank_pt;

                    blank_pt.dist_from(blank_pt) == 0

            for point
                    ThreeDPoint pt_2(5, 5, 5);

                    pt_2.dist_from(blank_pt) == 8.66

    */

    double ThreeDPoint::dist_from(ThreeDPoint a_3dpoint) const
    {
        return sqrt( pow( (get_x() - a_3dpoint.get_x()), 2.0) + pow( (get_y() - a_3dpoint.get_y()), 2.0) + pow( (z - a_3dpoint.get_z()), 2.0) );
    }
