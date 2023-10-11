#include <iostream>
#include "input.h"
#include "bagOfInts.h"

using namespace std;

int mainMenu();
char caseOneMenu();
void caseOne();

int main() {

	do {
		system("cls");
		switch (mainMenu()) {
		case 0: return EXIT_SUCCESS;
		case 1: caseOne(); break;

		default: cout << "\n\tERROR - INVALID CHOICE";
		}
		cout << "\n\n\t";
		system("pause");
	} while (true);
	return EXIT_SUCCESS;
}
//PreCondition: None
//PostCondition: Displays a menu and returns an integer
int mainMenu() {
	cout << "\n\tCMPR131 Chapter 6: non-template and template Container";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Non-template MyBag container of int";
	cout << "\n\t\t2> Template MyBag<double> container";
	cout << "\n\t\t3> Application using MyBag container";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	
	return inputInteger("\n\t\tOption: ", 0, 3);
}
//PreCondition: None 
//PostCondition: Displays a menu and returns a char
char caseOneMenu() {
	cout << "\n\t1> Non-template MyBag of integers";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA> clear";
	cout << "\n\t\tB> insert";
	cout << "\n\t\tC> search";
	cout << "\n\t\tD> remove";
	cout << "\n\t\tE> sort";
	cout << "\n\t\tF> display";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(100, char(205));
	
	return inputChar("\n\t\tOption: ", static_cast<string>("ABCDEF0"));
}
//PreCondition: None 
//PostCondition: Performs an action based on user choice
void caseOne() {
	bagOfInts myBag;

	do {
		system("cls");
		switch (caseOneMenu()) {
		case '0': return; break;
		case 'A': 
			myBag.clear(); 
			cout << "\n\t\tMyBag is cleared of all elements.";
			break;
		case 'B': {
			int number = inputInteger("\n\t\tEnter a value and insert into MyBag: ");
			myBag.insert(number);
			cout << "\n\t\t" << number << " has been inserted into MyBag.";
			break;
		}
		case 'C': {
			if (myBag.empty()) {
				cout << "\n\t\tMyBag is empty.";
				break;
			}
			int value = inputInteger("\n\t\tEnter a value to search from MyBag: ");
			myBag.search(value);
			break;
		}
		case 'D': {
			if (myBag.empty()) {
				cout << "\n\t\tMyBag is empty.";
				break;
			}
			int numToDelete = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted: ", 0 , myBag.mySize() - 1);
			myBag.remove(numToDelete);
			break;
		}
		case 'E':
			if (myBag.empty()) {
				cout << "\n\t\tMyBag is empty.";
				break;
			}
			myBag.mySort();
			break;
		case 'F':
			if (myBag.empty()) {
				cout << "\n\t\tMyBag is empty.";
				break;
			}
			myBag.display();
			break;
		}
		cout << "\n\n\t";
		system("pause");
	} while (true);
}