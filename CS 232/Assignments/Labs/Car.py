# CS 232 Spring 2023 - Week 10 Lab
# Dakota Donner & Peter Ramos
import math
class Car():
    def __init__(self, x_pos=0, y_pos=0):
        self.x = x_pos
        self.y = y_pos
        self.direction = 0
        self.speed = 0
    # left_or_right is a string "left" or "right"
    # direction is stored as an int as follows:
    #     0
    #     |
    # 3 --+-- 1
    #     |
    #     2
    #
    def turn(self, left_or_right):
        left_or_right.lower()
        
        if left_or_right == "left":
            self.direction -= 1
        elif left_or_right == "right":
            self.direction += 1
            
        if self.direction < 0:
            self.direction = 3
        elif self.direction > 3:
            self.direction = 0
    
        pass
    # time is number of time units to drive forward
    # (speed = distance drive per unit of time)
    def drive(self, time):
        
        if self.direction == 0:
            self.y += self.speed * time
        elif self.direction == 2:
            self.y -= self.speed * time
        elif self.direction == 1:
            self.x += self.speed * time
        else:
            self.x -= self.speed * time
        
        pass
    # Print all values of data members of object
    # Make it look pretty and readable!
    def print_status(self):
        print("*** CAR STATUS ***")
        print ("Current position is ({0}, {1})".format(self.x, self.y))
        if self.direction == 0:
            print("Current direction is up")
        elif self.direction == 1:
            print("Current direction is right")
        elif self.direction == 2:
            print("Current direction is down")
        else:
            print("Current direction is left")
        print("Current speed is {0}".format(self.speed))    
            
        pass
    # amount is change in speed - positive value
    # means speed up, negative means slow down --
    # note that it's possible to go backwards!
    def accelerate(self, amount):
        self.speed += amount
        pass
    # set speed to 0
    def stop(self):
        self.speed = 0
        pass
    # Calculate and print distance from (0,0)
    def distance_from_origin(self):
        origin = [0, 0]
        position = [self.x, self.y]
        return("Car's distance from (0,0) is {0:.2f} Units".format(math.dist(origin, position)))
        pass
