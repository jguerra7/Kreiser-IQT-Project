#include "person.h"

int log_roster(std::vector<Person>&, std::ofstream&);
int generate_roster(std::vector<Person>&);

int main()
{
	std::ofstream outfile("roster.txt");
	std::vector<Person> roster;
	
	int roster_size = generate_roster(roster);
	int logged_count = log_roster(roster, outfile);

	if (roster_size == logged_count)
		std::cout << "Roster logged successfully";
	else
		std::cout << "Roster size and logged count mismatch. Error!" << std::endl;

	roster.clear();
	outfile.close();

	return 0;

}
//Arguments: std::vector<person>& roster - reference a vector containing the list of students in the class
//           std::ofstream& - a reference to the ofstream outfile object you will write too 
//Returns:  int count of the number of records written out 
//Purpose: write out the logic
int log_roster(std::vector<Person>& roster, std::ofstream& outfile)
{
	int number_of_written = 0;
	int maxNum;	

	maxNum = roster.size();

	for (int i = 0; i < maxNum; i++)
	{
		if (outfile.is_open())
		{
			outfile << roster[i].getFirstName() << " " << roster[i].getLastName() << " " << roster[i].getGender() << " " << roster[i].getAge() << std::endl;
			number_of_written++;
		}
	}
	return number_of_written;
}

//Arguments: std::vector<Person>& roster - a reference to a vector that will contain the students you input 
//Returns: int count of the number of records input 
//Purpose: receive input and load the vector 
int generate_roster(std::vector<Person>& roster)
{
	int number_of_records = 0;	//return value 
	int	number_of_students = 0;	//number of students to add
	//temp variables to store user input and add to roster
	std::string firstname, lastname;
	char gender = '?';
	int age = 0;
	//Person object that will be added to roster
	Person student(firstname, lastname, gender, age);

	std::cout << "How many students do you have to enter? ";
	std::cin >> number_of_students;
	std::cin.ignore();

	for (int i = 1; i <= number_of_students; i++)
	{	
		std::cout << "Enter the first name of the person you would like to add: " ;
		std::getline(std::cin, firstname);

		std::cout << "Enter the last Name of the person you would like to add: ";
		std::getline(std::cin, lastname);		
		
		std::cout << "Enter the age of the person you would like to add: " ;
		std::cin >> age;
		
		std::cout << "Enter the gender of the person you would like to add: ";
		std::cin >> gender;	
		std::cin.ignore();

		//Push our temp values into the student object
		student.setFirstName(firstname);
		student.setLastName(lastname);
		student.setAge(age);
		student.setGender(gender);

		roster.push_back(student);
		number_of_records++;
	}

	return number_of_records;
}