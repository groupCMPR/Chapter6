#pragma once
#include <string>
#include <iostream>
using namespace std;

class Courses
{
private:
	int studentId;
	string name;
	double score;
	char letterGrade;

public: 
	//CONSTRUCTOR
	Courses();

	//ACCESSORS
	int getStudentId() const;
	string getName() const;
	double getScore() const;
	char getLetterGrade() const;

	//MUTATORS
	void setStudentId(int);
	void setName(string);
	void setScore(double);
	void setLetterGrade(char);
};

