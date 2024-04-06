#include <cstdlib> 
#include <iostream> 
#include <string> 
#include <cmath> 
using namespace std; 

/*
    === WORKSPACE ===
*/


// CS 112 standards and data types:
/*

Data Types:

    1. strings:
        
        * C++ has two string-like data types:
        
        char* - old-style C-string
        "hello" <-- a simple expression of type char
        
        string - New style and PREFERRED STANDARD for CS 112 and has cool methods
        
            example of method: obj_expression.method_name(arg, arg...)
        
    
    2. char:
    
        * single character in single qoutes
        
        'm'
        '\n' <-- type char of newline character.
        
        
    3. numbers
    
        * C++ has several numeric types, but CS 112 focus on these two:
        
        int - basic integer type
        
            2
            23
            -3
            
        double - modern-basic floating-point type
        
            double-precision floating point
            
            CS 112 standard: use double instead of float for floating-point values.
            
            2.4
            45.7
            -23.9
            
            
    4. booleans
    
        * C++'s boolean type is bool:
    
            true
            false

    
{ }'s must go on their own line! (CS 112 STANDARD, NOT REQUIRED BY C++)

! - can be used as "not".

    For example:

    bool some_bool = true

    !some_bool == false <--- this would be true

*/

// IF function
/*

if (bool_expr)
{
    statement;
    ...
}

else if (bool_expr)
{
    statement;
    ...
}

else
{
    statement;
    ...
}

*/

// WHILE function
/*

while (bool_expr)
{
    statement;
    ...
    concluding_statement;
}
after_statement;

*/

// FOR function
/*

for (init_part; condition; update_part)
{
    desired_rep_statement;
    ...
}

    CLASS STANDARD:
        * It is okay to use a single character variable in "for" loops.

*/

// GETLINE function
/*

If you want to read the WHOLE line of a cin input,
including blanks and all, use GETLINE.

getline(istream, string)

    example: string thing;
             getline(cin, thing);

*/

// C++ FILE/IO
/*

Provides classes ifstream and ofstream

ifstream - Type for an input file stream
ofstream - ... output file stream

open method connects that stream to a file

    * for an ifstream
    it connects it to that file
    ready to read the first thing from that file

    * for an ofstream,
    it creates that file if it does not exist
    or it connects it to that file if it does
    exist AND DELETES ALL OF THAT FILE'S CURRENT CONTENTS


* for an ifstream
you can now use it with >> or getline or etc...
JUST LIKE you've used cin for interactive input.

* for an ofstream,
you can now use it with a <<
JUST LIKE you've used cout for interactive output.


--- CS CLASS STYLE STANDARD ---
call the close method to properly close
your ifstream and ofstream objects when you are done
with them.
---            ~~~          ---

EXAMPLE:

#include <fstream>

const string FILE_NAME = "this-is-a-file.txt";
ifstream my_file_stream;
my_file_stream.open(FILE_NAME);

string write_stuff;
my_file_stream >> write_stuff;
my_file_stream.close(); <------- uses no arguments


string stuff;
cin >> stuff;

ofstream writing_stream;
writing_stream.open(FILE_NAME);
writing_stream << stuff << endl;

*/

// C++ ARRAYS
/*

* Arrays are a set of values all of the same type,
  of a size specified in advance.
  stored in contiguous memory.

elmnt_type arr_name[num_elmnts];
elmnt_type arr_name[num_elmnts] = {expr1, expr2, expr3, ... exprN};

you can grab OR CHANGE an element of an array using:

arr_name[index_of_des_elmnt] <--- must be between 0 and the size minus 1.

*/

