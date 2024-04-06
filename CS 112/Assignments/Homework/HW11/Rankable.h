/*----
  header file for class: Rankable

  by: Peter Ramos, Dakota Donner
  last modified: 4/22/22
----*/

#ifndef RANKABLE_H
#define RANKABLE_H
#include <string>
using namespace std;



class Rankable
{
    public:

    /*
    Signature: compute_rank: void->double
    Purpose: expects nothing and returns the comuted rank of calling
             the Rankable instance
    */


        virtual double compute_rank() = 0;

        // because it turns out you want a virtual destructor that
        // does nothing for your pure virtual class, also!

        virtual ~Rankable(){};

};
// just one pure abstract method...





#endif