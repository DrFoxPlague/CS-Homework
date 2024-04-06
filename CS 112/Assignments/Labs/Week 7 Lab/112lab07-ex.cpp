/*========
  Spring 2022 - CS 112
  Week 7 Lab Exercise

  Do NOT remove any of the comments below -- ADD the specified statement(s)
  after each of them.

  compile using:
      g++ 112lab07-ex.cpp PlayerChar.cpp rand_factor.cpp -o 112lab07-ex
  run using:
      ./112lab07-ex

  date: 2022-03-04
========*/

/*---
    by: Peter Ramos & Dakota Donner
    last modified: 2022-03-04
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "PlayerChar.h"
using namespace std;

int main()
{
    cout << boolalpha;

    //*** Make COPIES of:
    //***
    //*** *   Week 7 Lecture 2's PlayerChar.h and PlayerChar.cpp
    //*** *   the provided files rand_factor.cpp and rand_factor.h
    //***
    //*** ...in your folder for today's lab

    //*** DECLARE a pointer to a PlayerChar named player_ptr

    PlayerChar *player_ptr;

    //*** WRITE a statement that causes player_ptr to point to an
    //***     appropriate dynamically-allocated chunk of memory
    //***     such that PlayerChar's 3-argument constructor will be
    //***     used

    player_ptr = new PlayerChar;

    //*** WRITE a statement to CHANGE the role of the PlayerChar
    //***     object pointed to by player_ptr to be "Bard"

    player_ptr->set_role("Bard");

    //*** WRITE a statement to print to the screen the current
    //***     data fields of the PlayerChar object pointed to by
    //***     player_ptr (you can choose either one of the two reasonable
    //***     PlayerChar methods for this)


    player_ptr->display_player();



    //*** DECLARE a pointer to a PlayerChar named party

    PlayerChar *party;

    //*** WRITE statements to the screen declaring an int local variable,
    //***     asking the user HOW many players will be in today's party,
    //***     reading in what they enter

    int party_size;
    cout << "Enter the desired party size: ";
    cin >> party_size;
    cout << endl;


    //*** WRITE a statement that causes party to point to an
    //***     appropriate dynamically-allocated ARRAY of the size entered
    //***     by the user above

    party = new PlayerChar[party_size];

    //*** WRITE a loop that asks the user to enter names, roles, and
    //***     species for that many players, and creates PlayerChar
    //***     objects and puts them into party accordingly
    //*** OPTIONAL addition: also ask them for the PlayerChar's
    //***     enthusiasm level, and MODIFY that group element's
    //***     enthusiasm accordingly

    string des_name;
    string des_role;
    string des_species;

    for (int c = 0; c < party_size; c++)
    {
        cout << "Enter a desired name for PlayerChar " + to_string(c + 1) + ": ";
        cin >> des_name;
        cout << endl;

        cout << "Enter a desired role for PlayerChar " + to_string(c + 1) + ": ";
        cin >> des_role;
        cout << endl;

        cout << "Enter a desired species for PlayerChar " + to_string(c + 1) + ": ";
        cin >> des_species;
        cout << endl;

        PlayerChar player(des_name, des_role, des_species);
        party[c] = player;
    }


    //*** WRITE a loop that averages the heights of PlayerChars in the array party
    //***     (declare and initialize needed local variable(s) before this loop)

    double height_sum = 0.0;
    double height_av;

    for (int c = 0; c < party_size; c++)
    {
        height_sum += party[c].get_height();
    }

    height_av = (height_sum / party_size);

    //*** PRINT a message to the screen including the average height
    //***     computed above of the PlayerChar objects in
    //***     the array party

    cout << "Average height of team is: ";
    cout << height_av << endl;

    //*** WRITE a loop displaying the contents of party (using your choice
    //***    of the two reasonable methods for this)

    for (int c = 0; c < party_size; c++)
    {
        party[c].display_player();
    }

    //*** vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    //*** GO TO THE BOTTOM and DEALLOCATE player_ptr and party where asked!
    //*** MAKE SURE the above WORKS ***before you go on***.
    //*** ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    //*** IF you still have time: (and submit as far as you get on this
    //***                          by the end of lab)
    //*** OVER IN PlayerChar.h and PlayerChar.cpp:
    //*** *   ADD comments saying "modified by: " with YOUR names
    //*** *   ADD a public method to class PlayerChar, called challenge.
    //***     challenge expects another PlayerChar, PASSED BY REFERENCE,
    //***     because the calling PlayerChar is challenging this PlayerChar to...
    //***     ...what? You can choose. It can just be to a challenge, or it can
    //***         be a debate, or etc.
    //***
    //***     challenge should do AT LEAST the following:
    //***     *   print to the screen a message declaring that
    //***         calling player <name> is CHALLENGING player <other player name>
    //***         to (whatever you chose)
    //***     *   call the provided rand_factor function for each
    //***         player and multiply their level by its result
    //***     *   determine whose player's multiplied result is higher.
    //***         Increase that player's level by 1!
    //***     *   print to the screen the name of the winner/victor/etc
    //***     *   (you can do more -- change the enthusiasm, also,
    //***         for example -- but do at least the above)

    // [this part is completed in PlayerChar.h and PlayerChar.cpp, not here]

    //*** Now write a loop such that the player pointed to by player_ptr
    //***     challenges each player in party by calling this new challenge method!






    //*** Write code to display the resulting PlayerChar that player_ptr points to
    //*** (using either reasonable method)



    //*** Write a loop to display the resulting contents of party
    //** (using either reasonable method)






    //*** DEALLOCATE/free the memory that player_ptr is pointing to,
    //***     and then set player_ptr to point to nothing (following
    //***     CS 112 course coding standards)

    delete player_ptr;

    //*** DEALLOCATE/free the entire dynamically-allocated array party
    //***     and then set party to point to nothing (following
    //***     CS 112 course coding standards)

    delete [] party;

    return EXIT_SUCCESS;
}