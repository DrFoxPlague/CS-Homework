/*---
    SECOND VERSION: for a separately-compiled C++ program

    COPY this into a .cpp file in a folder within the CS50 IDE

    to compile: in a CS50 terminal that is open to the folder
        CONTAINING this program's .cpp files, type:

        g++ <my-program>.cpp <another-funct>.cpp ...  -o <my-program>

        (assuming this main function is in a file named my_program.cpp)
        (including the .cpp or .o files for *EVERY* function or class INVOLVED
        in this program)

    to run: in that same CS50 terminal that is open to the folder
        CONTAINING this .cpp file, type:

        ./<my-program>

    last modified: 2022-01-20
---*/

/*----
  signature: main: void -> int
  purpose: either:
           testing program for the function <name>
           OR
           <describe the program being written --
           what it needs, if anything, and what it does>

  by: Dakota Donner, Peter Ramos
  last modified: 3/11/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Path.h"
#include "Point.h"
using namespace std;

int main()
{
    cout << boolalpha;

    Path path_1;
    Path path_2("Onwards, to the Room of Bath", 5);

    cout << ( (path_1.get_name() == "UNKNOWN_PATH")
              && (path_1.get_size() == 1)
              && (path_1.get_point(0).get_x() == 0)
              && (path_1.get_point(0).get_y() == 0) ) << endl;

    cout << ( (path_2.get_name() == "Onwards, to the Room of Bath")
              && (path_2.get_size() == 5)
              && (path_2.get_point(0).get_x() == 0)
              && (path_2.get_point(0).get_y() == 0) ) << endl;

    // mutators

    cout << "mutator tests:\n";

    path_1.set_name("Forward, to the Room of Bed");
    cout << (path_1.get_name() == "Forward, to the Room of Bed") << endl;

    Point path2_point;
    path2_point.set_x(6);
    path2_point.set_y(9);

    path_2.set_point(path2_point, 2);
    cout << (path_2.get_point(2).get_x() == 6) << endl;
    cout << (path_2.get_point(2).get_y() == 9) << endl;

    // other

    cout << "Testing display\n";
    path_1.display();
    path_2.display();

    return EXIT_SUCCESS;
}

