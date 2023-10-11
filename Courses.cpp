#include "Courses.h"
Courses::Courses() : studentId(0), name("Unknown"), score(0.0), letterGrade('F')
{}

//ACCESSORS
int Courses::getStudentId() const
{
	return studentId;
}
string Courses::getName() const
{
	return name;
}
double Courses::getScore() const
{
	return score;
}
char Courses::getLetterGrade() const
{
	return letterGrade;
}

//MUTATORS
void Courses::setStudentId(int newStudentId)
{
	studentId = newStudentId;
}
void Courses::setName(string newName)
{
	name = newName;
}
void Courses::setScore(double newScore)
{
	score = newScore;
}
void Courses::setLetterGrade(char newLetterGrade)
{
	if (score > 89)
	{
		newLetterGrade = 'A';
	}
	else if (score > 79)
	{
		newLetterGrade = 'B';
	}
	else if (score > 69)
	{
		newLetterGrade = 'C';
	}
	else if (score > 59)
	{
		newLetterGrade = 'D';
	}
	else
	{
		newLetterGrade = 'F';
	}
	letterGrade = newLetterGrade;
}
