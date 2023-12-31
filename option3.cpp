//Names: Alexis Martinez,Neidy Malaga, & Vivian Huynh
//Group 1: Alexis
//Group 2: Neidy
//Group 3: Angie and Vivian
//Vivian organized the main.cpp base. Alexis helped with Group 2 corrections.
//Date: 10/4/2023
//Description: Chapter 6 Assignments: Software Development with Templates, Iterators, and the STL
//We created a container using a dynamic array and templates. The template allows for us to use different data types into our functions.
//We created the bag using a normal class and a template class. We then read into files and used both those classes
//to store any valid data types.

#include <iostream> //For cout
#include <vector>   //For vector
#include <fstream>  //For files
#include <iomanip> //for setprecision

//HEADER FILES
#include "input.h" //For input validation
#include "bagOfInts.h"
#include "TemplateBag.h"
#include "Courses.h"
using namespace std;


//PROTOTYPES
int mainMenu();

//Option 1 - Non-template MyBag of integers
void option1();
char caseOneMenu();
void caseOne();
//Option 2 - Template MyBag of doubles
void option2();

//Option 3 - Application using MyBag container
void option3();

//Precondition : N/A
//Posctondition: Calls option 1, 2, and 3
int main()
{
	do
	{
		system("cls");
		switch (mainMenu())
		{
		case 0: exit(0);
		case 1: system("cls"); option1(); break;
		case 2: system("cls"); option2(); break;
		case 3: system("cls"); option3(); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}

//Precondition : Calls from main
//Posctondition: Returns integer choice
int mainMenu()
{
	cout << "\n\tCMPR131 Chapter 6: non-template and template Container by Group 5 () 10/4/2023";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Non-template MyBag container of int";
	cout << "\n\t\t2> Template MyBag<double> container";
	cout << "\n\t\t3> Application using MyBag container";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0. Exit";
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

void option1()
{
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
			int numToDelete = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted: ", 0, myBag.mySize() - 1);
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

//precondition: called from main
//postcondition: clears vector, inserts, searches, removes, sorts, and displays
void option2()
{
	MyBag<double, size_t> bag2;

	do
	{
		cout << "\n\t2> Template MyBag of doubles";
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

		switch (inputChar("\n\t\tOption: ", static_cast<string>("0ABCDEF")))
		{
		case '0': return;
		case 'A': bag2.set_Clear(); cout << "\n\t MyBag is cleared of all elements."; break;
		case 'B': {
			double user_Value = inputDouble("\n\tEnter a value and insert into MyBag: ");
			bag2.set_Insert(user_Value);
			cout << "\n\t" << user_Value << " has been inserted into MyBag";
		} break;
		case 'C': {
			if (bag2.get_Empty()) {
				cout << "\n\tMyBag is empty";
				break;
			}

			double user_Value = (inputDouble("\n\tEnter a value to search from MyBag: ")) * 1.00;
			size_t position = bag2.get_Search(user_Value);

			//if not found, it will be a -1, else prints where it was found
			if (position == -1)
				cout << "\n\tValue " << user_Value << " is not found from MyBag";
			else
				cout << "\n\tValue " << *bag2.get_Value(position) << " is found at subscript #" << position << " from MyBag";
		} break;
		case 'D': {
			if (bag2.get_Empty()) {
				cout << "\n\tMyBag is empty";
				break;
			}

			//must use static cast so that inputInteger knows data type
			double user_Index = inputInteger("\n\tEnter an index(subscript) from MyBag to be deleted: ", 0, static_cast<int>(bag2.get_Size() - 1));
			cout << "\n\tValue " << *bag2.get_Value(user_Index) << " has been deleted from MyBag";
			bag2.set_Remove(user_Index);

		}break;
		case 'E': {
			if (bag2.get_Empty()) {
				cout << "\n\tMyBag is empty";
				break;
			}

			bag2.set_Sort();
			cout << "\n\tMybag has been sorted.";

		} break;
		case 'F': {
			if (bag2.get_Empty()) {
				cout << "\n\tMyBag is empty";
				break;
			}

			cout << "\n\tMyBag contains these integers:" << bag2;
		} break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");

	} while (true);
}

void option3()
{
	MyBag<Courses, size_t> bag3;
	int numberCourse = 0;
	Courses* studentRecord = NULL;
	string fileName = "";
	fstream inputFile;

	do
	{
		cout << "\n\t2> Courses using MyBags of integers, strings, doubles, and chars";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\t1> Specify the number of courses";	          //TODO
		cout << "\n\t\t2> Read in data file and insert into courses"; //TODO
		cout << "\n\t\t3> Search for a student record from a course";
		cout << "\n\t\t4> Remove a student record from a course";
		cout << "\n\t\t5> Display course(s)";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(100, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 5))
		{
		case 0: delete[] studentRecord; return;
		case 1: {
			numberCourse = inputInteger("\n\t1> Enter the number of courses: ", 1, true);
			cout << "\n\t" << numberCourse << " Course(s) has been created.\n";
			studentRecord = new Courses[numberCourse];
		}break;
		case 2: {

			if (numberCourse <= 0)
			{
				cout << "\n\tERROR: number of courses has not been assigned.\n";
				break;
			}

			for (int i = 0; i < numberCourse; i++)
			{
				fileName = inputString("\n\t2> Enter a data file name for course[" + to_string(i) + "] (STOP - return) : ", false);

				if (fileName == "STOP" || fileName == "stop")
				{
					return;
				}

				inputFile.open(fileName);

				while (inputFile.fail())
				{
					cout << "\n\tfile, " << fileName << ", cannot be found. Please re-specify.\n";
					inputFile.close();
					fileName = inputString("\n\t2> Enter a data file name for course[" + to_string(i) + "] (STOP - return) : ", false);
					if (fileName == "STOP" || fileName == "stop")
					{
						return;
					}
					inputFile.open(fileName);
				}

				string line = "";
				string title = "";
				int count = 0;
				int temp = 0;
				const int SIZE = 3; //contains the 3 elements in file
				string tokenize[SIZE];

				while (getline(inputFile, line))
				{
					if (temp == 0)
					{
						studentRecord->setTitle(line);
						temp++;
						continue;
					}

					istringstream stream(line);
					for (int i = 0; i < SIZE; i++)
					{
						getline(stream, tokenize[i], ','); //TODO
					}

					studentRecord[count].setStudentId(stod(tokenize[0]));
					studentRecord[count].setName(tokenize[1]);
					studentRecord[count].setScore(stod(tokenize[2]));
					count++;
				}

				bag3.set_Insert(*studentRecord);

				cout << "\n\tData from file, " << fileName << ", has been read and stored into Courses[" << i << "].\n";
				fileName = "";

				inputFile.close();
			}

		}break;
		case 3: {
			if (inputFile.fail())
			{
				cout << "\n\tERROR: No data file has been read and stored into Courses.\n";
				break;
			}

			cout << "\n\t\t3> Search by";
			cout << "\n\t\t" << string(30, char(196));
			cout << "\n\t\t\t1. ID Number";
			cout << "\n\t\t\t2. Name";
			cout << "\n\t\t\t0. return";
			cout << "\n\t\t" << string(30, char(196));

			switch (inputInteger("\n\t\t\tOption: ", 0, 2))
			{
			case 0: break;
			case 1: {
				/// ID number here ---
				//cout << "\n\tEnter a student ID to search: ";

				int userSearch = inputInteger("\n\tEnter a student ID to search: ",1,99999);
				
				//size_t position = bag3.get_Search(userSearch);

				//if not found, it will be a -1, else prints where it was found
				//if (position == -1)
					cout << "\n\tID: " << userSearch << " is not found from MyBag";
				//else
					cout << "\n\tID: " << userSearch << "has been found in Course: ";  // Need the tittle name;


			}break;
			case 2: {
				// Student name here ---
				//cout << "\n\tEnter a student name to search: ";

				string userSearch = inputString("\n\tEnter a student name to search : ", " ");
				//size_t position = bag3.get_Search(userSearch); 

				//if not found, it will be a -1, else prints where it was found
				//if (position == -1)
					cout << "\n\tStudent Name: " << userSearch << " is not found from MyBag";
				//else
					cout << "\n\tStudent Name: " << userSearch << "has been found in Course: ";  // Need the tittle name;

			}break;
			default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
			}
		}break;
		case 4: {
			if (inputFile.fail())
			{
				cout << "\n\tERROR: No data file has been read and stored into Courses.\n";
				break;
			}


			//menu based on the courses selected 
			while (true) {
				cout << "4> Course(s) " << endl;
				cout << "\n\t" << string(100, char(205));

				for (int i = 0; i < numberCourse; i++)
				{
					cout << i + 1 << ": " << studentRecord[numberCourse].getTitle();
				}
				cout << "\n\t" << string(100, char(205));
			}
			//---------------------
			// how to search and remove here 
			int userSearchandRemove = inputInteger("\n\tEnter a student ID to search and delete:", 1, 99999);

			cout << "\n\tStudent ID "; *bag3.get_Value(userSearchandRemove); " has been deleted from MyBag";
			bag3.set_Remove(userSearchandRemove);

		}break;
		case 5: {
			if (inputFile.fail())
			{
				cout << "\n\tERROR: No data file has been read and stored into Courses.\n";
				break;
			}
			// menu of course selected 
			while (true) {
				cout << "Course(s)" << endl;
				cout << "\n\t" << string(100, char(205));

				for (int i = 0; i < numberCourse; i++)
				{
					cout << i + 1 << ": " << studentRecord[numberCourse].getTitle();

				}
				cout << "3 : All\n";
				cout << "\n\t" << string(100, char(205));
				
			}

			// --- 
			//here display 
			cout << studentRecord->getTitle() << endl;

			cout << "index\tStudentID\tName\t\tScore\tGrade" << endl;

			for (int i = 0; i < studentRecord.size(); i++)
			{
				cout << setw(6) << numberCourse << i << "\t";
				cout << setw(10) << studentRecord[i].getStudentId << "\t";
				cout << setw(10) << studentRecord[i].getName << "\t";
				cout << setw(10) << studentRecord[i].getScore << "\t";
				cout << setw(10) << studentRecord[i].getLetterGrade << "\t";
			}



		}break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");

	} while (true);
}
