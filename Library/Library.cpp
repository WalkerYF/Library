#include "Library.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;


Single_Book::Single_Book(string t_id, string t_name, bool t_status = true)
{
	Id = t_id;
	Book_Name = t_name;
	book_status = t_status;
}

void Single_Book::Print()
{
	cout << Id << "  " << Book_Name << "  " << ((book_status) ? "can be borrowed." : "has been borrowed." )<< endl;
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

void Book::Add()
{
	if (book_status == false)
	{
		book_status = true;
	}
	Repertory_number++;
	Remain_number++;
	string t_id = Book_Name + char(Repertory_number+48);
	//the generation of id
	Same_Book.push_back(Single_Book(t_id, Book_Name, true));
}

bool Book::can_delete_all()
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
	else {
		Same_Book.pop_back();
		Repertory_number--;
		Remain_number--;
		cout << "This book has deleted successfully" << endl;
		cout << endl;
		return true;
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
		Same_Book[Repertory_number - Remain_number].set_status();
		Remain_number--;
		//reflesh the status of book.
		book_status = (Remain_number) ? true : false;
		cout << "You has borrowed this book successfully!" << endl;
		return true;
	}
}

bool Book::Return()
{
	if (Remain_number == Repertory_number)
	{
		cout << "No this kind of books has been borrowed." << endl;
		return false;
	}
	book_status = true;
	Same_Book[Repertory_number - Remain_number - 1].set_status();
	Remain_number++;
	cout << "You has returned this book successfully" << endl;
	return true;
}

void Book::Print()
{
	cout << "The book you want to know is " << Book_Name << "." << endl
		<< "In this library, the rapertory of this book is " << Repertory_number << " .\n"
		<< "Now " << Remain_number
		<< ((Remain_number > 1) ? " book" : " books") << " can be borrowed." << endl;
	cout << "id      name       status" << endl;
	for (auto i : Same_Book)
		i.Print();
}


bool Library::add_book()
{
	string t_name;
	cout << "Please write down the book name which you want to add:" << endl;
	cin >> t_name;
	auto find_this_book = Library_Book.find(t_name); 
	// get the iterator pointing to this kind of book or the of-the-end iterator.
	if (find_this_book == Library_Book.end()) 
	// can not find this book, so create a new kind of book object.
	{
		cout << "This book is not exist." << endl
			<< "You must enter extra information about this book to create a record." << endl;
		
		//maybe some more information.
	/////////////////////////////////////////////
		//create a new ojbect.
		Library_Book[t_name] = Book(t_name);
		find_this_book = Library_Book.find(t_name);
		//debug
	}

	else
	{
		cout << "This book exists." << endl;
		cout << "We will increase the number of this book." << endl;
	}

	//increase the number of this book.
	find_this_book->second.Add();
	cout << endl;
	return true;
}

bool Library::delete_book()
{
	string t_name;
	cout << "Please write down the book name which you want to add:" << endl;
	cin >> t_name;
	auto find_this_book = Library_Book.find(t_name);

	if (find_this_book == Library_Book.end())
	// can not find this book, so fail to delete this book.
	{
		cout << "This book is not exist." << endl
			<< "You can not delete this book." << endl;
		return false;
	}
	else
	// find this book, so delete this book ojbect.
	{
		if (find_this_book->second.can_delete_all())
		{
			Library_Book.erase(find_this_book);
			cout << "This book has deleted successfully" << endl;
			cout << endl;
			return true;
		}

		else
		{
			return find_this_book->second.Decrease();
		}
	}
}

bool Library::borrow_book()
{
	string t_name;
	cout << "Please write down the book name which you want to borrow:" << endl;
	cin >> t_name;
	auto find_this_book = Library_Book.find(t_name);
	if (find_this_book == Library_Book.end() )
	// can not find this book, so fail to borrow this book.
	{
		cout << "This book is not exist." << endl
			<< "You can not borrow this book." << endl;
		return false;
	}
	else
	{
		return find_this_book->second.Borrow();
	}
}

bool Library::return_book()
{
	string t_name;
	cout << "Please write down the book name which you want to return:" << endl;
	cin >> t_name;
	auto find_this_book = Library_Book.find(t_name);
	if (find_this_book == Library_Book.end())
	{
		cout << "Are you kidding??" << endl
			<< "There is no this book in this library." << endl;
		return false;
	}
	else
	{
		return find_this_book->second.Return();
	}
}


bool Library::find()
{
	string t_name;
	cout << "Please write down the book name which you want to find:" << endl;
	cin >> t_name;
	auto find_this_book = Library_Book.find(t_name);
	if (find_this_book == Library_Book.end())
	{
		cout << "Are you kidding??" << endl
			<< "There is no this book in this library." << endl;
		return false;
	}
	else
	{
		find_this_book->second.Print();
		return true;
	}
}

void Library::print()
{
	for (auto i : Library_Book)
		i.second.Print();
}