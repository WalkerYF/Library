#include <iostream>
#include <string>
#include "Library.h"
using std::string;

//#define NUM 2000000000



int main()
{
	using namespace std;
	cout << "*************************************************************" << endl;
	cout << "***      Welcome to the Book Managerment System.          ***" << endl;
	cout << "*** Before you use these system,                          ***" << endl;
	cout << "*** Please read these instructions carefully.             ***" << endl;
	cout << "***   a):   add a book                                    ***" << endl;
	cout << "***   d):   delete a book                                 ***" << endl;
	cout << "***   b):   borrow a book                                 ***" << endl;
	cout << "***   r):   return a book                                 ***" << endl;
	cout << "***   f):   view a book                                   ***" << endl;
	cout << "***   p):   view all books                                ***" << endl;
	cout << "***   q):   quit this system                              ***" << endl;
	cout << "***                                                       ***" << endl;
	cout << "***                            All Copyright by Walker.   ***" << endl;
	cout << "*************************************************************" << endl;
	//cout << "Now, we will give you several soconds to read these instructions." << endl;
	//for (int i = 0; i < NUM; i++) {};
	cout << endl;
	cout << "Ok, now you have read these instructions." << endl;
	cout << "Please enter carriage return to continue......." << endl;
	while (cin.get() != '\n')
		continue;
	string choice;
	Library library;

	cout << "Now please enter your choice" << endl;

	while ( cin >> choice && choice != "q")
	{
		while (cin.get() != '\n')
			continue;
		switch (choice[0])
		{
		case 'a':
		{
			library.add_book();
			break;
		}
		case 'd':
		{
			library.delete_book();
			break;
		}
		case 'b':
		{
			library.borrow_book();
			break;
		}
		case 'r':
		{
			library.return_book();
			break;
		}
		case 'f':
		{
			library.find_book();
			break;
		}
		case 'p':
		{
			library.print_book();
			break;
		}
		default:
		{
			cout << "Your commamd is invalid." << endl;
			cout << "Please enter the command again." << endl;
			cout << endl;
			break;
		}
		}

		cout << "If you want to continue,please enter your command." << endl;
		cout << "If you enter 'q', you will quit this system." << endl;

	}
	cout << endl;
	cout << "You has quited this system." << endl;
	cout << "Please enter carriage return to continue......." << endl;
	cin.get();
	cin.get();
	return 0;
}
