# CS 232 Peter Ramos Dakota Donner Milad Mohaddas

import os
os.chdir(r"C:\Users\pnr12\Downloads")

def gettysburg(a_letter):
    my_file = open("GettysburgAddress.txt", "rt")
    file_content = my_file.read().split()
    my_file.close()
    count = 0
    
    for i in file_content:
        if a_letter == i[0]:
            count += 1

    print( "There are {0} words in the Gettysburg Address that start with {1}".format(count,a_letter) )

def count_sentences(a_filename):
    my_file = open(a_filename, "rt")
    file_content = my_file.read().split()
    my_file.close()
    count = 0

    for i in file_content:
        if (i[-1] == ".") or (i[-1] == "!") or (i[-1] == "?"):
           count += 1

    if (count == 0):
        print ("There are no sentences in {0}".format(a_filename) )       
    elif (count == 1):
        print ("There is one sentence in {0}".format(a_filename) )
    else:
        print ("There are {0} sentences in {1}".format(count,a_filename) )