#include "Library.h"
#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

int Book::seed = 0;

string change_int_to_string(int t_number)
{
	int other_digit = t_number / 10;
	int unit_digit = t_number % 10;
	if (other_digit == 0)
	{
		return string(1, char(unit_digit + 48));
	}

	return change_int_to_string(other_digit) + char(unit_digit + 48);

	//int unit_digit = t_number % 10;
	//int other_digit = t_number / 10;
	//string result = "";
	//while (other_digit)
	//{
	//	result = string(1,char(unit_digit + 48)) + result;
	//	unit_digit = other_digit % 10;
	//	other_digit = other_digit / 10;
	//}
	//result = char(unit_digit + 48) + result;
	//return result;
}


Single_Book::Single_Book(string t_id, string t_name, bool t_status = true)
{
	Id = t_id;
	Book_Name = t_name;
	book_status = t_status;
}

void Single_Book::Print() const
{
	cout << setw(8)  << Id 
		 << setw(10) << Book_Name 
		 << setw(8)  << ((book_status) ? "Yes" : "No" )
		 << endl;
}


void Single_Book::set_status()
{
	book_status = !book_status;
}


Book::Book()
{
	Book_Name = "No name.";
	Repertory_number = 0;
	Remain_number = 0;
	book_status = false;
}


Book::Book(string t_name, int t_rep_number = 0, bool t_status = false)
{
	Book_Name = t_name;
	Remain_number = Repertory_number = t_rep_number;
	book_status = t_status;
}

bool Book::is_exist(const string & t_id) const
{
	auto find_single_book = Same_Book.find(t_id);
	if (find_single_book == Same_Book.end())
	{
		cout << "This book are not exist." << endl;
		cout << endl;
		return false;
	}
	return true;
}

bool Book::is_exist_not_borrowed(const string & t_id) const
{
	auto find_single_book = Same_Book.find(t_id);
	if (find_single_book == Same_Book.end())
	{
		cout << "This book are not exist." << endl;
		cout << endl;
		return false;
	}
	else if (find_single_book->second.get_status() == false)
	{
		cout << "This book has been borrowed." << endl;
		cout << endl;
		return false;
	}
	return true;
}

bool Book::is_exist_borrowed(const string & t_id) const
{
	auto find_single_book = Same_Book.find(t_id);
	if (find_single_book == Same_Book.end())
	{
		cout << "This book are not exist." << endl;
		cout << endl;
		return false;
	}
	else if (find_single_book->second.get_status() == true)
	{
		cout << "This book has not been borrowed." << endl;
		cout << endl;
		return false;
	}
	return true;;
}

void Book::Add()
{
	if (book_status == false)
	{
		book_status = true;
	}
	Repertory_number++;
	Remain_number++;
	seed++;

	string t_id = Book_Name + change_int_to_string(seed);
	//the generation of id
	Same_Book.insert ({ t_id, Single_Book(t_id, Book_Name, true) });
} 

bool Book::can_delete_all() const
{
	if (Repertory_number == Remain_number && Remain_number == 1)
		return true;
	else
		return false;
}

bool Book::Decrease()
{
	if (Remain_number == 0)
	{
		cout << "All this kind of books has been borrowed." << endl;
		cout << "You can't delete this book" << endl;
		return false;
	}
	else 
	{
		cout << "Please write down the id of your book." << endl;
		string t_id;
		cin >> t_id;

		if (is_exist_not_borrowed(t_id))
		{
			Same_Book.erase(t_id);
			Repertory_number--;
			Remain_number--;
			cout << "This book has deleted successfully" << endl;
			cout << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Book::Borrow()
{
	if (get_status() == false)
	{
		cout << "All of this kind of books has been borrowed." << endl
			<< "You can not borrow this book." << endl;
		return false;
	}
	else
	{
		cout << "Please write down the id of your book." << endl;
		string t_id;
		cin >> t_id;

		if (is_exist_not_borrowed(t_id))
		{
			Same_Book[t_id].set_status();
			Remain_number--;
			//reflesh the status of book.
			book_status = (Remain_number) ? true : false;
			cout << "You has borrowed this book successfully!" << endl;
			cout << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Book::Return()
{
	if (Remain_number == Repertory_number)
	{
		cout << "No this kind of books has been borrowed." << endl;
		cout << endl;
		return false;
	}
	cout << "Please write down the id of your book." << endl;
	string t_id;
	cin >> t_id;

	if (is_exist_borrowed(t_id))
	{
		Same_Book[t_id].set_status();
		Remain_number++;
		book_status = true;
		cout << "You has returned this book successfully" << endl;
		cout << endl;
		return true;
	}
	else
	{
		return false;
	}

}

void Book::Print() const
{
	cout << endl;
	cout << "Book's name: " << Book_Name << endl;
	cout << setw(8)  << "id"
		 << setw(10) << "name"
		 << setw(8)  << "status" 
		 << endl;
	for (auto i : Same_Book)
		i.second.Print();
	cout << "total | remain:" 
		 << setw(5) << Repertory_number 
		 << "|" 
		 << setw(5) << Remain_number << endl;
}

bool Library::is_exist(const string & t_name) const
{
	auto find_this_book = Library_Book.find(t_name);
	if (find_this_book == Library_Book.end())
		// can not find this book, so fail to borrow this book.
	{
		cout << "This book are not exist in this library." << endl;
		cout << endl;
		return false;
	}
	return true;
}

bool Library::add_book()
{
	string t_name;
	cout << "Please write down the book name which you want to add:" << endl;
	cin >> t_name;
	if ( is_exist(t_name	)) 

	{
		cout << "This book exists." << endl;
		cout << "We will increase the number of this book." << endl;
		cout << endl;
	}

	else
	// can not find this book, so create a new kind of book object.
	{
		cout << "Add this book successfully." << endl;
		cout << endl;

		//maybe some more information.
/////////////////////////////////////////////
		//create a new ojbect.
		Library_Book[t_name] = Book(t_name);
		//debug
	}

	//increase the number of this book.
	Library_Book[t_name].Add();
	cout << endl;
	return true;
}

bool Library::delete_book()
{
	string t_name;
	cout << "Please write down the book name which you want to delete:" << endl;
	cin >> t_name;

	if (is_exist(t_name))
	{
		if (Library_Book[t_name].can_delete_all())
		{
			Library_Book.erase(t_name);
			cout << "This book has deleted successfully" << endl;
			cout << endl;
			return true;
		}
		else
		{
			return Library_Book[t_name].Decrease();
		}
	}
	else
		// can not find this book, so fail to delete this book.
	{
		return false;
	}
}

bool Library::borrow_book()
{
	string t_name;
	cout << "Please write down the book name which you want to borrow:" << endl;
	cin >> t_name;
	if ( is_exist(t_name) )
	// can not find this book, so fail to borrow this book.
	{
		return Library_Book[t_name].Borrow();
	}
	else
	{
		return false;
	}
}

bool Library::return_book()
{
	string t_name;
	cout << "Please write down the book name which you want to return:" << endl;
	cin >> t_name;
	if (is_exist(t_name))
	{
		return Library_Book[t_name].Return();
	}
	else
	{
		return false;
	}
}


bool Library::find_book()
{
	string t_name;
	cout << "Please write down the book name which you want to find:" << endl;
	cin >> t_name;
	if (is_exist(t_name))
	{
		Library_Book[t_name].Print();
		cout << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Library::print_book() const
{
	for (auto i : Library_Book)
		i.second.Print();
	cout << endl;
}