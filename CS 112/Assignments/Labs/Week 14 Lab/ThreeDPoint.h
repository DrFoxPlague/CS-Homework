/*----
  header file for Class: ThreeDPoint

  adapted by: Peter Ramos, Dakota Donner
  last modified: 4/15/22
                 4/22/22 - addinG syntax to make it clear that methods display and 
                           to_string are now going to be overridden instead of redefined
----*/

#ifndef THREEDPOINT_H
#define THREEDPOINT_H
#include <string>
#include "Point.h"
using namespace std;

class ThreeDPoint: public Point
{
    public:
        //constructor
        ThreeDPoint();
        ThreeDPoint(double init_x, double init_y, double init_z);
        
        //accessor
        double get_z() const;
        
        //mutator
        void set_z(double new_z);
        
        //OAO
        bool operator==(const ThreeDPoint& rhs);
    
        //others
        
        /*
            Signature: display: void -> void
            Purpose: This expects nothing and has the side effect of
                     printing to the screen a gorgeous display of 
                     ThreeDPoints coordinates using parent class Point
        */
        
        virtual void display() const;

        /*
            Signature: to_string: void -> string
            Purpose: This expects nothing and returns the
                     ThreeDPoint coordinates as a string 
        */
        
        virtual string to_string() const;
        
        /*
            Signature: dist_from: ThreeDPoint -> double
            Purpose: This expects a ThreeDPoint Object and compares the
                     distance between the calling object and expected 
                     object using very confusing math
        */
        
        double dist_from(ThreeDPoint a_3dpoint) const;
    
    private:
        double z;
    
        
};

#endif