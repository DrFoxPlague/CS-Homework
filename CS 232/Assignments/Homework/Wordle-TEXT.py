# CS232 Spring 2023 Assignment #5
# Dakota Donner
# Last modified: 4-20-2023

# PROGRAM RULES:
#   * 6 tries
#   * Green = CORRECT ; Yellow = CORRECT+WRONG SPOT ; Gray = INCORRECT
#   * no word selected more than once from the given list
#   * player must be given the option to play again or quit the game

# NEEDED PACKAGES
# ======
from random import *
import os
# ======

# == SET DIRECTORY HERE ==
os.chdir(r"C:\Users\dhdon\Documents\Coding\CS 232\Assignments\Homework")

# CONSTANTS + VARIABLES
WORD_FILE = "5letterwords.txt"
MAX_TRIES = 6
words = []
wordOTD = "EMPTY"
statusList = []

# createWordList() -> None
# ------
# Purpose:        Expects nothing and creates a list of words
#                 from the given file
#
# Returns:        None
#
# Side-effects:   Changes the words to all caps and
#                 puts them in a list
# ------

def createWordList():
    '''
    Pulls from a file named 5letterwords.txt and
    puts them into a list in all caps

    USE TO CREATE/RESET THE LIST OF WORDS!!!
    '''
    global words

    fileIn = open(WORD_FILE,"rt")
    words = fileIn.read().upper().split()
    fileIn.close()

# getWord() -> None
# ------
# Purpose:        Expects nothing and sets a random word
#                 from the list of word to be the word of the day
#
# Returns:        None
#
# Side-effects:   None
# ------

def getWord():
    '''
    Sets a random word to be "word of the day"
    '''
    global words
    global wordOTD

    wordOTD = words[randrange(0,len(words))]

# guessStatus(guessWord:str) -> None
# ------
# Purpose:        Expects a 5 letter word, and adds the current status
#                 of the guessed word to the list statusList
#
# Returns:        None
#
# Side-effects:   Adds color statuses to statusList accordingly:
#                       * green - correct letter & spot
#                       * yellow - correct letter but wrong spot
#                       * gray - incorrect
# ------

def guessStatus(guessWord:str):
    '''
    Appends a color depending on the status
    of each letter to a list variable named statusList.

    Possible colors:
        * green - correct letter AND correct spot
        * yellow - correct letter BUT wrong spot
        * gray - incorrect letter
    '''

    global statusList
    statusList.clear()
    guessWord = guessWord.upper()

    if guessWord == wordOTD:
        statusList = ["green" for x in range(0,5)]
        return
    
    for x in range(0,5):
        if guessWord[x] == wordOTD[x]:
            statusList.append("green")
        elif guessWord[x] in wordOTD:
            statusList.append("yellow")
        else:
            statusList.append("gray")

# printHint(guessWord:str) -> None
# ------
# Purpose:        Expects a guess as a string and prints the correctly guessed
#                 letters in their correct spot.
#
# Returns:        None
#
# Side-effects:   Prints the correctly guessed(spot+letter) in it's
#                 appropriate spot, and a "_" for the spots that haven't
#                 had a correct guess yet.
# ------

def printHint(guessWord:str):
    '''
    Prints a hint based on what was guessed so far.

    For example, if the word of the day was "THERE" 
    and the guess was "SHEAR", then the following would print:

    "_HE__"
    '''
    guessWord = guessWord.upper()

    if guessWord == wordOTD:
        print(guessWord)
        return
    
    for x in range(0,5):
        if statusList[x] == "green":
            print(guessWord[x],end="")
        else:
            print("_",end="")
    print()

    for x in range(0,5):
        print("{0}: {1} ".format(guessWord[x],statusList[x]),end="")
    print()

# playWordle() -> None
# ------
# Purpose:        Plays the Wordle game
#
# Returns:        None
#
# Side-effects:   None
# ------

def playWordle():
    global wordOTD
    global words

    createWordList()        # Pull words from file, add them to a list

    print("=== WORDLE ===")

    while True:
        # GAME SET-UP
        userTries = 0           # Creating an incrementer
        getWord()               # Pulls a random word from the list
        os.system('cls')        # Clearing console of clutter

        while userTries < 6:
            userGuess = input("Enter your guess: ")

            # SAFETY NETS/CONDITIONALS
            if len(userGuess) != 5:                     # Prevents guesses not equal to 5 letters
                print("Not enough letters")
                continue
            if userGuess.upper() not in words:          # Prevents guesses not in word list
                print("Not in word list")
                continue

            guessStatus(userGuess)                      # Setting color status so far
            printHint(userGuess)                        # Printing hint so far


            userTries += 1                              # Incrementing

            if userGuess.upper() == wordOTD:            # Checking if guessed
                words.remove(wordOTD)                   # Deleting old word from list
                break
        
        print("\nThe correct word is: ", wordOTD)

        userEntry = input("Play again? (y/n): ")
        userEntry = userEntry.upper()

        if len(words) == 0:                                 # Checks if word list is used up
            print("OUT OF WORDS!")
            userEntry = input("Reset word list?: (y/n): ")  # Providing user the option to reset the list
            userEntry = userEntry.upper()

            if userEntry[0] == "Y":
                words = []
                createWordList()                            # Pull words from file, add them to a list
                continue
            elif userEntry[0] == "N":
                break

        if userEntry[0] == "Y":
            continue
        elif userEntry[0] == "N":
            break


#playWordle()   # UNCOMMENT TO PLAY :)