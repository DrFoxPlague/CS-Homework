/*----
  signature: main: void -> int

  purpose: program for creating a linked list of
           Node instances as long as the user
           desires, printing said list, and then
           deleting the list.

  by: Dakota Donner
  last modified: 9-19-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Node.h"

using namespace std;

int main()
{
    cout << boolalpha;

    int user_entry;

    // declaring a pointer to constantly point to the front

    Node *frontPtr;
    frontPtr = NULL;

    // declaring a pointer to work with

    Node *workPtr;

    // declaring conditional for loop

    bool exitLoop = false;

    while(exitLoop == false)
    {
        cout << "Enter a positive number to insert at front..." << endl << "or -1 to quit: ";
        cin >> user_entry;

        if (user_entry == -1)
        {
            exitLoop = true; 
        }

        else if (frontPtr == NULL)
        {
            frontPtr = new Node(user_entry);
            workPtr = frontPtr;
        }

        else
        {
            workPtr->setLink((new Node(user_entry)));
            workPtr = workPtr->getLink();
        }
    }

    workPtr = frontPtr;

    // printing list to the screen

    cout << endl << "PRINTING LIST:" << endl;
    cout << "------" << endl;

    while(workPtr != NULL)
    {
        cout << workPtr->getData() << endl;
        workPtr = workPtr->getLink();
    }

    cout << "------" << endl;

    workPtr = frontPtr;

    // deleting list

    cout << endl << "DELETING LIST..." << endl;

    Node *delPtr;
    int numFreed = 0;

    while(workPtr != NULL)
    {
        delPtr = workPtr;
        workPtr = workPtr->getLink();
        delete delPtr;
        numFreed++;
    }

    cout << "...FREED " << numFreed << " ITEMS!" << endl;

    return EXIT_SUCCESS;
}