// WRITING YOUR OWN CLASSES
/*

* An ABSTRACT DATA TYPE (ADT) is data, PLUS the operations for ACTING on that data,
  set up in such a way that the user does not have to care HOW it happens to be set up,
  and set up such that users can trust that using the provided operations on instances of that ADT
  will not "break" that ADT instance.

* In C++, you can implement a class to define an ADT.

class - a new data type, really;
object - an instance of a class

a class defines the methods that can be called for instances/objects 
of that class.

------------

Some common/classic categories of METHODS

* contructor methods/constructors 

   - to create a new instance, or object, of that class.
     CONSTRUCTOR NAMES ARE THE NAMES OF THE CLASS

* Accessor methods/accessors/getters

    - To access acceptable public data about that object

* mutator methods/modifier methods/mutators/modifiers/setters

    - to make allowable changes to data about that object.

* and others!

------------

=== HOW TO IMPLEMENT A CLASS ===

--- MUST START WITH UPPERCASE AND USE CamelCase ---

--- DATA FIELDS MUST BE IN private: ---

--- ALWAYS DECLARE A NO-ARGUMENT CONSTRUCTOR ---

--- WHEN POSSIBLE, INCLUDE AT LEAST ONE CONSTRUCTOR THAT LETS THE USER
    SPECIFICY INITIAL DATA FIELD VALUES THEY MIGHT FIND CONVENIENT TO SPECIFY ---

ex: PlayerName, TreeSize, GunAmmo, etc...

* Write a class definition, including the class name,
  its data fields, and the signatures of its methods

~~~!!HEADER!!~~~

class NewClassName 
{
    public:
        // give constructor method headers <- must be same as NewClassName (has no return type)
        // give accessor method headers
        // give mutator method headers
        // give any other method public method headers

    private: 
        dataFieldType data_field_name;
        dataFieldType data_field_name;
        ...

        // give helper method headers

        static const data_type CONST_NAME = data; <--- making a static constant if you want to make
                                                       default data if a user fails to specify.

}; <--- USE SEMICOLON

EXAMPLE:

class PlayerChar
{
    public:
        PlayerChar();

        PlayerChar(string init_name, string init_role, string init_species); <-- Don't make the arguments the same name as your private data fields.

        string get_name() const;
        int get_attack() const;
        int get_defense() const;
        string get_species() const;
        string get_role() const;
        int get_level() const;

        // mutator methods' headers

        void set_name(string new_name);
        void set_species(string new_species);
        void set_role(string new_role);

        // "other" methods

        void display_players() const;



    private:
        string name;
        int attack;
        int defense;
        string species;
        string role;
        int level;
};

~~~!!HEADER!!~~~


*/

