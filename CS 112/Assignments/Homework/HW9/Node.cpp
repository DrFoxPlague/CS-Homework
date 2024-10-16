/*----
  implementation file for function: Node

  A Node that can be used to help build a singly-linked list

  by: Sharon Tuttle
  last modified: 2022-04-18 by Dakota Donner
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Node.h"
#include "GameCard.h"
using namespace std;

/*---
  constructors
---*/

//---
// be sure to update no-argument constructor if you change 
//     NodeDataType (to set data data field to an appropriate
//     default value for that type)

Node::Node()
{
    data = GameCard();
    next = NULL;
}

Node::Node(NodeDataType init_data)
{
    data = init_data;
    next = NULL;
}

Node::Node(NodeDataType init_data, Node *init_next)
{
    data = init_data;
    next = init_next;
}

/*---
  accessors
---*/

NodeDataType Node::get_data() const
{
    return data;
}

Node *Node::get_next() const
{
    return next;
}

/*---
  mutators
---*/

void Node::set_data(NodeDataType new_data)
{
    data = new_data;
}

void Node::set_next(Node *new_next)
{
    next = new_next;
}

/*---
  "other" methods
---*/

/*---
  signature: display: void -> void
  purpose: expects nothing, has the side-effect of
     printing to the screen the data and next fields
     of the calling node, and returns nothing
  tests:
     for:
     Node nigel;

     then:
     nigel.display();
     ...should have the side-effect of printing to the screen:
Node:
  data: GameCard(0, 0, , , , common, , 0, no)
  next: NULL

     for:
     GameCard nancy_card;
     Node nancy(nancy_card, &nigel);

     then:
     nancy.display();
     ...should have the side-effect of printing to the screen:
Node:
  data: GameCard(0, 0, Nancy, , , common, , 0, no)
  next: <the address of nigel will appear here>

---*/

void Node::display() const
{
    cout << endl;
    cout << "Node:" << endl;

    //---
    // but MAY have to change how you print data data field
    //     if you change NodeDataType (if its new type does not
    //     work directly with >> for printing, for example)
    
    cout << "  data: " << data.card_to_string() << endl;
    cout << "  next: ";
    
    if (next == NULL)
        cout << "NULL";
    else
        cout << next;
        
    cout << endl << endl;
}