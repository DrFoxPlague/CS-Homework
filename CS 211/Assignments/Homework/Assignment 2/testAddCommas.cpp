#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "addCommas.h"
using namespace std;

int main()
{
    cout << boolalpha;

    addCommas(111);
    addCommas(222111);
    addCommas(333222111);
    addCommas(444333222111);
    addCommas(555444333222111);
    addCommas(666555444333222111);
    addCommas(7666555444333222111);
    addCommas(666555444333222111);

    cout << (333222111 / 1000000) << "," << ((333222111 % 1000000) / 1000) << endl;

    return EXIT_SUCCESS;
}