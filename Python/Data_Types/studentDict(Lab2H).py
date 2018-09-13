#   Name: William Kreiser
#   Date: 6 Sept 18
#   Project: Student Dictionary

"""
Lab 2H
1. Create a program that takes input of a group of students' names and grades.
2. Then sorts them based on highest to lowest grade. 
3. Calculate and print the sorted list and the average for the class. (Hint: Use Dictionaries!)
"""

#Main dictionary to hold others
student_database = {} 

def grade(grade_iter):
    #This loop takes in the grades and stores them in a tuple
    average = 0
    for j in range(int(grade_iter)):
        new_grade = raw_input("Enter a grade: ").rstrip()   
        student_database[new_student] = int(new_grade)            
        average += int(new_grade)
        j +=1

student_name = list()
#loop to populate the student_name dictionary
students = raw_input("How many students do you need to add? ")
grade_iter = raw_input("How many grades do you need to enter? ")
for i in range (int(students)): 
    new_student = raw_input("Enter your first and last name: ").rstrip()
    student_name.append(new_student.rstrip())  
    grade(grade_iter)

sorted_db = sorted(student_database, key=student_database.get, reverse=True)
for v in sorted_db:
    print v, ":", student_database[v]

print "The class average is: ".format(len(student_database), sum//len(student_database))