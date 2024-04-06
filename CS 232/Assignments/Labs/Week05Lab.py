# CS 232 Spring 2023 – Week 05 Lab 
# Peter Ramos and Dakota Donner

def until_break():
    while True:
        letter = input("Enter a Letter: ")
        if (letter == 'x'):
            break

#until_break()

def all_but_3s(max_value):
    x = 0
    while (x < max_value):
        x = x+1
        if (x%3 == 0):
            continue
        print (x, end= ' ')

#all_but_3s(100)

def list_all_but_3s(max_value):
    newlist = [x for x in range(0,max_value+1) if x%3 != 0]
    return newlist
        
#print (list_all_but_3s(100))

def alpha_dict():
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    myDict = {k+1:alphabet[k] for k in range(0,26) }
    return myDict
    
#print (alpha_dict())
    
    
def string_list(*args):
    arg_list = []
    for arg in args:
        if (type(arg) == str):
            arg_list.append(arg)
    return arg_list
    
#print (string_list("old", "some", "twelve", 2))

def list_at_index(my_tuple, index):
    size_list = [len(x) for x in my_tuple]
    if index > min(size_list)-1:
        return []
    new_list = [my_tuple[x][index] for x in range(0,len(my_tuple))]   
    return new_list
    
    
    
    
a_tuple =  ((0,  1,  2,  3,  4,  5,  6,  7,  8), 
       (10, 11, 12, 13, 14, 15), 
       (20, 21, 22, 23), 
       (30, 31, 32, 33, 34, 35, 36, 37), 
       (40, 41, 42, 43, 44, 45))
       
#print(list_at_index(a_tuple, 2))
    
    
    
    
    
    









