//Name: Angie Campos & Vivian Huynh
//Date: 10/11/2023
//Description: Header file for class Courses

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Courses
{
private:
	string title;
	int studentId;
	string name;
	double score;
	char letterGrade;

public: 
	//CONSTRUCTOR
	Courses();

	//ACCESSORS
	string getTitle() const;
	int getStudentId() const;
	string getName() const;
	double getScore() const;
	char getLetterGrade() const;

	//MUTATORS
	void setTitle(string);
	void setStudentId(int);
	void setName(string);
	void setScore(double);
};
