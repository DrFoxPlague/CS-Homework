# CS232 Spring 2022 Assignment #2 
# Dakota Donner
# Last modified: 2-17-2023

# letter_freq(aString:string) -> dictionary
# ------
# Purpose:        Expects a string value with no punctuation, and returns a dictionary, 
#                 with each letter as a key assigned to an int that represents how many 
#                 times that letter appeared.
#
# Returns:        A dictionary of letter frequencies
#
# Side-effects:   None
# ------

def letter_freq(aString):
    freqList = [x for x in aString.lower() if x not in " .,;:!?"]
    freqList.sort()
    freqDict = dict()

    for i in freqList:
        freqDict[i] = freqList.count(i)

    return freqDict


# freq_bar_chart(letFreqDict:dictionary) -> None
# ------
# Purpose:        Expects a dictionary of letter frequencies, returns nothing
#                 and prints a chart of letter frequencies to the screen.
#
# Returns:        None
#
# Side-effects:   Prints a bar chart that shows the frequencies of each letter
#                 with an 'X' mark.
# ------

def freq_bar_chart(letFreqDict):
    print("LETTER FREQUENCY CHART:\n------")
    for i in letFreqDict:
        print(i,"-",("X" * letFreqDict[i]))


# plot_points(pntDict:dictionary) -> None
# ------
# Purpose:        Expects a dictionary of coordinate points, prints
#                 a graph with the points plotted, and returns nothing
#
# Returns:        None
#
# Side-effects:   Utilizes lists to create and print a graph of the points.
# ------

def plot_points(pntDict):
    # max_coordinate_value: dict int -> int
    # Expects a dictionary of letters and ordered pairs,
    #     and an index value
    # Returns the maximum value of the X coordinates if
    #     the index value is 0, and the maximum value of
    #     the Y coordinates if the index value is 1

    def max_coordinate_value(the_dict, the_index):
        max_val = 0
        for a_point in the_dict:
            the_ordered_pair = the_dict[a_point]
            # max_val will have the largest value found so far
            if max_val < the_ordered_pair[the_index]:
                max_val = the_ordered_pair[the_index]
            
        return max_val

    yMax = max_coordinate_value(pntDict, 1)
    xMax = max_coordinate_value(pntDict, 0)
    graph = []

    #creating the graph
    for y in range(0, yMax+1):
        graph.append([])
        graph[y] = ["." for x in range(0, xMax+1)]

    #inserting into graph
    for key in pntDict:
        graph[abs(pntDict[key][1]-yMax)][pntDict[key][0]] = key

    #printing graph
    for x in range(0,yMax+1):
        print(yMax-x, *graph[x])
    print(" ", end=" ")
    for x in range(0, xMax+1):
        print(x, end=" ")
    print("")


# AUXILIARY FUNCTIONS FOR encode_message AND decode_message:
# ---------
ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ-. "

# relative_prime: int int -> bool
# Expects two positive integers >= 2
# Returns True if the integers are relatively prime
#     (that is, is their Greatest Common Divisior is 1)
# DO NOT ALTER THIS CODE!

def relative_prime(num_1, num_2):
    a, b = num_1, num_2
    while (b > 0):
        gcd = b
        b = a % b
        a = gcd
    return gcd == 1
    
# create_code_ring: int -> dict
# Expects a "seed" integer to initialize code mapping
# Returns a dictionary that maps each character in the
#     string constant ALPHABET to an int from 1 to the
#     length of the alphabet
# DO NOT ALTER THIS CODE!

def create_code_ring(seed):
    '''Expects an integer
       Returns a dictionary mapping each letter of a string
       constant ALPHABET to an integer from 1 to len(ALPHABET)'''
    alphabet_len = len(ALPHABET)
    
    # Use seed to set a usable (relatively prime) increment value
    inc_val = seed % alphabet_len
    if inc_val <= 1:
        inc_val = 2
    while not relative_prime(inc_val, alphabet_len):
        inc_val += 1

    # Inititalize index value and code_ring dictionary
    cur_idx = alphabet_len - 1
    code_ring = {}

    for i in list(ALPHABET):
        # Set next index value for mapping
        next_idx = (cur_idx + inc_val) % alphabet_len
        # print(i, " ", next_idx + 1) # UNCOMMENT TO SEE MAPPING
        code_ring.update({ i : next_idx + 1 })
        cur_idx = next_idx
    return code_ring
# ---------


# encode_message(message:str, aSeed:int) -> list
# ------
# Purpose:        Expects a message as a string, and a seed as an integer value,
#                 and returns a list with each character of the string as a coded
#                 integer value
#
# Returns:        A list of coded characters
#
# Side-effects:   None
# ------

def encode_message(message, aSeed):
    message = message.upper()
    codeRing = create_code_ring(aSeed)
    encodedMes = []

    for x in message:
        if x not in ALPHABET:
            print("Character",x,"not found; encoded to 99999")
            encodedMes.append(99999)
        else:
            encodedMes.append(codeRing[x])

    return encodedMes


# decode_message(codedMes:list, aSeed:int) -> string
# ------
# Purpose:        Expects a coded message as a list of int values, and a seed as an integer value,
#                 and returns a decoded message as a string value.
#
# Returns:        A string
#
# Side-effects:   None
# ------

def decode_message(codedMes, aSeed):
    codeRing = create_code_ring(aSeed)
    message = ""
    invCodeRing =  {val:key for key, val in codeRing.items()}

    for x in codedMes:
        if x == 99999:
            message += "@"
        else:
            message += invCodeRing[x]
    
    return message

