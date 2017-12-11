#include <iostream>
#include "Chrono.h"
#include "Book.h"


using namespace Chrono;

int main(int argc, char* argv[])
{
	Date today(2005, Month::dec, 24);
	std::cout << today << std::endl;
	Date tomorrow{};
	std::cout << tomorrow << std::endl;
	tomorrow = today;
	tomorrow.add_day(1);
	std::cout << tomorrow << std::endl;
	tomorrow.add_day(25);
	std::cout << tomorrow << std::endl;
	Book book { "123466", "Stolen from Our Embrace", "Crey", 2017, Month::nov, 28, true };
	Book book2{ "1234NN", "Toujours Provence", "Mayle", tomorrow, false };
	std::cout << book.GetISBN() << " " << book.GetBookName() << " " << book.GetRegisterDate() << std::endl;
	std::cout << book2.GetISBN() << " " << book2.GetBookName() << " " << book2.GetRegisterDate() << std::endl;
	return 0;
}