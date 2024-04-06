# Dakota Donner
# Last Modified: 2-3-2023

# multiples_in_range: int int int -> int
# ------
# Purpose:        Expects 3 positive numbers, a number to
#                 be multiplied, the beginning of the desired
#                 range, and the end of the range, has the side
#                 effect of printing each multiple of the first
#                 number within the given range, and returns the
#                 number of values printed.
#
# Returns:        The number of printed values.
#
# Side-effects:   Prints multiples of a given number on a given
#                 range.
# ------

def multiples_in_range(mult, rangeStart, rangeEnd):
    if mult and rangeStart and rangeEnd < 0:                    # Check if positive, error if not
        print("Values MUST be **POSITIVE**!!!")
        return 0
    count = 0
    if rangeStart % mult == 0:                                  # BASE CASE -  Beginning of range is a multiple
        for i in range((rangeStart + 2), rangeEnd, mult):
            print(i)
            count += 1
        return count
    else:
        for i in range(rangeStart, rangeEnd):                   # ELSE - find first multiple before engaging loop
            if i % mult == 0:
                for i in range(i, rangeEnd, mult):
                    print(i)
                    count += 1
                return count
                break


# letter_grade: float -> str
# ------
# Purpose:        Expects a grade as a float and returns
#                 the corresponding letter grade
#
# Returns:        A string, the letter grade
#
# Side-effects:   None
# ------

def letter_grade(grdFloat):
    if grdFloat >= 90:
        return "A"
    elif 80 <= grdFloat < 90:
        return "B"
    elif 70 <= grdFloat < 80:
        return "C"
    elif 60 <= grdFloat < 70:
        return "D"
    else:
        return "F"


# bump_it: any -> same
# ------
# Purpose:        Expects an input of any type, performs
#                 a specific action depending on the value
#                 and returns the same data type but with a
#                 slight modification depending on the type
#
# Returns:        The same data type as the input
#
# Side-effects:   Does the following for each data type:
#                       integer: adds 1 to the value
#                       float: adds 0.1 to the value
#                       string: appends "!" to the end
#                       boolean: gives the opposite
#                       everything else: goes unchanged
# ------

def bump_it(aValue):
    if type(aValue) == int:
        return aValue + 1
    elif type(aValue) == float:
        return aValue + 0.1
    elif type(aValue) == str:
        return aValue + "!"
    elif type(aValue) == bool:
        return not(aValue)
    else:
        return aValue


# my_nickname: str -> str
# ------
# Purpose:        Expects a name, as a string, and takes the first 5
#                 characters to create a nickname:
#                       
#                   If the string is less than 5 characters long, returns as is
#
#                   If the string's 5th character is "y", then it returns the string
#                   without it
#
#                   If not, it appends a "y" to the end
#
# Returns:        A string
#
# Side-effects:   None
# ------

def my_nickname(name):
    name = name.capitalize()
    
    if len(name) < 5:
        return name

    name = name[0:5]
    
    if name[4] == "y":
        return name[0:4]
    else:
        return (str(name) + "y")


# flip_case: str -> str
# ------
# Purpose:        Expects any string, and returns the same string modified,
#                 depending on the following cases:
#
#                   If it's all uppercase, returns it in all lowercase
#
#                   If it's all lowercase, returns it in all uppercase
#
#                   If it's a mix of two different cases, returns it
#                   with the first character in the opposite case
#
# Returns:        A string
#
# Side-effects:   None
# ------

def flip_case(aStr):
    if aStr.isupper():
        return aStr.lower()
    elif aStr.islower():
        return aStr.upper()
    else:
        return aStr[0].swapcase() + aStr[1:]


# fibonacci_list: int -> list
# ------
# Purpose:        Expects an integer greater than or equal to 2,
#                 and returns a list of fibonacci numbers of
#                 said length.
#
# Returns:        A list of fibonacci numbers
#
# Side-effects:   None
# ------

def fibonacci_list(desLen):
    if type(desLen) != int or desLen < 2:
        print("CHECK VALUES!!!  Must be type INT of at least 2!")
        return []

    defFiboList = [0, 1]

    for i in range(2,desLen):
        defFiboList.append(defFiboList[(i - 1)] + defFiboList[(i - 2)])

    return defFiboList