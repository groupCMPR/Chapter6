#include "bagOfInts.h"
//default 
bagOfInts::bagOfInts() {}
//returns true/false if empty
bool bagOfInts::empty() {
	return myVec.empty();
}
//to return size
int bagOfInts::mySize() {
    return myVec.size();
}
//to clear contents
void bagOfInts::clear() {
	myVec.clear();
}
//inserts int
void bagOfInts::insert(int numToInsert) {
	myVec.push_back(numToInsert);
}
//looks for int
void bagOfInts::search(int numToFind) const {

	for (int i = 0; i < myVec.size(); i++) {
		if (myVec[i] == numToFind) {
			cout << "\n\t\tValue " << numToFind << " is found at subscript #" << i << " from MyBag.";
			return;
		}
	}
	cout << "\n\t\tValue " << numToFind << " is not found from MyBag.";
   
}
//deletes certain value
void bagOfInts::remove(int& index)  {
    cout << "\n\t\tValue " << myVec.at(index) << " has been deleted from MyBag.";
	myVec.erase(myVec.begin() + index);	
}
//sorts content
void bagOfInts::mySort() {
	sort(myVec.begin(), myVec.end());
}
//displays content
void bagOfInts::display() {
	for (int i = 0; i < myVec.size(); i++) {
		cout << "\n\t\t[" << i << "] - " << myVec[i];
    }
}