# OPERATIONS
# ------
"i" in "team"   # the "in" boolean operator detects if something is IN something.
# ------


# STRINGS
# ------
sample_string = "ABCDEFGH"  # Declaring
sample_string2 = "Hello how are you"
sample_string3 = "A"

# substrings
sample_string[0]  # Output is 'A'
sample_string[2]  # Output is 'C'

# using operators
sample_string3 * 3  # Output is 'AAA'
sample_string3 + sample_string  # Output is 'ABCDEFGHA' - concatenates the strings
sample_string > sample_string3  # Output is True - compares the lengths
# ------


# LISTS
# ------
my_list = ["green","blue","red","purple"]
len(my_list)  # returns the length
my_list[0]

split_list = sample_string2.split()  # splits each individual word seperated by spaces into a list of strings

# methods
my_list.append("pink")  # adds an item("pink") to the end of the list
my_list.remove("green") # removes a specified item
del my_list[1]  # removes an item at a specified index
my_list.insert(1, "magenta")    # inserts an object at a specified index(STAY WITHIN RANGE!!!)
my_list.index("purple") # returns the index of the object within the list
my_list.count("purple") # returns the number of occurences of the specified value
my_list.pop()   # returns value on the top and deletes it
    # The .sort method uses QUICKSORT

# slicing 
    # syntax - initial:end:indexjump

# list comprehensions
squares = [i ** 2 for i in range(10)]   # ONE LINE OF CODE!!! :D

sentence = "What is going on here??"
vowels = [i for i in sentence if i in "aeiou"]  # Uses conditionals

# assignment
ex_a = [1,2]
ex_b = ex_a
ex_b.append(3)  # List ex_a is also changed(points to the same place in memory)!!  This is how Python works!

ex_b = ex_a.copy()  # Use this to prevent it!!!

enumerate()     # Iterates through each list index, creating a index/element 2-tuple of each element.
# ------


# MAP FUNCTION
# ------
def square(x):
    return x ** 2

squares = map(square, range(10))    # map() returns a map object
# ------


# LOOPING
# ------
for i in split_list:    # loops through each item in split_list
    print(i)

i = 0
while i < len(split_list):
    print(type(split_list[i]))  # 'type' returns the data type of the specified element
    i += 1
# ------


# SHORTHANDS
# ------
x = 0   # Value initialized
x += 2  # Adds 2 and redfines variable as new value
        # Same works for -, *, /, %

# walrus operators
x = int(input())            # EXAMPLE OPERATION
print(x)

print(num:=int(input()))    # := condenses the example into a single operation
# ------


# CONDITIONALS
# ------
exampleBool = False

if exampleBool == True:     # If statement with expression
    print("It's true!\n:)")

elif exampleBool == False:  # Else-If statement
    print("It's false\n:(")

else:                       # Else statement
    print("ah")
# ------


# TUPLES
# ------
    # Syntactically, tuples use parentheses () and lists use brackets [].
    # Tuples are immutable(cannot be changed after declaration)

tuple(ex_a) # Creates a tuple out of a list

v = (2) # Python reads this simply as 2, not a single-element tuple.
v = (2,)    # Creates a singleton tuple.  Python reads the trailing comma.

# use this for swapping!
a = 1
b = 2
a, b = b, a     # Eliminates the reason for a 'temp' variable!!
# ------


# DICTIONARIES
# ------
a_dict = {1: "a",2: "b",3: "c"}    # uses curly braces; has a key tied to each item

    # By default, looping through dictionaries only loops through the keys!

a_dict.keys()   # Returns the keys
a_dict.values() # Returns the values
# ------


# SETS
# ------
a_set = {1, 2, 3}   # Essentially dictionary keys without associated values.
    # Does not allow duplicates

set("string")   # You can turn a string into a set

# set operations
    #   &   Intersection (items in both sets)
    #   |   Union (items in either set)
    #   -   Difference (items in first set that are not in the second)
    #   ^   Xor/Exclusive Or (Items in one set but NOT both)
# ------


# FUNCTIONS
# ------
def print_it(*args):    # *args means anything can be placed here
    print(args)

# docstrings
    # using single quotes '' allows you to use help(a_func)
    # triple quotes '''''' allows for multiple lines

# lambda functions
    # an unnamed function that can be used at runtime

lambda x : x ** 3   # Cubes x, removing the need for a cube function

# nesting
    # functions can be nested:

def printDouble(num):
    def double(numToDouble):
        return numToDouble * 2
    return double(num)
# ------


# GENERATORS
# ------
genOne = range(0,1000)  # One example

genTwo = (x for x in range(0,1000)) # Another example.  Sort of a tuple comprehension.

def factorial_gen():
    result = 1
    i = 1
    while True:
        result *= i
        i += 1
        yield result    # The 'yield' statement tells Python this is a generator function!

# assigning to a variable
gen_var = next(factorial_gen)   # 'next' assigns 'gen_var' to whatever 'factorial_gen' spits out
# ------


