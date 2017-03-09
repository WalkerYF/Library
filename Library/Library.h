
#include <string>
#include <map>

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
	void Print() const;
	void set_status();
	bool get_status() const { return book_status; }
};

class Book {
	static int seed;

	string Book_Name;
	//string Writer;
	int Repertory_number;
	int Remain_number;
	bool book_status;

	map<string,Single_Book> Same_Book;

public:
	Book();
	Book(string, int, bool);
	bool is_exist(const string & t_id) const;
	bool is_exist_not_borrowed(const string & t_id) const;
	bool is_exist_borrowed(const string & t_id) const; 
	void Add();
	bool Decrease();
	bool can_delete_all() const;
	bool get_status() { return book_status; }
	bool Borrow();
	bool Return();
	void Print() const;
};



class Library {
	friend class Book;
	map<string, Book> Library_Book;
public:
	bool is_exist(const string & t_name) const;
	bool add_book();
	bool delete_book();
	bool borrow_book();
	bool return_book();
	bool find_book();
	void print_book() const;
};

