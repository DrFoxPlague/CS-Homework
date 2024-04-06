/*----
  signature: main: void -> int

  purpose: interactive input for class SaleItem
           that will result in a file that contains
           a list of SaleItem values.

  by: Dakota Donner
  last modified: 2-28-2022
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h> // added for sleep function
#include <iomanip> // for setw
#include <fstream>
#include "SaleItem.h"
using namespace std;

int main()
{
    cout << boolalpha;

    // local variables

    int obj_cnt;
    string obj_name;
    double obj_price;
    string obj_color;
    string file_name;
    int des_plcs;

    // program

    cout << "Please state how many objects you want: ";
    cin >> obj_cnt;
    SaleItem sale_arr[obj_cnt];

    cout << endl;

    cout << "To add: " << obj_cnt << " items for sale." << endl;

    for (int c = 0; c < obj_cnt; c++)
    {
        cout << "entering product no." + to_string(c+1) << endl;
      
        cout << "Enter the product's name: ";
        cin >> obj_name;
        cout << endl;

        cout << "Enter the product's price: ";
        cin >> obj_price;
        cout << endl;

        cout << "Enter the product's color: ";
        cin >> obj_color;
        cout << endl;

        SaleItem product(obj_name, obj_price, obj_color);
        sale_arr[c] = product;
    }

    cout << "Enter a file name to store the products: ";
    cin >> file_name;
    cout << endl;

    cout << "Enter a desire amount of fractional places: ";
    cin >> des_plcs;
    cout << endl;

    // fake loading purely for fun!

    cout << "constructing";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << endl;

    // actual file construction

    ofstream inventory_file;

    inventory_file.open(file_name);
    
    for (int c = 0; c < obj_cnt; c++)
    {
        inventory_file << setw(des_plcs) << "product " + to_string(c+1) + ": ";
        inventory_file << setw(des_plcs) << sale_arr[c].get_name() << endl;

        inventory_file << setw(des_plcs) << "price: ";
        inventory_file << setw(des_plcs) << sale_arr[c].get_price() << endl;

        inventory_file << setw(des_plcs) << "color: ";
        inventory_file << setw(des_plcs) << sale_arr[c].get_color() << endl;

        inventory_file << setw(des_plcs) << endl;
    }

    cout << "File " << "\"" << file_name << "\" has been created." << endl;

    return EXIT_SUCCESS;
}