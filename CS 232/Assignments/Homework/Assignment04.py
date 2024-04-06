# CS232 Spring 2023 Assignment #4
# Dakota Donner
# Last modified: 4-9-2023

import random
import collections

NUM_SIDES = 6       # Number of sides on each dice
NUM_DICE = 5        # Number of dice in the game
NUM_ROLLS = 3       # Number of rolls for each test
NUM_TESTS = 1000    # Number of tests to perform
PRINT = False        # If True, print rolls to screen

class Dice():
    def __init__(self, number_of_sides=NUM_SIDES):
        self.sides = number_of_sides
        self.__curRoll = 0

    def roll(self):
        self.__curRoll = random.randint(1, self.sides)

    def value(self):
        return self.__curRoll

normalDie = Dice()
twentySidedDie = Dice(20)

# is_yahtzee(listOfDice:list) -> bool
# ------
# Purpose:        Expects a list of Dice objects, and returns True or False
#                 if the Dice are a yahtzee(all the same value)
#
# Returns:        a boolean(True if Yahtzee, False if not)
#
# Side-effects:   none
# ------

def is_yahtzee(listOfDice:list):
    return all(x.value() == listOfDice[0].value() for x in listOfDice)

# best_value_to_keep(listOfDice:list) -> int
# ------
# Purpose:        Expects a list of Dice objects, and returns the value
#                 found on the most dice
#
# Returns:        an integer
#
# Side-effects:   none
# ------

def best_value_to_keep(listOfDice:list):
    diceVals = [x.value() for x in listOfDice]
    diceCounter = dict(collections.Counter(diceVals))
    return max(diceCounter, key=diceCounter.get)

# print_dice: list of Dice objects -> nothing
# purpose: expects a list of Dice objects
#    returns nothing
# side effect: prints to screen the values on the dice

def print_dice(the_dice):
    print("The dice values are: {0}".format([i.value() for i in the_dice]))

# play_yahtzee(listOfDice:list) -> None
# ------
# Purpose:        plays yahtzee
#
# Returns:        None
#
# Side-effects:   prints game progress and results
# ------

def play_yahtzee(listOfDice:list):
    for x in listOfDice:
            x.roll()
    BEST_VALUE = best_value_to_keep(listOfDice)

    for x in range(0,NUM_ROLLS):
        for x in listOfDice:
            if x.value() == BEST_VALUE:
                continue
            else:
                x.roll()

        if PRINT:
            print_dice(listOfDice)

        if is_yahtzee(listOfDice):
            break

    if PRINT:
        if is_yahtzee(listOfDice):
            print("YAHTZEE!!!")
        else:
            print("Aw, no Yahtzee...")

# test_yahtzee() -> None
# ------
# Purpose:        Expects nothing, runs the play_yahtzee function a certain
#                 amount of times, as declared by constant NUM_TESTS, and prints
#                 the rate of successful Yahtzees, and returns nothing
#
# Returns:        None
#
# Side-effects:   prints:
#                   Total # of tests
#                   # of successful Yahtzees
#                   Yahtzee rate
# ------

def test_yahtzee():
    diceList = [Dice() for x in range(0,NUM_DICE)]
    yahtzees = 0

    for x in range(0,NUM_TESTS):
        play_yahtzee(diceList)
        if is_yahtzee(diceList):
            yahtzees += 1

    print("Tests occured: {0}\nSuccessful Yahtzees: {1}\nYahtzee rate: {2:.2f}%".format(NUM_TESTS,yahtzees,((yahtzees/NUM_TESTS)*100)))