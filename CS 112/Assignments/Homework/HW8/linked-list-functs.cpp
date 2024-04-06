/*====
  a collection of functions I hope will be useful
      for linked lists created using the Node class

  by: Sharon Tuttle
  and: Peter Ramos, Dakota Donner
  last modified: 2022-03-25 - adding get_size, <other function you chose>
                 2022-03-24 - adding print_list, delete_list, search_for
                 2022-03-23 - starting with insert_at_front
====*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Node.h"
using namespace std;

/*----
  signature: insert_at_front: Node*& NodeDataType -> void
  purpose: expects a start pointer to a linked list
      PASSED BY REFERENCE, and data desired for the new first
      list element, has the side-effects of:
      *   creating a new Node with this data
      *   adding that Node to the FRONT of this
          linked list (CHANGING the argument pointer's
          value),
      and returns nothing
  tests:
      for:
      Node* head = NULL;

      insert_at_front(head, 47);  // change for new NodeDataType

      after this:
      head->get_data() == 47
      head->get_next() == NULL

      if I then do:

      insert_at_front(head, 36);

      after this:
      head->get_data() == 36
      head->get_next()->get_data() == 47

  by: Sharon Tuttle
  last modified: 2022-03-23
----*/

void insert_at_front(Node*& start_ptr, NodeDataType new_element)
{
    Node* new_node_ptr;

    // make the new first node, with the desired list element

    new_node_ptr = new Node(new_element);

    // if the list is currently empty, make this new node
    //    the first node in this list

    if (start_ptr == NULL)
    {
        start_ptr = new_node_ptr;
    }

    // if the list is NOT empty right now, make this new node
    //    the new first element (and LEAD to the "old" first)

    else
    {
        // BUT note the ORDER here -- make the new node lead
        //     to the previous starting node FIRST!

        new_node_ptr->set_next(start_ptr);
        start_ptr = new_node_ptr;
    }
}

/*----
  signature: print_list: Node* -> void
  purpose: expects a pointer to the beginning of a linked
      list, has the side-effect of printing the data in each
      node to the screen, and returns nothing
  tests:
      for:
      Node *my_first = NULL;

      print_list(my_first);

List:
=====
=====

      insert_at_front(my_first, 13);
      insert_at_front(my_first, 5);
      insert_at_front(my_first, 24);
      print_list(my_first);

List:
=====
13
5
24
=====
----*/

void print_list(Node *start_ptr)
{
    cout << "\nList:" << endl
         << "=====" << endl;

    Node *curr_node_ptr = start_ptr;

    while (curr_node_ptr != NULL)
    {
        cout << curr_node_ptr->get_data() << endl;
        curr_node_ptr = curr_node_ptr->get_next();
    }

    cout << "=====" << endl;
}

/*----
  signature: delete_list: Node*& -> int
  purpose: expects a pointer to a linked list
      PASSED BY REFERENCE of dynamically-allocated
      nodes to be freed, has the side-effect
      of freeing all the nodes in that list,
      sets the pointer ARGUMENT to NULL,
      and returns the number of nodes freed
  tests:
      for:
      Node* begin = NULL;

      delete_list(begin) == 0

      and then:
      insert_at_front(begin, 25);
      insert_at_front(begin, 80);
      insert_at_front(begin, 1);
      insert_at_front(begin, 9);

      delete_list(begin) == 4

----*/

int delete_list(Node*& start_ptr)
{
    Node* curr_ptr = start_ptr;
    int num_freed = 0;

    while (curr_ptr != NULL)
    {
       // make start_ptr point to next node

       start_ptr = start_ptr->get_next();

       // now it is safe to delete node curr_ptr is pointing to

       // uncomment for testing purposes
       //cout << "about to delete node w/data: "
       //     << curr_ptr->get_data() << endl;

       delete curr_ptr;
       num_freed++;

       // now make curr_ptr point again to same node as start_ptr

       curr_ptr = start_ptr;
    }

    return num_freed;
}