// PARAMETERS
/*

input, output, and input/output

* The vast majority if parameters are input...
  Just USED by the function

* Output parameters are intended to JUST be set by the function.

* Input/output parameters are intended to be used AND set set/changed
  by the function.

==============

-- PASS-BY-VALUES -- 

Scalar - (or scalar value) - a single value, not an array.

*   BUT -- arrays are passed-by-value
    by copying the ADDRESS of where the argument array
    STARTS into the array parameter,

    SO changing an element in a parameter array
    DOES change the argument array's element

*   SO -- changing an array parameter
    CAN change the corresponding array argument;

  If you don't want this:

  We can turn:
  void print_nums(double num_arr[], int size) to:
  void print_nums(const double num_arr[], int size)
                    ^------------------------------------ add const

==============

-- PASS-BY-REFERENCE --

* You use this when you don't want to copy the value of the argument
  expression into your parameter...

  but, instead, you want the parameter to hold the LOCATION of the argument
  (a REFERENCE to the argument)...and you don't feel like using pointers


In C++, to indicate that a parameter should be passed by reference instead of by value,

you put a & between the parameter type and the parameter name in the
function header.

==============

-- POINTERS --

* A pointer is the memory address of a variable.

* for a non-pointer value, in a non-pointer variable,

  int quant = 13;

  ...the variable represents the value of that variable.

  quant == 13


* a pointer value is not typically a value we want directly...
  Instead, it is a value REFERENCING a value of interest; 

    * In C++, a pointer's type includes the type of the value
      it is pointing to.


* declaration SYNTAX:

  put an asterisk between the type name and the variable name to
  indicate that variable's type is POINTER to that type.

  EX: int *quant_ptr;


*** CLASS STYLE STANDARD ***

If a C++ pointer is currently NOT pointed anywhere,
give it the named constant value NULL:

int *quant_ptr;
quant_ptr = NULL;

*** CLASS STYLE STANDARD ***


* You'll frequently be checking if a pointer is anywhere, before
  using it.

  if (my_ptr != NULL)
  {
      ... follow my_ptr ...
  }

  while (my_ptr != NULL)
  {
      ... follow my_ptr ...
      ... change my_ptr to something ...
  }

* if you want the address of a variable, let's say,
  You can use & as a prefix operator to get that.

  int *quant_ptr;
  quant_ptr = NULL;

  int local_num = 3;

  // set quant_ptr to the address of local_num.
  quant_ptr = &local_num;

  
* SO...
  ...how can you get the value POINTED TO by a pointer?
  (that is, the value at the pointer address)

  Use * as a prefix operator for the pointer expression.

  cout << *quant_ptr;


* An expression like *quant_ptr is considered to be an
  lvalue.

  like a variable name or an array reference.

  you can directly modify what is there.

  After:
  *quant_ptr = 45;

  local_num will now equal 45.


================

--- DYNAMIC MEMORY ---

 (the memory for parameters and local variables is
   a different "chunk" of memory than this memory
   you can allocate and deallocate while a program
   is running)

   *   this memory you can allocate and deallocate while
       the program is running is sometimes called
       dynamic memory

*   operator new, when followed by a type,
    dynamically allocates an instance of that type
    (in dynamic memory/the heap/the freestore)
    and returns its address

    a pointer variable can be set to the result
    of the new operator!

    double *num_ptr;        // num_ptr's type is pointer-to-double

             _______
    num_ptr  |  ?  |
             |     |
             -------

    num_ptr = new double;   // allocate a chunk of memory able to
                            //    hold a double, and return the address
                            //    of that chunk, which is then assigned
			    //    to num_ptr
			    // (so, num_ptr now points to that newly-
			    //    allocated chunk of memory)

             _______            _________
    num_ptr  |  --------------->|   ?   |
             |     |            ---------
             -------

    *num_ptr = 13.13;       // set the value at that newly-allocated
                            //    chunk of memory to 13.13;
	                    // go to the address in num_ptr and
			    //    put 13.13 in that memory;
			    // follow num_ptr, and put 13.13 where
			    //    it is pointing

             _______            _________
    num_ptr  |  --------------->| 13.13 |
             |     |            ---------
             -------

    cout << (*num_ptr) << endl;   // so this will print 13.13,
                                  //     the value at the address in
				  //     num_ptr (the value num_ptr
                                  //     is pointing to

===========================
***** IMPORTANT *****!!!!!
===========================
    ...when you are done with that dynamic memory,
    you are expected to FREE it with delete:

    delete <the address of that memory>;

    delete num_ptr;    // FREE the dynamic memory pointed to by num_ptr
    num_ptr = NULL;    // (and make num_ptr now point to nothing)

===========================

--- DYNAMIC ARRAYS ---

*   you can dynamically allocate an array!

    you can say:

    new array_type[array_size]

    ...to get a dynamically-allocated array of array_size elements
    of type array_type, and this then returns the address where that
    newly-allocated array starts;

    new string[47]   // dynamic array of 47 strings

    ...and this returns the address of the 1st element in that
    array of 47 strings.

    FOR a dynamic array, you typically declare such a variable
    as a pointer to its first element:

    double *widget_costs;

    ...then set that to the address of a newly-allocated array:

    widget_costs = new double[12];

    // and then you can use that array -- accessing its
    //     elements -- as we have been doing with static
    //     arrays:

    for (int i=0; i < 12; i++)
    {
        widget_costs[i] = 10;
	cout << widget_costs[i] << endl;
    }

    //=========IMPORTANT!!!==========
   // BUT you have to TELL C++ an *array* is being
   //    freed -- by putting [] between the delete
   //    and the array pointer...!

   delete [] widget_costs;
   widget_costs = NULL;

   (otherwise, it will only free the FIRST array element,
   and the rest will be a memory leak...!)

================

--- POINTERS TO OBJECTS --- 

C++ lets you say "call the method of the object I am pointing to"
with the -> operator

for PlayerChar:

PlayChar *player_ptr;

(*player_ptr).get_height()

can be

player_ptr->get_height()

*/

