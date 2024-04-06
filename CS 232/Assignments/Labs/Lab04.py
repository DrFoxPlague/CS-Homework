# CS 232 Spring 2023 – Week 04 Lab 
# Peter Ramos and Dakota Donner and Milad Mohaddess
import math

PRICE_DICT = {'apples': 1.00, 'bananas': 2.00,'pears': 3.00,'carrots': 4.00,'broccoli': 5.00}

def problem_1():
    print (len(PRICE_DICT))
    print(PRICE_DICT["carrots"])
    print(PRICE_DICT.keys())
    print(PRICE_DICT.values())
    PRICE_DICT['apples'] = 1.99
    print(PRICE_DICT['apples'])
    PRICE_DICT.update({'grapes' : 2.68})
    print(PRICE_DICT)
    print('cauliflower' in PRICE_DICT)
    del PRICE_DICT['broccoli']
    print("Broccoli removed")
    
    count = 0
    for i in PRICE_DICT.values():
        count += i
    print(count)

my_points = { 'a': (4, 3), 'b': (1, 2), 'c': (5, 1) }
def distance(pointDict):
    pointOne = input("What's your first point?: ")
    pointOne = pointDict[pointOne]
    pointTwo = input("Second point?: ")
    pointTwo = pointDict[pointTwo]
    
    print("Distance between", pointOne, "and", pointTwo, ":", 
          math.sqrt(((pointTwo[0] - pointOne[0])**2) + ((pointTwo[1] - pointOne[1])**2)))
          






























