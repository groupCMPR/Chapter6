#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class bagOfInts
{
private:
	vector<int> myVec;

public: 
	//Default constructor 
	bagOfInts();
	//to clear contents
	void clear();
	//to return size
	int mySize();
	//returns true/false if empty
	bool empty();
	//inserts int
	void insert(int);
	//looks for int
	void search(int) const;
	//deletes certain value
	void remove(int&);
	//sorts content
	void mySort();
	//displays content
	void display();
};