// DYNAMIC MEMORY W/ THE "BIG 3"
/*

!-You can get an assignment operator and a so-called
  copy constructor (caled by the operating system in certain situations
  like for pass-by-value parameters) generated automatically when you create a class,
  if you don't do it yourself.-!

destructor - free any dynamic memory

copy constructor - makes a sufficiently-deep copy of an object when needed (like for
                   pass-by-value arguments)

overloaded assignment operator - make a sufficiently-deep copy of an object for
                                 assignment statement use.

=== DESTRUCTOR ===
* its name is a tilde (~) followed by the class name.
* like a constructor, it has no return type nor arguments(so it 
  cannot be overloaded, either)

Its job is to free any dynamically allocated memory, and any other
needed cleanup.

ex:
~ClassName()


== COPY CONSTRUCTOR ==
* syntax:

  ClassName(const ClassName& a_desired_class)

the goal is to make a non-destructive of its argument.


=== OVERLOADED ASSIGNMENT STATEMENT ===


header:

ClassName& operator=(const ClassName& rhs)

1. Check for self-assignment
   (and return *this if so).

2. Deallocate any memory the calling object is
   using internally.

3. Allocate some memory to hold what's needed from rhs.

4. Copy the values from the rhs into the caling instance.

5. And return the new version of the calling instance.

*/

// VECTOR CLASS
/*

* part of C++ Standard Template Library (STL)

to include:
#include <vector>

* as a templated class, you provide the type of
  element in a vector object a little differently:

  one basic way (using vector's no-argument constructor):

  vector<desired_type> var_name;

  vector<int> counts;
  vector<double> weights;
  vector<string> names;


it has a variety of methods, which include the number
of elements in the array.

cout << names.size() << endl; // would be 0 cuz empty


you can add a new element to the END of a
vector using its push_back method.

names.push_back("John"); // position 0
names.push_back("Arthur"); // poition 1


When you have elements, THEN you can
reference to the using [].

cout << names[1] << endl;


* The vector one-argument constructor can let you specify
  an initial size (and now you don't have to push_back
  that many times initially)

  vector<string> names(5);


* the two-argument constructor lets you 
  initialize the vector's element to
  a value

  vector<string> names(5, "Bill");

pop_back - expects no arguments
           returns nothing
           removes the last element from the vector, reducing the vector size by 1
           destroys the removed element.

*/

// STRING STREAM
/*

(Like file i/o)

* output:
  ostringstream output;

  You can "write" to this using <<

  output << "(" << (3+5) << ")";

  
  then, you can get the resulting built string
  from that output string stream using its str method.

  cout << output.str() << endl;


* input:
  istringstream input;

  You can read mulrivalue lines from a file and
  then want to read the individual values from
  that line:

  string stuff = "13 baff 256 yopa";

  input.str(stuff);

  string weird_word;
  int number;

  input >> number >> weird_word;

  cout << number << weird_word << endl;


  BEFORE you put in another string, call the clear method.

  input.clear();
  input.str("420 REE 69 BOI");



*/

// TYPEDEF
/*

=== typedef === 

* You can assign a name to a type or type definition
  and then use that assigned name in declarations and
  headers.

* You put this in the .h file of the class using it.

ex:

typedef known_type Desired_Name;

typedef int NodeDataType;




*/

// EXCEPTION HANDLING
/*

* A way to be more specific or intentional about what should
  happen if something "bad" happens while a program is running.

* In C++, there's a mechanism for signaling that something
  unusual or bad or etc. has happened--
  (that's called THROWING an exception).

  at another place in your program,
  you place the code for handling the exceptional case;
  * this is called HANDLING the exception (people talk
    about exception-handlers);

    In C++, you can talk about CATCHING an exception
    (you can also talk about throwing it to another
    level...!)

* It IS intended to be used sparingly (if you can handle a
  common error with an IF-STATEMENT, that's usually better)

    * don't use for basic control flow;
      it is not intended to be a common alternative for
      returning a value

    * don't use it just to pop out of a loop.

=== SYNTAX ===

* try-block

  try
  {

  }

  * Idea: in a try-block should be a logical sequence
          of statements where an exception MIGHT be thrown.

          (you might throw it explicitly,
           or a statement within might throw the exception...)


* throw statement

  throw expression-for-the-exception-to-be-thrown;

  * what data type does expression-for-the-exception-to-be-thrown
    need to be in?

    In C++, this expression can be any data type you'd like,
    but ideally, it's best to throw objects from the
    std::exception class (or one of its subclasses)

    * you can use the exception class by:

      #include <exception>

  * use throw only to signal an error.


* catch-block

  catch (exception-type e)
  {

  }

  * written to handle, or catch, a particular
    type of exception that has been thrown in a try block.

    a try block can be followed by multiple catch blocks,
    one for each type of exception that might be thrown.

  * ...and if an exception is thrown in a try block,
    control passes AT that point to the FIRST catch block
    whose exception-type matches the thrown exception

    ...and after that catch block's actions, all the other
    catch blocks are skipped and control proceeds after
    the last catch block.

  * you can catch an exception by value,
    by reference,
    or by pointer.

    CATCH-BY-VALUE:

    catch (exception e)

    CATCH-BY-REFERENCE:

    catch (exception& e)

    CATCH-BY-POINTER:

    catch (exception* e)

      * and if you want to pass the exception by reference
        but NOT mess with it,
        add a const:

        catch (const exception& e)


*/

