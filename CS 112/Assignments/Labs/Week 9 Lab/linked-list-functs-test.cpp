/*----
  signature: main: void -> int
  purpose: testing program for our collection of linked
      list functions

  (Tests assume NodeDataType is int.)

  compile using: (but all on one line!)
      g++ linked-list-functs-test.cpp linked-list-functs.cpp Node.cpp -o linked-list-functs-test
  run using:
      ./linked-list-functs-test

  by: Sharon Tuttle
  and: Dakota Donner, Peter Ramos
  last modified: 2022-03-25 - adding get_size, <other function you chose>
                 2022-03-24 - adding print_list, delete_list, search_for
                 2022-03-23 - starting with insert_at_front
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Node.h"
#include "linked-list-functs.h"
using namespace std;

int main()
{
    cout << boolalpha;

    //---
    // testing insert_at_front

    cout << "\n*** Testing function insert_at_front ***\n";

    // starting with an empty list

    Node* head = NULL;

    insert_at_front(head, 47);  // change for new NodeDataType

    cout << (head->get_data() == 47) << endl;
    cout << (head->get_next() == NULL) << endl;

    insert_at_front(head, 36);

    cout << (head->get_data() == 36) << endl;
    cout << (head->get_next()->get_data() == 47) << endl;

    // need to deallocate dynamic memory used for these two nodes!

    cout << "hope to see 2 nodes deleted: ";
    cout << delete_list(head) << endl;

    //---
    // testing print_list

    cout << "\n*** Testing function print_list ***\n";

    Node *my_first = NULL;

    cout << "should see just List header, and no contents:"
         << endl;

    print_list(my_first);

    cout << "\nshould see list header, then contents\n"
         << "   24, 5, 13:\n";

    insert_at_front(my_first, 13);
    insert_at_front(my_first, 5);
    insert_at_front(my_first, 24);
    print_list(my_first);

    cout << "hope to see 3 nodes deleted: ";
    cout << delete_list(my_first) << endl;

    //---
    // testing delete_list

    cout << "\n*** Testing function delete_list ***\n";

    Node* begin = NULL;

    cout << (delete_list(begin) == 0) << endl;

    // uncomment if you feel like it
    //cout << "hope to delete nodes with 9, then 1, then 80, then 25"
    //     << endl;

    insert_at_front(begin, 25);
    insert_at_front(begin, 80);
    insert_at_front(begin, 1);
    insert_at_front(begin, 9);

    cout << (delete_list(begin) == 4) << endl;

    //---
    // testing search_for

    cout << "\n*** Testing function search_for ***\n";

    Node* stuff = NULL;

    insert_at_front(stuff, 300);
    insert_at_front(stuff, 400);
    insert_at_front(stuff, 250);
    insert_at_front(stuff, 400);
    insert_at_front(stuff, 25);

    cout << (search_for(stuff, 12) == false) << endl;
    cout << (search_for(stuff, 25) == true) << endl;
    cout << (search_for(stuff, 400) == true) << endl;

    cout << "hope to see 5 nodes deleted: ";
    cout << delete_list(stuff) << endl << endl;

    cout << "\n*** Testing function get_size ***\n";

    cout << (get_size(stuff) == 0) << endl;

    insert_at_front(stuff, 10);
    insert_at_front(stuff, 20);
    insert_at_front(stuff, 30);
    insert_at_front(stuff, 40);
    insert_at_front(stuff, 51);

    cout << (get_size(stuff) == 5) << endl;

    cout << "**Deleting list**\n" << endl;
    delete_list(stuff);

    cout << "\n*** Testing function remove_from_front ***\n";

    
    cout << "Removing an empty list should see true if returns 0: " << endl;
    stuff = NULL;
    cout << (remove_from_front(stuff) == 0) << endl;

    insert_at_front(stuff, 10);
    insert_at_front(stuff, 20);
    insert_at_front(stuff, 30);
    insert_at_front(stuff, 40);
    insert_at_front(stuff, 51);

    cout << "Now removing a full list of these 5 items: 51. 40, 30, 20, & 10" << endl;
    print_list(stuff);

    
    cout << (remove_from_front(stuff) == 51) << endl;
    
    cout << "\nAfter deletion should see same list without 51 in front: " << endl;
    print_list(stuff);


    return EXIT_SUCCESS;
}

