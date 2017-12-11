#pragma once

#include <string>

using std::string;
using namespace Chrono;

class Book {
private:
	string isbn;
	string book_name;
	string authour_surname;
	Date register_date;
	bool isout;

public:
	Book(string _isbn, string _book_name, string _authour_surname, Date _register_date, bool _out);
	Book(string _isbn, string _book_name, string _authour_surname, int y, Month m, int d, bool _out);
	Book();

	string GetISBN() { return isbn; }
	string GetBookName() { return book_name; }
	string GetAuthourSurname() { return authour_surname; }
	Date GetRegisterDate() { return register_date; }
	bool GetIsOut() { return isout; }

	bool IsOut(const Book& a);
};