// INHERITANCE
/*

* Sometimes you want a class that happens to be
  reasonable to consider it as a specialized version
  or subclass of an existing class.

  Inheritance provides a means to derive a new 
  specialized ckass from an existing class,
  andinherit/obtain the code from that
  existing class automaitcally, which can then
  be modified as needed.

    * Inheritance works for representing so-called
      IS-A relationships.

* We'll call the class being derived from the base
  class or the superclass or the parent class.

  we'll call the class that results from that
  the derived class or the subclass or the child class.

=== SYNTAX ===

class MyDerivedClass: public MyBaseClass

class ColorPoint: public Point
  * reads as: ColorPoint is a class being derived from Point.

    and now ColorPoint has:

    * all the data fields,
      most of the methods,
    
    * and now you can add additional data fields and methods
      and can modify inherited methods as needed
      (and even overload inherited methods as needed)

* KEEP IN MIND:

  * subclass instances indeed have all the private data
    fields inherited from the base class --
    BUT they cannpt directly access these data fields.

    (the derived class instance CAN use inherited
     public accessors and public modifiers, though)

  * you are expected to provide appropriate constructors
    for the derived class, and these typically must call
    the base class' constructors to initialize the 
    inherited private data fields.

    SYNTAX:

    in MyDerivedClass.cpp:

    MyDerivedClass::MyDerivedClass(): MyBaseClass()
    {
      ...
    }

    MyDerivedClass::MyDerivedClass(type1 arg1, ...): MyBaseClass(arg1)
    {
      something = arg1;
    }

* NOTE!

  an instance of a derived class has MORE than
  one type..

  It is considered to have its class as one of its types,
  and it is also considered to be on of ALL of its
  base-or-ancestor classes:

  string name; // type string
  int x_val; // type int
  Point pt; // type Point
  ColorPoint cp; // type Point AND type ColorPoint

  So, for example, derived class instance CAN be an argument
  for a function expecting arguments of its base-or-ancestor
  classes.

  Another example, you can insert any ColorPoint instance in
  an array or a vector of type Point.



*/

// POLYMORPHISM
/*

!=RELATED TO INHERITANCE=!

* Being particular to object-oriented programming,
  polymorphism is the ability to associate MULTIPLE
  meanings to one METHOD name by means of a special mechanism
  called LATE binding or DYNAMIC binding;

* How can you give a method the ability to use late/dynamic
  binding?

  1. It has to be declared as virtual

     at LEAST in the base class class DECLARATION (in the .h)
     (and optionally by GOOD STYLE in the derived class DECLARATION)

     put the word "virtual" in front of the method header:

     class ExampleClass
     {
       public:
        ...
        virtual double example();

      ...
     }

     now, method example is now a virtual method.
     (and you are not required to put virtual in a class
     derived from ExampleClass, but it's good style to do so)

  2. If you have a pointer to a dynamic instance of class
     ExampleClass, you can have it point to instances of its
     derived class.

*/

