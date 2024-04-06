# CS232 Spring 2023 Assignment #5
# Dakota Donner
# Last modified: 4-26-2023

# PROGRAM RULES:
#   * 6 tries
#   * Green = CORRECT ; Yellow = CORRECT+WRONG SPOT ; Gray = INCORRECT
#   * no word selected more than once from the given list
#   * player must be given the option to play again or quit the game

# NEEDED PACKAGES
# ======
from random import *
import os
from tkinter import *
# ======

# == SET DIRECTORY HERE ==
os.chdir(r"C:\Users\dhdon\Documents\Coding\CS 232\Assignments\Homework")

# CONSTANTS + VARIABLES
WORD_FILE = "5letterwordsCopy.txt"
MAX_TRIES = 6
words = []
wordOTD = "EMPTY"
statusList = ["gray","gray","gray","gray","gray"]
guesses = 0
isCorrect = False

# createWordList() -> None
# ------
# Purpose:        Expects nothing and creates a list of words
#                 from the given file
#
# Returns:        None
#
# Side-effects:   Changes the words to all caps and
#                 puts them in a list
#                  
#                 Also prints a feedback message
# ------

def createWordList():
    '''
    Pulls from a file named 5letterwords.txt and
    puts them into a list in all caps

    USE TO CREATE/RESET THE LIST OF WORDS!!!
    '''
    print("WORD LIST CREATED")
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
# Side-effects:   Prints a feedback message
# ------

def getWord():
    '''
    Sets a random word to be "word of the day"
    '''
    global words
    global wordOTD
    print("WORD RETRIEVED")
    
    wordOTD = words[randrange(0,len(words))]
    #print("WORD: ",wordOTD)    # UNCOMMENT FOR DEBUGGING!

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
#                 Also prints a feedback message
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

