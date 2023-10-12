//Name: Angie Campos & Vivian Huynh
//Date: 10/11/2023
//Description: cpp file for class Courses

#include "Courses.h"

//Precondition : N/A
//Postcondition: Initialize the private members
Courses::Courses() : title(""), studentId(0), name("Unknown"), score(0.0), letterGrade('F')
{}

//==========================================================
// Accessors Section
//==========================================================
//Precondition : N/A
//Postcondition: Return private member title
string Courses::getTitle() const
{
	return title;
}
//Precondition : N/A
//Postcondition: Return private member studentID
int Courses::getStudentId() const
{
	return studentId;
}
//Precondition : N/A
//Postcondition: Return private member name
string Courses::getName() const
{
	return name;
}
//Precondition : N/A
//Postcondition: Return private member score
double Courses::getScore() const
{
	return score;
}
//Precondition : N/A
//Postcondition: Return private member letterGrade
char Courses::getLetterGrade() const
{
	return letterGrade;
}

//==========================================================
// Mutators Section
//==========================================================
//Precondition : Passing in a string
//Postcondition: Private member title is changed
void Courses::setTitle(string newTitle)
{
	title = newTitle;
}
//Precondition : Passing in int in student ID format
//Postcondition: Private member studentID is changed
void Courses::setStudentId(int newStudentId)
{
	studentId = newStudentId;
}
//Precondition : Passing in a string
//Postcondition: Private member name is changed
void Courses::setName(string newName)
{
	name = newName;
}
//Precondition : Passing in positive double values between 0.0...100.0
//Postcondition: Private member score and letterGrade is changed
void Courses::setScore(double newScore)
{
	char newLetter;
	if (newScore > 89)
	{
		newLetter = 'A';
	}
	else if (newScore > 79)
	{
		newLetter = 'B';
	}
	else if (newScore > 69)
	{
		newLetter = 'C';
	}
	else if (newScore > 59)
	{
		newLetter = 'D';
	}
	else
	{
		newLetter = 'F';
	}
	score = newScore;
	letterGrade = newLetter;
}
