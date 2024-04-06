/*====
  header file for a collection of functions I hope will be useful
      for linked lists created using the Node class

  by: Sharon Tuttle
  and: Dakota Donner, Peter Ramos
  last modified: 2022-03-25 - adding get_size, <other function you chose>
                 2022-03-24 - adding print_list, delete_list, search_for
                 2022-03-23 - starting with insert_at_front
====*/

#ifndef LINKED_LIST_FUNCTS_H
#define LINKED_LIST_FUNCTS_H

#include <string>
#include "Node.h"
using namespace std;

void insert_at_front(Node*& start_ptr, NodeDataType new_element);

void print_list(Node *start_ptr);

int delete_list(Node*& start_ptr);

bool search_for(Node* start_ptr, NodeDataType desired_val);

// put headers for your Week 9 Lab Exercise functions here

int get_size(Node* this_ptr);

NodeDataType remove_from_front(Node*& this_ptr);

// HW8 Functions

NodeDataType sum_list(Node* list_ptr);


#endif