/*---
  signature: search_for: Node* NodeDataType -> bool
  purpose: expects a pointer to the start of a linked list
     and a value of interest, and returns whether or not
     that value is anywhere in that list

  NOTE: *MAY* NEED TO BE MODIFIED IF NodeDataType is CHANGED!

  tests:
      for:
      Node* stuff = NULL;

      insert_at_front(stuff, 300);
      insert_at_front(stuff, 400);
      insert_at_front(stuff, 250);
      insert_at_front(stuff, 400);
      insert_at_front(stuff, 25);

      search_for(stuff, 12) == false
      search_for(stuff, 25) == true
      search_for(stuff, 400) == true
---*/

bool search_for(Node* start_ptr, NodeDataType desired_val)
{
    Node* curr_ptr = start_ptr;
    bool found = false;  // have not found desired value yet!

    // continue looking until you either run out of list
    //     or find the desired value

    while ((curr_ptr != NULL) && (found == false))
    {
        // NOTE: *may* need to change this bool is NodeDataType is
        //     changed

        if (curr_ptr->get_data() == desired_val)
        {
            found = true;
        }
        else
        {
            // if have not found desired value yet, continue to
            //     next node

            curr_ptr = curr_ptr->get_next();
        }
    }

    // when exit loop, found should be true if desired value was found,
    //     and false if ran out of list without finding it

    return found;
}

// put design recipe steps for your Week 9 Lab Exercise functions here

/*----
  signature: get_size: Node* -> int
  purpose: Expects a pointer of a node, and returns the size of
           the linked list

  tests:
        For:
        Node* stuff = NULL;
        get_size(stuff) == 0;

        insert_at_front(stuff, 10);
        insert_at_front(stuff, 20);
        insert_at_front(stuff, 30);
        insert_at_front(stuff, 40);
        insert_at_front(stuff, 51);

        get_size(stuff) == 5;

  by: Peter Ramos, Dakota Donner
----*/


int get_size(Node* this_ptr)
{
    int count = 0;
    Node* temp_ptr = this_ptr;

    while(temp_ptr != NULL)
    {

        temp_ptr = temp_ptr->get_next();

        count++;
    }
    return count;
}


/*----
  signature: remove_from_front: Node*& -> NodeDataType
  purpose: Expects a node pointer as a PASS BY REFERENCE
           has a side effect of removing just the first
           node and frees the allocated value of the Node
           and returns that deleted value

  tests:
        For:
        Node* stuff = NULL;
        remove_from_front(stuff) == 0;

        insert_at_front(stuff, 10);
        insert_at_front(stuff, 20);
        insert_at_front(stuff, 30);
        insert_at_front(stuff, 40);
        insert_at_front(stuff, 51);

        remove_from_front(stuff) == 51;

  by: Peter Ramos, Dakota Donner
----*/

NodeDataType remove_from_front(Node*& this_ptr)
{
    Node* temp_ptr = this_ptr;

    if(temp_ptr == NULL)
    {
        return 0;
    }
    else
    {
        this_ptr = this_ptr->get_next();
        NodeDataType temp = temp_ptr->get_data();
        delete temp_ptr;


        return temp;

    }


}

/*----
  signature: sum_list: Node* -> NodeDataType

  purpose: Expects a node pointer and returns the sum
           of all NodeDataType instances within the
           linked list.

  tests:
        For:
        Node* stuff = NULL;
        
        sum_list(stuff) == 0

        after:
        
        insert_at_front(stuff, 10);
        insert_at_front(stuff, 20);
        insert_at_front(stuff, 30);

        sum_list(stuff) == 60

  by: Dakota Donner
----*/

NodeDataType sum_list(Node* list_ptr)
{
    if (get_size(list_ptr) == 0)
    {
        return 0;
    }

    else
    {
        NodeDataType sum = 0;
        Node* curr_ptr = list_ptr;

        while(curr_ptr != NULL)
        {
            sum += (curr_ptr->get_data());
            curr_ptr = curr_ptr->get_next();
        }
    }
}