# DECORATORS
# ------
    # A decorator function is one designed to take a function as its input

# example 1
def helloUser(func):
    def innerExample(name):
        return "Hello, " + func(name)
    return innerExample

def get_text(name):
    return name + "."

helloUser(get_text)("Jason")    # returns "Hello, Jason."

decExOne = helloUser(get_text)
decExOne("Jason")               # returns the same


# example 2
def p_decorate(func):
    def func_wrapper(name):
        return "<p>" + func(name) + "</p>"
    return func_wrapper

decExTwo = p_decorate(get_text)
decExTwo("Mike")
# ------


# LOCAL AND GLOBAL SCOPE
# ------
    # Variables declared within a function are only accessible
    # by the function itself.  This is a LOCAL variable.

    # Variables declared outside of a function are accessible
    # by anything.  This is a GLOBAL variable.

# example
aVal = 5                # <--- within the global scope
def add_2():
    aVal = 2            # <--- within the local scope of add_2
    return aVal + 2

def add_3():
    global aVal         # <--- tells Python to modify aVal in the global space
    aVal = 4            # <--- aVal will actually change to 2, globally
    return aVal + 3

# FUN FACT - You can make a conditional variable

aVal = 3 if 3 == 3 else 2
# ------


# MODULES AND PACKAGES
# ------
    # Modules are single files(what YOU create)
    # Packages are folders of multiple files

import sys  # imports the "sys" package

sys.path.append(r"C:\Users\dhdon\Documents\Coding")  # so you can import your own file

# from <package> import <module>                # imports specific item from a package
# from <package> import <module> as <alt name>  # imports module with alternative name

# EXAMPLE
from math import sqrt           # considered better form to ONLY import what's needed
from math import sqrt as sq     # gives sqrt() an alias as sq()
import math as m                # you can even give a library/package an alias

# ------


# COUNTERS
# ------
    # a Counter is a generator-type object that can keep a count of how many times an
    # equivalent value shows up in a list or a tuple

from collections import Counter

c = Counter(["b", "b", "b", "a", "a", "c"])
dict(c)

# set operations work on Counters!
# ------


# EXCEPTION HANDLING
# ------
    # Python has a built-in way to "catch" an error/exception that's been "thrown"

    # the "try" keyword tells the system that the fllowing lines of code MIGHT
    # throw an exception that we wish to catch and handle in a way that doesn't
    # stop execution.

    # the code between "try" and "except" keywords then get exception handling based
    # on what comes after the "except".

try_list = [1, 2, 3, "r"]

try:
    print(try_list[3])
except IndexError:
    print("INDEX EXCEEDED! MAX INDEX IS:", len(try_list)-1)
except TypeError:
    print("TYPE ERROR!  INDICES MUST BE OF TYPE int!")
except:
    print("bitch idk wtf you did to break this shit")
# ------


# FILE I/O
# ------
import os   # Needed to set a directory
os.getcwd() # Tells you what directory you're working with
os.chdir("")    # Changes the directory

    # The open function takes two arguments:
    # The name of the file to be opened
    # A 2-letter string that specifies how to open it:
    # The first letter is:
        # 'r' for read
        # 'w' for write (overwrite)
        # 'a' for write (append)
        # 'x' for write (create new file)
    # The second letter is:
        # 't' for text
        # 'b' for binary
# ------


# OUTPUT FORMATTING
# ------
'{:7.2f}'.format(1/2)
# ------


# OBJECTS
# ------
    # Most of everything is implemented as an OBJECT.
    # Even atomic data types, like integers, have methods.

number = 7
number.__abs__()    # <--- absolute value

# creating classes
class LightSwitch():
    def __init__(self):
        self.switchIsOn = False

    def turnOn(self):
        self.switchIsOn = True

    def turnOff(self):
        self.switchIsOn = False

class Person():
    def __init__(self, name):
        self.name = name
    
    def change_name(self, new_name):
        self.name = new_name

class Student(Person):  # <-- child class
    def __init__(self, a_name, id_num):
        super().__init__(a_name)    # <-- calls the name attribute from the parent
        self.id = id_num

    # double underscore BEFORE an attribute means it's supposed to be PRIVATE!!
        
# ------


# F-STRINGS
# ------
    # A more streamlined syntax than old-style % formatting and positional .format()
    # formatting, at the expense of simply adding an "f" at the front of the string.

# example
name = "Jason"
age = 19

f"Hi, I'm {name}, and I am {age}"

    # Consider the following class definition:

class Comedian:
    def __init__(self, first_name, last_name, age):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
    def __str__(self):
        return f"{self.first_name} {self.last_name} is {self.age}."
    def __repr__(self):
        return f"{self.first_name} {self.last_name} is {self.age}. Surprise!"
    
    # The __str__ dunder is used for human-readable output when printing the object, while __repr__ is
    # output when "calling" the object within the interpreter.
# ------


# PATHLIB
# ------
import pathlib

pathlib.Path.cwd()
# ------