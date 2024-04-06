# CS232-03-Dakota-Donner.py
# Name: Dakota Donner
# Last Modified: 3-2-2023

# Adapted from MIT 6.189, MIT Open Courseware
# Used by permission of Creative Commons license
# Adapted for use in CS 232 by David Tuttle

# Import statements: DO NOT write code above this!

from random import randrange
from string import *
import os

# Uncomment the next statement and insert the path to the
# directory where your Python module and words.txt files
# are located. This makes loading the words.txt file work

#os.chdir(r"")

# CONSTANT AND GLOBAL VARIABLE DEFINITIONS

# Define name of file containing the dictionary of words
WORDLIST_FILENAME = "hangman_words.txt"

# NOTE: Changing the maximum number of guesses
# will require altering the print_hangman_image
# code -- PLEASE leave at 6 unless you're willing
# to make substantial changes elsewhere!
MAX_GUESSES = 6

# GLOBAL VARIABLES (with default values for testing)

# secret_word is the word being guessed during the game
secret_word = 'claptrap'

# letters_guessed is the list of letters the player has
# guessed during the current game - BE SURE TO EMPTY
# THIS LIST after each game!
letters_guessed = []

###################################################################
# Helper code - DO NOT ALTER ANY OF THE HELPER CODE!

# load_words: void -> list
# expects nothing
# returns a list of words read from the WORDLIST_FILENAME

def load_words():
    '''
    Returns a list of valid words. Words are strings of lowercase
    letters.

    Depending on the size of the word list, this function may
    take a while to finish.
    '''
    print("Loading word list from file...")
    # inFile is a file handle, like you see in C++
    inFile = open(WORDLIST_FILENAME, 'rt')
    # line is a string to hold the contents of the file
    line = inFile.readline()
    # wordlist is a list of words found in the file
    wordlist = line.split()
    
    print("  ", len(wordlist), "words loaded.")
    print('Enter play_hangman() to play a game of Hangman!')
    return wordlist

# We run the load_words() function to get the list of words.
# The list_of_words variable is global so it can be used
# in any of the functions defined in this module

list_of_words = load_words()

# You will run get_word() within your play_hangman() function
# to randomly select a secret word by using a statement like
# this within your function:

# secret_word = get_word()

# get_word: void -> str
# expects nothing
# returns a word rendomly selected from the file "words.txt"

def get_word():
    '''
    Retrieves a random word from the list of available words
    '''
    chosen_word = list_of_words[randrange(0, len(list_of_words))]
    return chosen_word

# NOTE: original ASCII images created by internet artist sk
#       replaced with smaller images by David Tuttle

# print_hangman_image: int -> void
# expects an integer for the number of incorrect guesses so far
# returns nothing
# side effect: prints to the screen a drawing of the Hangman
#     game based on the number of incorrect guesses

def print_hangman_image(mistakes=6):
  '''
  Prints out a gallows image for hangman.
  The image printed depends on the number of mistakes (0-6).
  '''

  if mistakes <= 0:
    print('''
        __________
        |    |       
        |
        |
        |
        |
        |_________
        ''')

  elif mistakes == 1:
    print('''
        __________
        |    |       
        |    O
        |
        |
        |
        |_________
        ''')
  elif mistakes == 2:
    print('''
        __________
        |    |       
        |    O
        |    |
        |    |
        |
        |_________
        ''')
  elif mistakes == 3:
    print('''
        __________
        |    |       
        |    O
        |   /|
        |    |
        |
        |_________
        ''')
  elif mistakes == 4:
    print('''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   
        |_________
        ''')
  elif mistakes == 5:
    print('''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   /
        |_________
        ''')
  else: # mistakes >= 6
    print('''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   / \\
        |_HANGED!_

        ''')
  
# End of helper code - DO NOT ALTER HELPER CODE!
###################################################################

# THE FOLLOWING IS TO BE COMPLETED BY THE STUDENT

# word_guessed: void -> bool
# expects nothing
# returns True if the word (stored in secret_word) has been
#     completely guessed, based on the letters_guessed list
# returns False otherwise

def word_guessed():
    '''
    Returns True if the player has successfully guessed the word,
    and False otherwise.
    '''
    global secret_word
    global letters_guessed

    count = 0
    for i in secret_word:
        if i in letters_guessed:
            count += 1
    return count == len(secret_word)


# print_guessed: void -> void
# expects nothing, returns nothing
# side effect: prints to the screen (on one line) a letter
#     of the secret word if it has been guessed, and "_" for
#     any letter that hasn't yet been guessed

# For example, if the word is "claptrap" and the letters
# guessed so far are ['a', 'e', 'p', 't'] then it should print:
#
# _ _ a p t _ a p

def print_guessed():
    '''
    Prints out the secret word, revealing only those letters
    that have been guessed so far
    '''
    global secret_word
    global letters_guessed
    
    print("        ",end="")
    for i in secret_word:
       if i in letters_guessed:
          print(i,end="")
       else:
          print("_",end="")
    print()
    print()


# play_hangman: void -> void
# expects nothing, returns nothing
# side effects:
# This function controls the playing of the game Hangman by:
# -- clearing the list of guessed letters!!!
# -- choosing a secret word (or using "claptrap" for testing)
# -- asking the player for letters to guess, one at a time
# -- displaying the Hangman image after each guess
#    (by calling the function print_hangman_image)
# -- displaying the word as guessed so far after each guess
#    (by calling the function print_guessed)
# -- When the word has been completely guessed, tell the
#    user they've won! (Use the word_guessed function for this)
# -- If the word's not completely guessed before the maximum
#    number of mistakes, tell the user they've lost and reveal
#    the word they didn't get

def play_hangman():
    '''
    Plays the Hangman game!
    '''
    global secret_word
    global letters_guessed
    
    # For debugging purposes, don't uncomment the line below,
    # and the word will always be "claptrap".  This will help
    # you test your function.  When you're confident your
    # function works, un-comment the line below to let the
    # computer select a word at random.
    playAgain = "y"

    print("\nWelcome to...\n")
    print("===========")
    print("==HANGMAN==")
    print("===========") 
    print("\nCan you save him, or will the rope swing?\n")
    while playAgain == "y":
        secret_word  = get_word()
        letters_guessed.clear()
        mistakeCount = 0
        while True:
            print_hangman_image(mistakeCount)
            print_guessed()
            print("Letters guessed: ", " ".join(letters_guessed))
            guess = input("Make a guess...: ")
            if guess in letters_guessed:
                continue
            else:
                letters_guessed.append(guess)
       
            if word_guessed():
                print("You win...the man is safe")
                break
            elif guess in secret_word:
                print("Correct...")
            else:
                print("Wrong...")
                mistakeCount += 1
                if mistakeCount == MAX_GUESSES:
                    print_hangman_image(mistakeCount)
                    print("You have lost...")
                    print("The key to his release was...: ", secret_word.upper())
                    playAgain = input("Play again?(y/n): ")
                    break
            

    # Place this return line as is at the end of play_hangman
    return None