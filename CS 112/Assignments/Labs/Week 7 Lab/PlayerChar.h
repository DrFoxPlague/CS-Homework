/*----
  header file for class: PlayerChar

  a PlayerChar represents a player in a game (for example, in a
      role-playing game)

  by: Sharon Tuttle
  last modified: 2022-03-02 (adding enthusiasm data field, and related
                             changes; also removing "excess" comments
                             from writing-ones-first-class)
----*/

#ifndef PLAYERCHAR_H
#define PLAYERCHAR_H

#include <string>
#include <random>
using namespace std;

class PlayerChar
{
    public:
        // constructor methods

        PlayerChar();

        PlayerChar(string init_name, string init_role, string init_species);

        // accessor methods

        string get_name() const;
        double get_height() const;
        int get_level() const;
        int get_speed() const;
        string get_role() const;
        string get_species() const;
        int get_enthusiasm() const;

        // mutator methods

        void set_name(string new_name);
        void set_role(string new_role);
        void set_enthusiasm(int new_enthus_level);

        // "other" methods

        /*---
            signature: display_player: void -> void
            purpose: expects nothing, prints to the screen the
                characteristics of the calling PlayerChar,
                and returns nothing
        ---*/

        void display_player() const;

        /*---
            signature: player_to_string: void -> string
            purpose: expects nothing, returns a string depiction
                of the calling PlayerChar
        ---*/

        string player_to_string() const;

        // it is also fine to declare *public* named constants you want
        //    users of the class to also be able to use

        // FUN FACT: each object has its "own" copies of data fields and
        //     methods, UNLESS they are declared as static --
        //     static means there is always EXACTLY one of that data field or
        //     method, no matter how many (or even if no) objects of that
        //     class currently exist
        // (but if double, C++11 compilers require
        //     constexpr instead of const...!?)

        // public members to help with setting player heights --
        //     no reason for multiple copies of named constants...!
        // (gulp -- only made public so could use them for testing?!)

        static constexpr double MIN_HEIGHT = 2.0;
        static constexpr double MAX_NON_GIANT_HT = 6.0;
        static constexpr double MAX_GIANT_HT = 12.0;

        // public members for controlling enthusiasm levels --
        //     still don't need multiple copies of these;

        static const int MIN_ENTHUS = 1;
        static const int MAX_ENTHUS = 10;

    private:
        // data fields

        string name;
        double height;
        int    level;
        int    speed;
        string role;
        string species;
        int    enthusiasm;

        /*---
            signature: rand_ht: double -> double
            purpose: expects a desired maximum height for a player,
                and attempts to use the C++11 <random>
                library to return a height in the range
                [MIN_HEIGHT, desired maximum height]
        ---*/

        double rand_ht(double desired_max);

        // only need 1 copy of these, also; and trying making these
        //     private;

        static const int INIT_LEVEL = 1;
        static const int INIT_SPEED = 10;
        static const int INIT_ENTHUS = 5;
};

#endif