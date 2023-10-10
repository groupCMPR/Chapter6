#pragma once
#include <vector> //for vector
#include <iostream> //for overloading <<
#include <algorithm> //for find, search, sort
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

	////Accessor
	value get_Size();
	value get_Capacity();
	value get_Search(const value_vector&) const;
	typename vector<value_vector>::const_iterator get_Value(const value&) const;

	//friend
	friend ostream& operator<<(ostream&, const MyBag<value_vector, value>& obj);


};
