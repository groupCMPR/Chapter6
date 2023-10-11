//Name: Neidy Malaga
//Date: 10/7/2023
//Description: cpp file for class MyBag in template 

#include "TemplateBag.h"

//default constructor
//precondition : N/A
//postcondition: initialize the private members
template <typename value_vector, typename value>
MyBag<value_vector, value>::MyBag() {
	bag_size = 0;
	bag_capacity = 0;
	bag_ptr = bag.begin();
}

//================================================
//				Mutators
//================================================

//precondition : initialized vector
//postcondition: clears vector, resets size
template <typename value_vector, typename value>
void MyBag<value_vector, value>::set_Clear() {
	bag.clear();
	bag_size = 0;
}

//precondition : data type newData, initialized vector
//postcondition: inserts newData, re-adjust size
template <typename value_vector, typename value>
void MyBag<value_vector, value>::set_Insert(const value_vector& newData) {
	bag.push_back(newData);
	bag_size = bag.size();
}

//precondition : valid index, filled vector
//postcondition: erases at index, re-adjust size
template <typename value_vector, typename value>
void MyBag<value_vector, value>::set_Remove(const value& index) {
	bag_ptr = bag.begin() + index;
	bag.erase(bag_ptr);
	bag_size = bag.size();
}

//precondition : filled vector
//postcondition: sorts elements 
template <class value_vector, class value>
void MyBag<value_vector, value>::set_Sort() {
	sort(bag.begin(), bag.end());
}

//precondition : initialized vector
//postcondition: clears and resizes vector, adjusts capacity, and size
template <typename value_vector, typename value>
void MyBag<value_vector, value>::set_Resize(const value& newSize) {
	bag.clear();
	bag.resize(newSize);
	bag.shrink_to_fit();
	bag_size = 0;
	bag_capacity = bag.capacity();
}

//================================================
//				Accessors
//================================================

//precondition : N/A
//postcondition: returns bag_size
template <typename value_vector, typename value>
value MyBag<value_vector, value>::get_Size() const{
	return bag_size;
}

//precondition : N/A
//postcondition: returns bag_capacity
//Notice: used to control how many elements can be inserted
template <typename value_vector, typename value>
value MyBag<value_vector, value>::get_Capacity() const {
	return bag_capacity;
}

//precondition : filled vector, newValue with same data type
//postcondition: returns position or -1 (if no position) after searching
template <typename value_vector, typename value>
value MyBag<value_vector, value>::get_Search(const value_vector& newValue) const {
	for (int i = 0; i < bag_size; ++i) {
		if (bag.at(i) == newValue)
			return i;
	}
	return -1;
}

//precondition : filled vector
//postcondition: returns pointer at index
template <typename value_vector, typename value>
typename vector<value_vector>::const_iterator MyBag<value_vector, value>::get_Value(const value& index) const {
	auto ptr = bag.begin() + index;
	return ptr;
}

template class MyBag<double, size_t>;
