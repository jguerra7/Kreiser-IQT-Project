#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class Person
{
private:
	std::string firstName;
	std::string lastName;
	char gender;
	int age;
public:
	Person(std::string firstName, std::string lastName, int age, char gender)
	{
	this->firstName = firstName;
	this->lastName = lastName;
	this->gender = gender;
	this->age = age;
	}
	~Person()
	{

	}
	std::string getFirstName()
	{
		return firstName;
	}
	std::string getLastName()
	{
		return lastName;
	}
	int getAge()
	{
		return age;
	}
	char getGender()
	{
		return gender;
	}
	void setFirstName(std::string firstname)
	{
		this->firstName = firstname;
	}	
	void setLastName(std::string lastname)
	{
		this->lastName = lastname;
	}	
	void setGender(char gender)
	{
		if (gender == 'M' || gender == 'F' || gender == 'm' || gender == 'f')
			this->gender = gender;
		else
			this->gender = '?';
	}	
	void setAge(int age)
	{
		if (age > 0 && age < 120)
			this->age = age;
		else
			this->age = 0;
	}
};

