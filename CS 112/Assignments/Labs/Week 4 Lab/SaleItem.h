/*----
  header file for class: SaleItem

  by: Peter & Dakota
  last modified: 2-11-2022
----*/

#ifndef SALEITEM_H
#define SALEITEM_H
#include <string>
using namespace std;

class SaleItem
{
    public:

        SaleItem();
        SaleItem(string init_name, double init_price, string init_color);

        // accessor methods

        string get_name() const;
        double get_price() const;
        string get_color() const;

        // mutator methods

        void set_name(string new_name);
        void set_price(double new_price);
        void set_color(string new_color);

        // display method

        /*----
            signature: display_item: void -> void

            purpose: expects nothing, has the side-effect of printing the item
                     details to the screen, and returns nothing
        ----*/

        void display_item() const;
        

    private:

        string name;
        double price;
        string color;

};

#endif