# CS232 Spring 2023 Assignment #3
# Dakota Donner
# Last modified: 3-2-2023

word = "claptrap"
guess = list("cliptrap")

def guessOne(aGuess):
    count = 0
    for i in aGuess:
        if i in word:
            count += 1
    return count == len(word)

def guessTwo(aGuess):
    correctWord = list(word)
    correctWord.sort()

    guessList = aGuess.copy()
    guessList.sort()

    if guessList == correctWord:
        return True
    else:
        return False

print(guessOne(guess))
print(guessTwo(guess))

def print_guessed():
    '''
    Prints out the secret word, revealing only those letters
    that have been guessed so far
    '''
    
    for i in word:
       if i in guess:
          print(i,end="")
       else:
          print("_",end="")
    print()

print_guessed()