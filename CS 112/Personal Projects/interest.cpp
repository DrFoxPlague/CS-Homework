#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    cout << boolalpha;

    // variables

    int init_amount;
    int accum_amt;
    int days;

    // code

    cout << "Enter the amount: ";
    cin >> init_amount;
    cout << endl;

    cout << "Enter the days: ";
    cin >> days;
    cout << endl;

    accum_amt = init_amount;

    for (int c = 0; c < days; c++)
    {
        if (accum_amt > 10000)
        {
            accum_amt += (accum_amt * 0.02);
        }

        else
        {
            accum_amt += (accum_amt * 0.016);
        }
        
    }

    cout << "Total accumulation after " + to_string(days) + " days: ";
    cout << accum_amt;
    cout << endl;

    cout << "Money made: ";
    cout << (accum_amt - init_amount) << endl;

    cout << "Divided unto two people: ";
    cout << ((accum_amt - init_amount) / 2) << endl;

    return EXIT_SUCCESS;
}