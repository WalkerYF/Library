#pragma once

#include <string>
#include <deque>
#include <map>
using std::string;
using std::deque;
using std::map;

//struct Single_Book{
//	string id;
//	
//};

class Book {
	string Book_Name;
	string Writer;
	int Repertory_number;
	int Remain_number;
	bool 
};


class Library {
	friend class Book;
	map<string, Book> Library_Book;
public:
	bool add_book();
	bool delete_book();
	bool borrow_book();
	bool return_book();
	bool find();
};