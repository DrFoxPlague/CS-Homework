// Intro
/*

Using existing programming skills

    * Creating Data structures using the big 4:
        * INSERT
        * REMOVE
        * SEARCH
        * SORT

All textbook assignments due late Sept.

*/

// Abstract Data Types
/*

An ADT is "a data type where programmers who use
it do not have access to the details of how the
values and operations are implemented"

There are two ways to interpret what ADT means:

    * In one, it's an object class with public and private parts,
      where methods like constructors, accessors, mutators, etc, 
      are used to interact with objects.

    * In the other, it's a structure that contains such objects as
      its elements.  THIS IS THE FOCUS OF CS 211.


* We define program behvaior in terms of operations to be performed
  on data.

* The details will emerge as we refine the definitions of the operations.

* Only then will implementation of those operations be carried out

* As part of this, we must choose appropriate data structures

* A DATA STRUCTURE is a technique of storing and organizing data so
  it can be used efficiently.

* A data structure can be independent of the data type it contains.
  For example, an array can hold integers, or doubles, or strings, etc,
  as its elements.

*/

// Stacks
/*

A stack is a kind of ADT
...also called a last-in-first-out(LIFO) linear structure!
   (items can only be added and removed from one end)

Actions:
      * PUSH - insert into stack
      * POP - remove from stack
      * TOP - return the value of the item at the top of the stack
      * EMPTY - determine if the stack is empty
      * CREATE - create a new empty stack



*/

// Objects, Classes, and Methods
/*

* A fundamental to object-orientated programming (OOP) is the
  notion of an OBJECT

* An OBJECT is a data structure, combined with the operations
  pertinent to that structure



*/

// Data Encapsulation
/*

* The combination of data members and methods in a class
  is referred to as DATA ENCAPSULATION

*/

// Inheritance
/*

* INHERITANCE is a technique of reusing exisiting class definitions
  to derive new classes.

* These new clases (called derived classes or subclasses or child subclasses)
  can inherit the attributes and behavior of the pre-existing classes (called base classes
  or superclasses or parent classes).

* Derived classes can add, delete, & modify methods and data members
  in their own definitions (known as OVERRIDING)

*/

// Pointers
/*

* A variable defined in a program has two important attributes
  * Its content or value (what it stores)
  * Its location or address (where it is)

* Normally, we access a variable's content by specifying the variable's NAME

* Pointers allow us to store a variable's address in another variable.

--- HOW TO USE ---

* To assign a variable's address to a pointer, the reference operator (&) 
  is placed before the variable

* For pointer p_ptr to a point variable x, we write:

      p_ptr = &x;

* To access p_ptr's value, we have to use the dereference operator (*):

      *p_ptr <--- refers to the value stored in p_ptr, the address of x

*/

// Computational and Asymptotic Complexity
/*



*/

// Big-O Notation
/*



*/