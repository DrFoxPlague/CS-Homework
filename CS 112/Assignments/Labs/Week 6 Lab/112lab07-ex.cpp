/*========
  Spring 2022 - CS 112
  Week 6 Lab Exercise - Problem 2 - pointers and dynamic memory allocation

  Do NOT remove any of the comments below -- ADD the specified statement(s)
  after each of them.

  date: 2022-02-25
========*/

/*---
    by: Peter Ramos & Dakota Donner
    last modified: 2022-02-25
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    cout << boolalpha;

    int quantity = 47;

    //*** DECLARE a pointer to an int named quant_ptr

    int *quant_ptr;

    //*** WRITE a statement that causes quant_ptr to point to quantity

    quant_ptr = &quantity;

    //*** WRITE a statement, using ONLY quant_ptr, to print to the
    //***     screen the value that quant_ptr currently points to

    cout << *quant_ptr << endl;

    //*** WRITE a statement, using ONLY quant_ptr, that changes the
    //***     value quant_ptr is currently pointing to, adding 23 to it

    *quant_ptr += 23;

    //*** WRITE a statement, using ONLY quant_ptr, to print to the
    //***     screen the value that quant_ptr currently points to




    cout << "and now, quantity is: " << quantity << endl;
    cout << *quant_ptr << endl;
    cout << endl;

    //*** DECLARE a pointer to a string named city_ptr

    string *city_ptr;

    //*** WRITE a statement that causes city_ptr to point
    //***     to an appropriate dynamically-allocated chunk of memory

    city_ptr = new string;

    //*** WRITE a statement that causes the memory pointed to by
    //***     city_ptr to contain the name of a city of your choice
    //
    // optional: if you want to ask the user to enter this,
    //     you can add additional statements accordingly

    *city_ptr = "Arcata";

    //*** WRITE a statement that prints to the screen the value
    //***     currently pointed to by city_ptr

    cout << *city_ptr << endl;

    //*** DEALLOCATE/free the memory that city_ptr is pointing to,
    //***     and then set city_ptr to point to nothing (following
    //***     CS 112 course coding standards)

    delete city_ptr;


    //*** DECLARE a pointer to an int named salmon_counts

    int *salmon_counts;

    //*** WRITE statements to the screen declaring an int local variable,
    //***     asking the user HOW many salmon counts will be entered, and
    //***     reading in what they enter

    int nums_of_salmon;
    cout << "How many salmon counts ya want?: ";
    cin >> nums_of_salmon;


    //*** WRITE a statement that causes salmon_counts to point to an
    //***     appropriate dynamically-allocated ARRAY of the size entered
    //***     by the user above

    salmon_counts = new int[nums_of_salmon];

    //*** WRITE a loop that asks the user to enter that many salmon counts and reads
    //***     them into the array pointed to by salmon_counts
    //*** (more commonly, we'd now just call this the array salmon_counts,
    //***     or the DYNAMICALLY-ALLOCATED array salmon_counts...)

    int count = 0;

    for (int c = 0; c < nums_of_salmon; c++)
    {
        cout << "\nEnter salmon count " << count++ << ": ";
        cin >> salmon_counts[c];
    }




    //*** WRITE a loop that averages the salmon counts in the array salmon_counts
    //***    (CAREFUL, avoid integer division issues computing the average of
    //***    these int values!)

    int sum = 0;

    for (int c = 0; c < nums_of_salmon; c++)
    {
        sum += salmon_counts[c];
    }




    //*** PRINT a message to the screen including the average computed above
    //***     of the entered salmon counts

    cout << (sum / nums_of_salmon) << endl;

    //*** DEALLOCATE/free the entire dynamically-allocated array salmon_counts,
    //***     and then set salmon_counts to point to nothing (following
    //***     CS 112 course coding standards)

    delete [] salmon_counts;


    return EXIT_SUCCESS;
}

