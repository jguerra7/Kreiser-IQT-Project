#!/usr/bin/env python
# Name: William Kreiser
# Date: 9 Oct 18
# Project: Python Eval
import os, glob, subprocess

"""
# Given a list of strings (['string1', 'string2', 'string3']), reverse all of the characters, and
# join them all together into a single string, with each previous word separated by spaces
# (the above example becomes '1gnirts 2gnirts 3gnirts')
"""
def first_test(string_list):
    #Temp list to hold reversed string list
    return_list = []
    #iterate through string_list and reverse everything
    for string in string_list: 
        new_string = string[::-1]
        #store
        return_list.append(new_string)
    #Join the list with a space
    return_list = " ".join(return_list)

    return return_list

"""
# Given a directory path, find each file that ends with '.txt', and create a dictionary,
# where each element consists of the filename, and its contents (e.g., if we had a file called
# "foo.txt" that contained "AAAA", our dictionary would look like: 
# { "evalFolder\\foo.txt" : "AAAA" }). This dictionary will be our return item.
"""
def third_test(fname):

    #Dictionary to hold fname and fname data
    testDict = {}
    for i in fname:
        #Read in the data
        fileContents = open(i, "r")
        #Temp variable to hold fname contents
        data = fileContents.read()
        #Store the file contents in the dictionary
        testDict[i] = data
        #Close the file
        fileContents.close()
    return testDict

#Variables and Function call for First Test
string_list = ["String1", "String2", "String3"]
new_string = first_test(string_list)
print new_string

#Variables and Function call for Third Test
fileDict = {}
directoryList = []
#Search directory for all files with .txt extension
for name in glob.glob('C:\IQTRepo\Project\PythonEval\evalFolder\*.txt'):
    directoryList.append(name)    
#Run Third test using the directory_list
fileDict = third_test(directoryList)
print fileDict
