/*====
  Spring 2022 - CS 112
  Week 1 Lab Exercise - PART 3

  date: 2022-01-21
====*/

/*----
    *   COPY this into a file named 112lab01-demo.cpp in the CS50 IDE

    *   ALSO copy the contents of the provided letter_match.h into a file named
        letter_match.h within the SAME folder in the CS50 IDE
        *   and REPLACE "PUT YOUR NAME HERE" with your name!

    *   ALSO copy the contents of the provided letter_match.cpp into a file named
        letter_match.cpp within the SAME folder in the CS50 IDE
        *   and REPLACE "PUT YOUR NAME HERE" with your name!

    *   ADD/MODIFY the parts asked for below in your 112lab01-demo.cpp
        
    *   if you want to JUST compile this SINGLE file 112lab01.demo.cpp,
        in a CS50 terminal that is open to the folder
        CONTAINING this .cpp file, type:
   
        g++ -c 112lab01-demo.cpp

        if you want to JUST compile the single file letter_match.cpp,
        in a CS50 terminal that is open to the folder
        CONTAINING letter_match.cpp file, type:
   
        g++ -c letter_match.cpp

        [NOTE: you do not compile .h files individually -- 
        but their CONTENTS end up being compiled when they are #include'd
        in a .cpp file!]
        
        if you want to compile, link, and load the whole program
        that has this file's main function, make sure you have all
        of its .cpp and .h files in the SAME folder in the CS50 IDE,
        and then, in a CS50 terminal that is open to the folder
        CONTAINING this .cpp file, type:
   
        g++ 112lab01-demo.cpp letter_match.cpp -o 112lab01-demo

    *   IF the whole program compiles/links/loads with no errors:
        to run: in that same CS50 terminal that is open to the folder
        CONTAINING this .cpp file, type:

        ./112lab01-demo

    *   make sure that:
        *   you have added all the parts specified below,
        *   you have added your name where specified in letter_match.h
            and letter_match.cpp,
        *   this program indeed runs, and
        *   you like what you see 

    *   When you are done, or before you leave lab, submit all of this
        lab exercise's files (your versions of Part 1's github-name.txt,
        Part 2's cs50-success.txt, and
        Part 3's 112lab01-demo.cpp, letter_match.h, and letter_match.cpp) on
        Canvas.
----*/

/*----
    completed by: Dakota Donner
    last modified: 2022-01-21
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "letter_match.h" 
using namespace std;

int main()
{
    cout << boolalpha;

    // add a cout statement printing YOUR name
    
    cout << "Dakota Donner" << endl;




    cout << endl;
    cout << "*** Testing letter_match: ***" << endl;
    cout << (letter_match("apple", "juice", 3) == false) << endl;
    cout << (letter_match("apple", "juice", 4) == true) << endl;
    cout << endl;

    // add at least one cout statement printing to the screen the 
    //     result of calling letter_match with DIFFERENT word of the day,
    //     a DIFFERENT guessed word, and a DIFFERENT position 
    //     than EITHER test call above
    
    cout << (letter_match("coding", "roping", 1) == true) << endl;


    // OPTIONAL: IF YOU WANT: you can do some more with letter_match here!
    // (you can call it from a loop to see if all of the letters of two
    // words match, you can ask the user to enter a word and compare it to a
    // word of your choice using letter_match, etc.!)

  
    return EXIT_SUCCESS;
}