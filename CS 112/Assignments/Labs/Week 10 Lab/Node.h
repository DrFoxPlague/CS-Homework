/*----
  header file for function: Node

  A Node that can be used to help build a singly-linked list

  by: Sharon Tuttle
  and: Dakota Donner & Peter Ramos
  last modified: 2022-04-01 - changing typedef of NodeDataType 
                              from int to Point
                 2022-03-23 - our first version
----*/

#ifndef NODE_H    
#define NODE_H

#include "Point.h"
using namespace std;

//---
// change type below to type desired for Node class'
//     data data field
//     (and modify no-argument constructor and display
//     methods accordingly if needed)

typedef Point NodeDataType; 

class Node
{
    public:
        // constructors

        Node();
        Node(NodeDataType init_data);
        Node(NodeDataType init_data, Node *init_next);

        // accessors

        NodeDataType get_data() const;
        Node *get_next() const;

        // mutators

        void set_data(NodeDataType new_data);
        void set_next(Node *new_next);

        // "other" methods

        /*---
          signature: display: void -> void
          purpose: expects nothing, has the side-effect of
             printing to the screen the data and next fields
             of the calling node, and returns nothing
        ---*/

        void display() const;

    private:
        NodeDataType data;
        Node *next;
};

#endif

