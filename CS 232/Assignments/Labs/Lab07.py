# CS 232 Spring 2023 – Week 07 Lab 
# Peter Ramos and Dakota Donner
import random

def dice_roller():
    while True:
        dice1 = random.randint(1,6)
        dice2 = random.randint(1,6)
        sum = dice1 + dice2
        yield sum
    
roll_dice = dice_roller()

def play_craps():
    first_roll = next(roll_dice)
    if (first_roll == 7) or (first_roll == 11):
        return True
    elif (first_roll == 2) or (first_roll == 3) or (first_roll == 12):
        return False
    else:
        point_val = first_roll
    next_roll = 0 
    while (next_roll != 7) or (next_roll != point_val):
        next_roll = next(roll_dice)
        if (next_roll == 7):
            return False
        elif (next_roll == point_val):
            return True



def run_trials(num_trials):
    wins = 0
    losses = 0
    for i in range(num_trials):
        if play_craps():
            wins += 1
        else:
            losses += 1
    print(f"Wins: {wins}, Losses: {losses}, Winning Percentage: {wins / num_trials * 100}%") 
