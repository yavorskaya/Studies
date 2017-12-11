#include <string>
#include "Chrono.h"
#include "Book.h"

using std::string;
using namespace Chrono;

Book::Book(string _isbn, string _book_name, string _authour_surname, Date _register_date, bool _isout) :
	isbn{ _isbn }, book_name{ _book_name }, authour_surname{ _authour_surname }, 
	register_date { _register_date.year(), _register_date.month(), _register_date.day() },
	isout{ _isout } {}

Book::Book(string _isbn, string _book_name, string _authour_surname, int y, Month m, int d, bool _isout) :
	isbn{ _isbn }, book_name{ _book_name }, authour_surname{ _authour_surname },
	register_date{ y, m, d },
	isout{ _isout } {}

Book::Book () {}

bool Book::IsOut(const Book& a)
{
	return a.isout;
}

