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
	MyBag() {
		bag_size = 0;
		bag_capacity = 0;
		bag_ptr = bag.begin();
	}

	//================================================
	//				Mutators
	//================================================

	//precondition: initialized vector
	//postcondition: clears vector, resets size
	void set_Clear() {
		bag.clear();
		bag_size = 0;
	}

	//precondition: data type newData, initialized vector
	//postcondition: inserts newData, readjust size
	void set_Insert(const value_vector& newData) {
		bag.push_back(newData);
		bag_size = bag.size();
	}

	//precondition: valid index, filled vector
	//postcondition: erases at index, readjust size
	void set_Remove(const value& index) {
		bag_ptr = bag.begin() + index;
		bag.erase(bag_ptr);
		bag_size = bag.size();
	}

	//precondition: filled vector
	//postcondition: sorts elements 
	void set_Sort() {
		sort(bag.begin(), bag.end());
	}

	//precondition: initialized vector
	//postcondition:  clears and resizes vector, adjusts capacity and size
	void set_Resize(const value& newSize) {
		bag.clear();
		bag.resize(newSize);
		bag.shrink_to_fit();
		bag_size = 0;
		bag_capacity = bag.capacity();
	}

	//================================================
	//				Accessor
	//================================================

	//precondition: N/A
	//postcondition: returns bag_size
	value get_Size() {
		return bag_size;
	}

	//precondition: N/A
	//postcondition: returns bag_capacity
	//Notice: used to control how many elements can be inserted
	value get_Capacity() {
		return bag_capacity;
	}

	//precondition: filled vector, newValue with same data type
	//postcondition: returns position or -1 (if no position) after searching
	value get_Search(const value_vector& newValue) const {
		for (int i = 0; i < bag_size; ++i) {
			if (bag.at(i) == newValue)
				return i;
		}

		return -1;
	}

	//precondition: filled vector
	//postcondition: returns pointer at index
	typename vector<value_vector>::const_iterator get_Value(const value& index) const{
		auto ptr = bag.begin() + index;
		return ptr;
	}

	//precondition: filled vector, outsream, class object
	//returns outsream
	friend ostream& operator<<(ostream& out, const MyBag& obj) {
		for (int i = 0; i < obj.bag_size; ++i)
			out << "\n\t[" << i << "] -" << obj.bag.at(i);

		return out;
	}
};
