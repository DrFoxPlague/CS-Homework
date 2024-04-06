##########################################################
# ASSIGNMENT 2 - CODE TO INSERT BEFORE PROBLEM 3
# DO NOT ALTER THIS CODE IN ANY WAY!

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
#
##########################################################


##########################################################
# ASSIGNMENT 2 - CODE TO INSERT BEFORE PROBLEM 4
# DO NOT ALTER THIS CODE IN ANY WAY!

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
#
##########################################################