# printHint(guessWord:str) -> str
# ------
# Purpose:        Expects a guess as a string and returns the correctly guessed
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
    Returns a hint based on what was guessed so far.

    For example, if the word of the day was "THERE" 
    and the guess was "SHEAR", then the following would return:

    "_HE__"
    '''
    guessWord = guessWord.upper()
    hintReturn = ""

    if guessWord == wordOTD:
        hintReturn = guessWord
        return hintReturn
    
    for x in range(0,5):
        if statusList[x] == "green":
            hintReturn += guessWord[x]
        else:
            hintReturn += "_"

    for x in range(0,5):
        print("{0}: {1} ".format(guessWord[x],statusList[x]),end="")
    print()
    return hintReturn

# Wordle()
# ------
# Purpose:        Wordle game class
# ------

class Wordle():
    def __init__(self,parent_window):
        self.frame = Frame(parent_window)
        self.frame.grid()
        self.letter_1 = StringVar()
        self.letter_2 = StringVar()
        self.letter_3 = StringVar()
        self.letter_4 = StringVar()
        self.letter_5 = StringVar()
        self.error_out = StringVar()

        # guess button
        self.guess_button = Button(self.frame, font=('Helvetica',12))
        self.guess_button.grid(row = 1, column = 3)
        self.guess_button['text'] = "GUESS:"
        self.guess_button['command'] = self.guess_and_return

        # replay button
        self.replay_button = Button(self.frame, font=('Helvetica',12))
        self.replay_button.grid(row = 1, column = 3)
        self.replay_button['text'] = "AGAIN?"
        self.replay_button['command'] = self.replay_game

        # entry box
        self.guess_box = Entry(self.frame, fg = 'black', font=('Helvetica',12))
        self.guess_box.grid(row = 1, column = 2)
        self.guess_box['width'] = 10

        # resulting text
        self.result_text1 = Label(self.frame, fg = "gray", bg = 'gray10', font=('Helvetica',50), width = 1)
        self.result_text1.grid(row = 10, column = 4)
        self.result_text1['textvariable'] = self.letter_1

        self.result_text2 = Label(self.frame, fg = "gray", bg = 'gray10', font=('Helvetica',50), width = 1)
        self.result_text2.grid(row = 10, column = 5)
        self.result_text2['textvariable'] = self.letter_2

        self.result_text3 = Label(self.frame, fg = "gray", bg = 'gray10', font=('Helvetica',50), width = 1)
        self.result_text3.grid(row = 10, column = 6)
        self.result_text3['textvariable'] = self.letter_3

        self.result_text4 = Label(self.frame, fg = "gray", bg = 'gray10', font=('Helvetica',50), width = 1)
        self.result_text4.grid(row = 10, column = 7)
        self.result_text4['textvariable'] = self.letter_4

        self.result_text5 = Label(self.frame, fg = "gray", bg = 'gray10', font=('Helvetica',50), width = 1)
        self.result_text5.grid(row = 10, column = 8)
        self.result_text5['textvariable'] = self.letter_5

        # error text
        self.error_text = Label(self.frame, fg = "red", font=('Helvetica', 12))
        self.error_text.grid(row = 1, column = 4, columnspan=5)
        self.error_text['textvariable'] = self.error_out

        # setting defaults
        self.letter_1.set('{0}'.format("_"))
        self.letter_2.set('{0}'.format("_"))
        self.letter_3.set('{0}'.format("_"))
        self.letter_4.set('{0}'.format("_"))
        self.letter_5.set('{0}'.format("_"))
        self.guess_button.grid()
        self.replay_button.grid_remove()

    # clear method
        # clears the word box and resets the colors
    def clear(self):
        global statusList
        statusList = ["gray","gray","gray","gray","gray"]
        self.result_text1.configure(fg = statusList[0])
        self.result_text2.configure(fg = statusList[1])
        self.result_text3.configure(fg = statusList[2])
        self.result_text4.configure(fg = statusList[3])
        self.result_text5.configure(fg = statusList[4])
        self.letter_1.set('{0}'.format("_"))
        self.letter_2.set('{0}'.format("_"))
        self.letter_3.set('{0}'.format("_"))
        self.letter_4.set('{0}'.format("_"))
        self.letter_5.set('{0}'.format("_"))
        self.error_out.set('{0}'.format(""))

    # guess_and_return method
        # guess button function
    def guess_and_return(self):
        global guesses
        global isCorrect

        self.text_in = str(self.guess_box.get())
        self.guess_button.grid()
        self.replay_button.grid_remove()

        if len(self.text_in) != 5:
            self.error_out.set('')
            self.error_out.set('{0}'.format("Not enough letters"))
        elif self.text_in.upper() not in words:
            self.error_out.set('')
            self.error_out.set('{0}'.format("Not in word list"))
        else:
            self.error_out.set('')
            guessStatus(self.text_in)
            self.text_out = (printHint(self.text_in))

            self.result_text1.configure(fg = statusList[0])
            self.result_text2.configure(fg = statusList[1])
            self.result_text3.configure(fg = statusList[2])
            self.result_text4.configure(fg = statusList[3])
            self.result_text5.configure(fg = statusList[4])

            self.letter_1.set('{0}'.format(self.text_out[0]))
            self.letter_2.set('{0}'.format(self.text_out[1]))
            self.letter_3.set('{0}'.format(self.text_out[2]))
            self.letter_4.set('{0}'.format(self.text_out[3]))
            self.letter_5.set('{0}'.format(self.text_out[4]))
            
            guesses += 1


        if self.text_in.upper() == wordOTD or guesses >= MAX_TRIES:
            if self.text_in.upper() == wordOTD:
                isCorrect = True
            self.error_out.set('{0}'.format(("Word:" + wordOTD)))
            self.guess_button.grid_remove()
            self.replay_button.grid()

    # replay_game method
        # replay button function
    def replay_game(self):
        global guesses
        global words
        global isCorrect
        if isCorrect:
            words.remove(wordOTD)
        if len(words) == 0:
            self.error_out.set('{0}'.format("WORD LIST EMPTY! LIST RESET!"))
            createWordList()
        guesses = 0
        getWord()
        isCorrect = False
        self.guess_button.grid()
        self.replay_button.grid_remove()
        self.clear()

# playWordle() -> None
# ------
# Purpose:        Plays the Wordle game with a nice GUI
#
# Returns:        None
#
# Side-effects:   None
# ------

def playWordle():
    createWordList()
    getWord()

    game_window = Tk()
    game_window.title("Wordle")
    game_window.geometry("500x250")

    play_game = Wordle(game_window)

    game_window.mainloop()
   
    try:
        game_window.destroy()
    except:
        print("TASK ENDED")


playWordle()   # UNCOMMENT TO PLAY! :)