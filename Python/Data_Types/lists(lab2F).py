#   Name: William Kreiser
#   Date: 5 Sep 18
#   Project: Lab 2F "Man a Rag"

"""Instructions:
    1. Write a program that will be able to check if two words (strings) are anagrams.
    2. An anagram is a word or phrase formed by rearranging the letters of a different word or phrase

    The program should include:
        1. All proper comments
        2. Needed docstrings
        3. User input (only expecting one user input due to not having gone over loops yet)"""
#User input
string1 = raw_input("Enter a word: ")
string2 = raw_input("Another word: ")

#Solution comparing two words
def isAnagram(s1,s2):
    alist2 = sorted(s2)
    alist1 = sorted(s1)

    if (alist1 == alist2):
        print "The words are anagrams."
    else:
        print "The two words are not anagrams."
    return

#Solution checking each character
def anagramSolution1(s1,s2):
    alist = list(s2)

    pos1 = 0
    stillOK = True

    while pos1 < len(s1) and stillOK:
        pos2 = 0
        found = False
        while pos2 < len(alist) and not found:
            if s1[pos1] == alist[pos2]:
                found = True
            else:
                pos2 = pos2 + 1
        if found:
            alist[pos2] = None
        else:
            stillOK = False

        pos1 = pos1 + 1

    return stillOK

#Solution comparing two words
isAnagram(string1, string2)

#Solution checking each character
print(anagramSolution1(string1, string2))

# Split on " ", sort both parts, compare    Burright's Solution
print "Anagram result:", ''.join(sorted(string1)) == ''.join(sorted(string2))
