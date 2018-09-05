def wordCount(mystring):  
    tempcount = 0  
    count = 1
    try:  
        for character in mystring:  
            if character == " ":  
                tempcount +=1  
                if tempcount == 1:  
                    count +=1  
                else:
                    tempcount+=1
            else:
                tempcount = 0
        return count  

    except Exception:  
        error = "Not a string"  
        return error    

myString = raw_input("Enter whatever you wish: \n")
print(wordCount(myString))

user_input = raw_input("Please input a string: ")
print "The sentence input was: {}".format(user_input)
length = len(user_input.split(" "))
print "The number of words in the sentence is {}".format(length)