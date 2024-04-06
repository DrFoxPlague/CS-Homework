# CS 232 Spring 2022 – Week 08 Lab
# Peter Ramos and Dakota Donner

from collections import Counter

def more_vowels(string1:str, string2:str):
    '''
    Expects two strings and determines which one
    has the most vowels.

    Expects:
        string1 - First string
        string2 - Second string

    Returns:
        An int value:
            1 - string1 has more vowels
            2 - string2 has more vowels
            0 - both have equal amount of vowels

    Side-effects:
        Prints a message, depending on the result:
            "The first string has more vowels"
            "The second string has more vowels"
            "The strings have an equal number of vowels"
    '''
    str1 = string1.lower()
    str2 = string2.lower()
    VOWELS = "aeiou"
    vc1 = 0
    vc2 = 0

    c1 = dict(Counter(str1))
    c2 = dict(Counter(str2))

    for i in VOWELS:
        if i in c1:
            vc1 += c1[i]
        if i in c2:
            vc2 += c2[i]

    if vc1 > vc2:
        print("The first string has more vowels")
        return 1
    elif vc1 < vc2:
        print("The second string has more vowels")
        return 2
    else:
        print("The strings have an equal number of vowels")
        return 0