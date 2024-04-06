/*----
  signature: main: void -> int
  purpose: either:
           testing program for the function <name>
           OR
           <describe the program being written --
           what it needs, if anything, and what it does>

  by: Peter & Dakota
  last modified: 2-11-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "SaleItem.h"
using namespace std;

int main()
{
    cout << boolalpha;

    cout << endl
         << "--- Testing SaleItem ---"
         << endl << endl;

    cout << "testing constructors:" << endl;

    SaleItem bitcoin_pepper;
    SaleItem strange_orange("Orange", 99.99, "blue");

    cout << endl
         << "testing accessors:"
         << endl;

    cout << ( (bitcoin_pepper.get_name() == "") 
            && (bitcoin_pepper.get_price() == 0.0)
            && (bitcoin_pepper.get_color() == "") ) << endl;

    cout << ( (strange_orange.get_name() == "Orange") 
            && (strange_orange.get_price() == 99.99)
            && (strange_orange.get_color() == "blue") ) << endl;

    cout << endl
         << "testing mutators:"
         << endl;

    bitcoin_pepper.set_name("Bell Pepper");
    cout << (bitcoin_pepper.get_name() == "Bell Pepper") << endl;

    bitcoin_pepper.set_price(420.69);
    cout << (bitcoin_pepper.get_price() == 420.69) << endl;

    bitcoin_pepper.set_color("gold");
    cout << (bitcoin_pepper.get_color() == "gold") << endl;

    cout << endl
         << "--- Testing display_item ---"
         << endl;
    
    SaleItem a_item;
    a_item.display_item();

    cout << "the following will print to the screen:" << endl;

    cout << "SaleItem:\n"
         << "   name:\n"
         << "   price: 0.0\n"
         << "   color:" << endl; 

    strange_orange.display_item();

    cout << "the following will print to the screen:" << endl;

    cout << "SaleItem:\n"
         << "   name: Orange\n"
         << "   price: 99.99\n"
         << "   color: blue" << endl; 

    return EXIT_SUCCESS;
}