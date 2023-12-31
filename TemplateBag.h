//Name: Neidy Malaga
//Date: 10/7/2023
//Description: Header file for class MyBag in template 

#pragma once
#include <vector>    //For vector
#include <iostream>  //For overloading <<
#include <algorithm> //For sort

using namespace std;

template <typename value_vector, typename value>
class MyBag
{
private:
	vector<value_vector> bag;
	typename vector<value_vector>::const_iterator bag_ptr;
	value bag_size;
	value bag_capacity;

public:
	//default contructor
	MyBag();

	//Mutators
	void set_Clear();
	void set_Insert(const value_vector&);
	void set_Remove(const value&);
	void set_Sort();
	void set_Resize(const value&);

	//Accessors
	value get_Size() const;
	value get_Capacity() const;
	value get_Search(const value_vector&) const;
	bool get_Empty() const;
	typename vector<value_vector>::const_iterator get_Value(const value&) const;

	//Friend
	friend ostream& operator<< (ostream& out , const MyBag<value_vector, value>& obj) {
		for (int i = 0; i < obj.get_Size(); ++i)
			out << "\n\t[" << i << "] - " << *obj.get_Value(i);
		return out;
	}



};
