#include <iostream>
#include "Chrono.h"

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
	return 0;
}