// MULTI-INHERITANCE
/*

* TERM: Overriding

  * has to do with virtual methods

  * reminder: in a derived class,
    when a method has the same header as in the base class,
    that's considered a REDEFINED method, which essentially
    replaces the base class' version of that method.

    And, in a derived class,
    when a method has the same name but a different-enough
    set of parameters (different number, different types),
    those are considered OVERLOADED methods
    (in addition to any from the base class).

  * IF the method being given a particular implementation
    in a derived class happens to be a VIRTUAL method
    in the base class,
    then that method is said to be OVERRIDDEN, instead of
    redefined.

===
=== MULTIPLE INHERITANCE ===
===

* What is it???

  what it is NOT:
  this is NOT:

  class Dessert
  {
    ...
  };

  class Pie: public Dessert
  {
    ...
  };

  class CreamPie: public Pie
  {
    ...
  };

    ... this isn't multi-inheritance,
        it's just a chain of derived classes.

        CreamPie is derived from base class Pie,
        Pie is derived from Dessert
        Dessert is a grandparent, not a parent.


* What it ACTUALLY is:

  * When a class has more than one PARENT class

    that is:

    class DerivedClass: public ParentClass1, public ParentClass2

  * EXAMPLES:

    class Mammal // PARENT 1
    {
      ...
    };

    class WingedAnimal // PARENT 2
    {
      ...
    };

    class Bat: public Mammal, public WingedAnimal // CLASS WITH MULTI-INHERITANCE
    {
      ...
    };


    class Vehicle // PARENT 1
    {
      ...
    };

    class WeaponizedItem // PARENT 2
    {
      ...
    };

    class Tank: public Vehicle, public WeaponizedItem // CLASS WITH MULTI-INHERITANCE
    {
      ...
    };


===
A FEW DETAILS...
===

* The constructors for inherited classes are called in
  the same order they are inherited

  so, for
  class Tank: public Vehicle, public WeaponizedItem

  ... for a Tank object, the constructor for Vehicle
      will be called, then the constructor for WeaponizedItem

  (and destructors are called in reverse order)

* Issue example:

  What if both parents have a common public method?

  * you should get a compiler error -- because this 
    is ambiguous.
    BUT -- you an get around that by specifying which
    parent's version you want...

    In Bat, you could specifiy Mammal::method_name or
    WingedAnimal::method_name.


* THE DIAMOND PROBLEM:

  when two parents of a child have a common parent:

  class Person
  class Student: public Person
  class Faculty: public Person
  class TA: public Student, public Faculty

  ... when a TA object is created,
      the constructor for Student is called,
      the constructor for Faculty is called,
      the constructor for common parent Person is called TWICE,
        (two copies of the Person data fields...!)

      * solution! make the common parent a VIRTUAL base class
        of the multiple parents:

        class Faculty: virtual public Person
        class Student: virtual public Person


===
How about even more concepts that make use
of the keyword 'virtual'
===

* abstract class?

  idea: a class you dont want actual instances of,
        but you want to serve as a base class for one or
        more derived classes:

  * definition: In C++, an abstract class is one that 
    has at least one pure virtual method.

    * what is a "pure virtual method"?

      in the class definition,
      the method header starts with virtual
      and ends with the so-called pure specifier, = 0

      virtual ret_type method_name(...) = 0;

      and there is NO implementation of this method written
      for this class

    * and when a class has one or more pure virtual methods,
      when it is an abstract class,
      you cannot create instances of that class.
      (you can write functions with that class as one of its parameters, however)

    * if a derived class does NOT implement
      all of the pure virtual methods of its parent,
      it ALSO is an abstract class...


===
PURE abstract classes???!!11!
===

* a pure abstract class has ONLY pure virtual methods
  and NO data fields or concrete methoods.

  in general, a pure abtract class is used in C++ to
  define an interface, is intended to be inherited by
  concrete(non-abstract) classes

  * It's a way of forcing a kind of contract between the
    class designer and the users of that class.



*/

// "MODERN" TYPE CASTING
/*

* Sometimes, for some data types, 
  it is reasonable and useful to ask to get a version
  of an expression in a type other than its actual type.

  that can be called type casting --
  EX:

    * casting an int value to double
    * casting a double value to int

* Overtime, C++ has had more than one syntax for this;
  this is the more modern one.

* More-modern C++:
  * now provides FOUR operators for type casting.
  * Using static_cast
     
     * intended to be a valid conversion in C++,
       or than an appropriate constructor makes possible

  operator: static_cast
  type to convert to: in angle brackets
  expression to convert: in parantheses

  static_cast<double>(9)
  ...asks for the double version of int expression 9

  static_cast<int>(3.4 + 1.6)
  ...asks for the int version of the sum of two double types.


  

*/

