
#include <string>
#include <map>
using std::string;
using std::map;

//struct Single_Book{
//	string id;
//	
//};

class Book {
	string Book_Name;
	//string Writer;
	int Repertory_number;
	int Remain_number;
	bool book_status;
public:
	Book();
	Book(string, int, bool);
	void add_number();
//	void decrease_number();
	bool get_status() { return book_status; }
	bool Borrow();
	bool Return();
	void Print();
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