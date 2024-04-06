/*----
  signature: <funct_name: types expected -> ret_type>
  purpose: <describe what it expects, describe any side-effects,
      describe what it returns>
  tests: <give either boolean expressions involving
      specific example calls, or give example calls
      and describe their side effects>

  by: Peter Ramos, Dakota Donner
  last modified:
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Path.h"
#include "Point.h"
using namespace std;

// constructors

Path::Path()
{
   name = "UNKNOWN_PATH";
   size = DEFAULT_SIZE;
   points = new Point[size];

}

Path::Path(string init_name, int init_size)
{

    name = init_name;
    size = init_size;
    points = new Point[size];
}

// copy constructor

Path::Path(const Path &a_path)
{
    cout << "Called copy constructor" << endl;

    name = a_path.name;
    size = a_path.size;

    points = new Point[size];

    for (int i = 0; i < size; i++)
    {
        points[i] = a_path.points[i];
    }
}


// destructor

Path::~Path()
{
    cout << "Called destructor" << endl;

    delete [] points;
}


// overloaded assignment operator

Path& Path::operator=(const Path& rhs)
{
    cout << "Called overloading assignment operator" << endl;

    if(this == &rhs)
    {
        return *this;
    }

    delete [] points;

     name = rhs.name;
     size = rhs.size;

     points = new Point[size];

     for (int i = 0; i < size; i++)
     {
         points[i] = rhs.points[i];
     }

     return *this;
}

//Accessor
string Path::get_name() const
{
    return name;
}

int Path::get_size() const
{
    return size;
}

Point Path::get_point(int position) const
{
    return points[position];
}


// Mutator
void Path::set_name(string new_name)
{
    name = new_name;
}

void Path::set_point(Point new_point, int position)
{
    points[position] = new_point;
}


void Path::display() const
{
    cout << "\nPath name: " << name << "\nSize: " << size << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Point " << to_string(i+1) << ": ";
        points[i].display();
    }

}