// GIT AND GITHUB
/*

* Git - a popular distributed version control system.

* GitHub - a website, a web-based HOSTING service for projects
           (usually software projects) that use Git.

    Obtainable at:

    desktop.github.com

    !! FREE VERSIONS AVAILABLE !!


* with command-line git
  tend to see a lot of:

  git desired-git-command> argument

  manual page for a particular git command:

  man git-desired-git-command


* a repository is an archive of the code (and other docs)
  related to a project

    * often referred to as a "repo" or "rep" for short.

  * to make one:

    git init my-repository-name

    to make a current folder a repo:

    WITHIN THAT FOLDER:
    git init

    ...and that folder will now be a repo (but its
    files are not part of that repo yet)

* git status

    ... to see the current status of your repo

* git add file-or-files

    ... this "stages" or adds files to repo,
        but does not commit them

* git commit -m "short comment about this commit"

    ... commits all the staged/added files at this point
        (and you can roll back when needed)

===
extras
===

* You can configure various bits of info using:

  git config

  of the many settings, two of which are especially encouraged:

  user.name
  user.email

  setting for all local repos:

  git config --global user.name "Example Name"
  git config --global user.email "exampleemail@examp.com"

  * you can see a list of current configurations:

  git config --list


* to PUSH your repository from CS50 to your GitHub account:

  * Have your GitHub username and personal access token available

  * Set your user.name and user.email if you have not

  * Say WHERE you are pushing TO:

    git remote add origin https://github.com/username/repo-name.git

    git branch -M main

    git push -u origin main
      * NOTE - it asks for a password!
               you need to put your personal access token!!!

    git pull
      * to get the latest version from your remote.


* you can get a project repo and its entire version history using:

  git clone https://...


* You can also fork

    * it gives you the entire history of the forked
      repository, but for one's own continued work,
      not intending to update the repo forked from


* BRANCHES are also a big git thing:

  * You can make a branch to explore an idea, work on
    adding an additional user story or use case, work
    on fixing a bug, etc.

  * STEPS:
    * create a branch
    * check out the branch
    
    git branch desiredNewBranchName

    * it exists but not IN IT yet/

    git checkout desiredNewBranchName

    * Now you've check it out

*/

// A TASTE OF MAKEFILES
/*

* Observation #1: at the compiling stage (before linking and loading)
  you generally just need the .h files to compile a given .cpp file

* Observation #2: at the linking and loading stage, THAT'S when 
  you need the actual implementations of each function and
  class method (the .cpp files or the .o object files from compiling those .cpp's)

* Observation #3: when recompiling a large program, you don't
  really HAVE to recompile ALL the pieces, necessarily,
  every time; you only need to recompile pieces that have
  changed, or depend on parts that have been changed.

* make is a PROGRAM that knows how to take a makefile
  of the names of files needed for a program and the
  dependencies of those files and the commands for
  compiling and linking and loading that program,

  and does JUST the recompiling needed for that program.


* a makefile consists of a collection of entries

  * each entry has:
    * a target (usually a file)
    * the dependencies (files which the target depends on)
    * the command(s) to run, based on the target and dependencies

target: dependencies
        desired command # this line starts with a TAB!

* NOTE - the dependencies for a .o file:
compiled using - g++ -c example_file.cpp

EX:
======================

team-battle: team-battle.o Team.o PlayerChar.o rand_int.o
  g++ team-battle.o Team.o PlayerChar.o rand_int.o -o team-battle

team-battle.o: team-battle.cpp Team.h PlayerChar.h rand_int.h
  g++ -c team-battle.cpp

Team.o: Team.cpp PlayerChar.h
  g++ -c Team.cpp

PlayerChar.o: PlayerChar.cpp
  g++ -c PlayerChar.cpp

rand_int.o: rand_int.cpp
  g++ -c rand_int.cpp

clean:
  rm *.o

======================

* NOTE - the clean thingy is a nice, but optional touch,
  which makes typically removes the .o files
  after, type "make clean"

* HOW TO RUN? - Simply type: make
  if there is a file named makefile, and if it finds one,
  it'll use it

  if there is no makefile, but a Makefile, it'll use that.

*/

/*
    === WORKSPACE ===
*/

int main() 
{
    cout << boolalpha; 
    
    // do something 
    return EXIT_SUCCESS;
    
    
}