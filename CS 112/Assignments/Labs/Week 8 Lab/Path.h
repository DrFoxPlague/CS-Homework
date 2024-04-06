/*----
  header file for class: Path

  by: Peter Ramos, Dakota Donner
  last modified:
----*/

#ifndef PATH_H    // replace X with the NAME of your function in all-caps
#define PATH_H
#include <string>
#include "Point.h"

using namespace std;

class Path
{
    public:

        // constructors

        Path();
        Path(string init_name, int init_size);


        // destructor

        ~Path();


        // copy cobstructor

        Path(const Path &a_path);


        // overloaded assignment operator

        Path& operator=(const Path& rhs);


        // accessors

        string get_name() const;
        int get_size() const;
        Point get_point(int position) const;


        // modifiers

        void set_name(string new_name);
        void set_point(Point new_point, int position);


        // other methods

        void display() const;







    private:
    
        string name;
        int size;
        Point *points;

        static const int DEFAULT_SIZE = 1;




}; //semicolon

#endif

