/*----
  Implementation of methods for class SaleItem.

  a SaleItem represents an item for sale in a store of some type. 

  by: Peter & Dakota
  last modified: 2-11-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "SaleItem.h"
using namespace std;

// Constructors

SaleItem::SaleItem()
{
    name = "";
    price = 0.0;
    color = "";
}

SaleItem::SaleItem(string init_name, double init_price, string init_color)
{
    name = init_name;
    price = init_price;
    color = init_color;
}

// Accessors

string SaleItem::get_name() const
{
    return name;
}

double SaleItem::get_price() const
{
    return price;
}

string SaleItem::get_color() const
{
    return color;
}

// Mutators

void SaleItem::set_name(string new_name)
{
    name = new_name;
}

void SaleItem::set_price(double new_price)
{
    price = new_price;
}

void SaleItem::set_color(string new_color)
{
    color = new_color;
}

// Display

/*----
    signature: display_item: void -> void

    purpose: expects nothing, has a side-effect of printing the item
             details to the screen, and returns nothing.

    tests: for:
           SaleItem a_item;

           a_item.display_item();

           the following will print to the screen:

           SaleItem:
            name:
            price: 0.0
            color: 


            for:
            SaleItem strange_orange("Orange", 99.99, "blue");

            strange_orange.display_item();

            the following will print to the screen:

            SaleItem:
             name: Orange
             price: 99.99
             color: blue
----*/

void SaleItem::display_item() const
{
    cout << endl;
    cout << "SaleItem\n"
         << "   name: " << name << endl
         << "   price: " << price << endl
         << "   color: " << color << endl;
}