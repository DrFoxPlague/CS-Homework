
/*----
  signature: main: void -> int
  purpose:
           testing program for the class ThreeDPoint
       
  by: Peter Ramos, Dakota Donner
  last modified: 4/15/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "ThreeDPoint.h" 
using namespace std;

int main()
{
    cout << boolalpha;

    ThreeDPoint blank_pt;
    ThreeDPoint pt_2(5, 5, 5);
    
    cout << "\nCalling accessors\n";
    cout << "...should see 3 true values, if successful\n" << endl;
    
    cout << (pt_2.get_x() == 5) << endl;
    cout << (pt_2.get_y() == 5) << endl;
    cout << (pt_2.get_z() == 5) << endl;
    
    
    cout << "\nCalling display & to_string\n";
    
    cout << "should display: " << endl;
    cout << "ThreeDPoint(x: 0, y: 0, z: 0)" << endl;
    cout << "ThreeDPoint(x: 5, y: 5, z: 5)" << endl << endl;
    
    blank_pt.display();
    pt_2.display();
    
    cout << "for blank_pt:" << endl;
                
    cout << (blank_pt.to_string() == "ThreeDPoint: (x: 0, y: 0, z: 0)") << endl;
            
    cout << "for pt_2" << endl;
                
    cout << (pt_2.to_string() == "ThreeDPoint: (x: 5, y: 5, z: 5)") << endl;
    
    
    
    cout << "\nCalling dist_from\n";
                
    cout << (blank_pt.dist_from(blank_pt) == 0) << endl;
    cout << (pt_2.dist_from(blank_pt) == 8.66025) << endl;
    
    
    cout << "\nCalling mutators\n";
    cout << "...should see 1 true value, if successfully changed\n" << endl;
    blank_pt.set_x(1);
    blank_pt.set_y(2);
    blank_pt.set_z(3);
    
    cout << ( (blank_pt.get_x() == 1) && (blank_pt.get_y() == 2) && (blank_pt.get_z() == 3) ) << endl;
    
    
    

    return EXIT_SUCCESS;
}