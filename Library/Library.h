
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::string;
using std::map;

class Single_Book{
	string Id;
	string Book_Name;
	//string Writer;
	bool book_status;
	//some more information
public:
	Single_Book() {};
	Single_Book(string, string, bool);
	void Print();
	void set_status();
};

class Book {
	string Book_Name;
	//string Writer;
	int Repertory_number;
	int Remain_number;
	bool book_status;

	vector<Single_Book> Same_Book;

public:
	Book();
	Book(string, int, bool);
	void Add();
	bool Decrease();
	bool can_delete_all();
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
	void print();
};

