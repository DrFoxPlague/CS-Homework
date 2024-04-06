# CS 232 Spring 2023 – Week 02 Lab 
# Amy Nguyen and Dakota Donner


# Signature: c_to_f: float -> float
# Purpose: converts Celsius to Fahrenheit

def c_to_f(Ctemp):
    return ((Ctemp * 1.8) + 32)

# Signature: c_to_f_check: float -> float
# Purpose: converts Celsius to Fahrenheit,
#          but returns an error message if it
#          passes -273.16.

def c_to_f_check(Ctemp):
    if c_to_f(Ctemp) < -273.16:
        print("Temperature is too low!")
        return False
    else:
        return ((Ctemp * 1.8) + 32)

# Signature: yell_it: string -> void
# Purpose: determines if the input is a string,
#          if so, prints it in all capitals, if
#          not, prints an error message, and returns nothing

def yell_it(ifString):
    if type(ifString) == str:
        print(ifString.upper() + "!!!")
    else:
        print("Not a String!!!")

# Signature: divisible_by: int -> void
# Purpose: determines whether or not the
#          given input is divisible by 2-10
#          and prints whether it is or not

def divisible_by(aNum):
    if aNum > 0:
        for i in range(2,11,1):
            if (aNum % i) > 0:
                print(aNum,"is NOT divisible by",i)
            else:
                print(aNum,"is divisible by",i)
    else:
        print("NOT a positive number! >:T")

# Signature: test_demorgan: bool, bool -> bool
# Purpose: takes two boolean values and tests
#          whether or not DeMorgan's Laws work,
#          and returns true or false depending on
#          if the law works for the inputs

def test_demorgan(P,Q):
    return ( (not(P and Q) == (not(P) and not(Q))) and (not(P or Q) == (not(P) or not(Q))) )