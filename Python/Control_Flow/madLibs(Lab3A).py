#   Name: William Kreiser
#   Date: 6 Sep 18
#   Project: Mad Libs(Lab3A)

"""
Background
"Mad Libs is a phrasal template word game where one player prompts others for a list of words to substitute for blanks in a story, 
before reading the – often comical or nonsensical – story aloud. The game is frequently played as a party game or as a pastime."

Requirments:
Adhere to PEP8 (Comments, formatting, style, etc)
Create a handfull of pharses that require different numbers of inputs
Prompt the user for input(s):
    Inputs can be done a number of ways...
        (SIMPLE) Ask user for input directly, tell them if the word(s) need to be a verb, noun, etc.
        (Moderate) Give the user a handful of choices per input to choose from.You will need to create a bank of verbs, nouns, etc for this.
        (Harder) Give the user cards based off the actual game. Allowing them to draw, etc following the rules. Allow them to only input those cards.
    (optional) Implement basic user input checking:
        Check to ensure words are words, numbers are numbers (there are many ways to do this)
        Ensure symobls aren't used if they are not needed
        Check length
        etc
        Implement re-input if input is incorrect
Output the user inputs into the given pharse
Use formatting to not only output the user inputs, but to create a UI within the terminal. 
Space out certain UI elements such as title of program, choices, menu deceration, etc.
"""
import random
import string

#This function will provide the bank of nouns for user selection
def printNouns():
    noun_string = "I You Grandma Grandpa Cat Python Meteor Dragon Ostrich Everything Mind Snake"
    noun_list = noun_string.split(" ")
    print "Here is a list of nouns: "
    for noun in noun_list:
        print noun
    print "-------------------\n"
    noun = raw_input("Please select a noun: ")
    if noun in noun_list:
        return noun

#This function will provide the bank of nouns for user selection
def printVerbs():
    verb_string = "running flipping skipping throwing riding stomping spear-fishing lost dropped "
    verb_list = verb_string.split(" ")
    print "Here is a list of verbs: "
    for verb in verb_list:
        print verb
    print "-------------------\n"
    verb = raw_input("Please select a verb: ")
    if verb in verb_list:
        return verb
    


#This function will provide a random sentence for the user to select words to put in
def printRandomSentence():
    
    sentence = random.randint(1, 4)
    if sentence == 1:
        sentence = "Why is a Noun Verb through the house, destroying Noun in their path."
        return sentence
    elif sentence == 2:
        sentence = "Noun have you completely Verb your Noun."
        return sentence
    elif sentence == 3:
        sentence = "That's it. Now i have to kill a Noun while Verb on a Noun."
        return sentence
    elif sentence == 4:
        sentence = "Well, now that i killed the Noun that the Noun was Verb on, I must bury the Noun."
        return sentence
    

print """___       ___              ___       ____        ___                
`MMb     dMM'              `MM       `MM'     68b MM                
 MMM.   ,PMM                MM        MM      Y89 MM                
 M`Mb   d'MM    ___     ____MM        MM      ___ MM____     ____   
 M YM. ,P MM  6MMMMb   6MMMMMM        MM      `MM MMMMMMb   6MMMMb\ 
 M `Mb d' MM 8M'  `Mb 6M'  `MM        MM       MM MM'  `Mb MM'    ` 
 M  YM.P  MM     ,oMM MM    MM        MM       MM MM    MM YM.      
 M  `Mb'  MM ,6MM9'MM MM    MM        MM       MM MM    MM  YMMMMb  
 M   YP   MM MM'   MM MM    MM        MM       MM MM    MM      `Mb 
 M   `'   MM MM.  ,MM YM.  ,MM        MM    /  MM MM.  ,M9 L    ,MM 
_M_      _MM_`YMMM9'Yb.YMMMMMM_      _MMMMMMM _MM_MYMMMM9  MYMMMM9"""

print """\n\n Mad Libs books contain short stories on each page with many key words replaced with blanks. 
Beneath each blank is specified a lexical or other category, such as "noun", "verb", "place", or "part of the body".
One player asks the other players, in turn, to contribute a word of the specified type for each blank, 
but without revealing the context for that word. Finally, the completed story is read aloud. 
The result is usually comic, surreal and somewhat nonsensical.\n\n"""

sentence = printRandomSentence()

if sentence:
    print sentence
    newSentence = sentence
    while "Noun" or "Verb" in newSentence:
        if "Noun" in newSentence:
            noun = printNouns()
            count = newSentence.count('Noun')
            newSentence = sentence.replace('Noun', noun.rstrip(), 1)
        elif "Verb" in newSentence:
            verb = printVerbs()
            newSentence = sentence.replace('Verb', verb.rstrip())
        print newSentence














