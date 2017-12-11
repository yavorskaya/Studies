#include "Chrono.h"
namespace Chrono { // Либо писать Chrono::Date::Date ()

	Date::Date(int yy, Month mm, int dd) : y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}

	const Date& default_date()
	{
		static Date dd{ 2001, Month::jan, 1 };
		return dd;
	}


	Date::Date() :  y{ default_date().year() },
					m{ default_date().month() },
		            d{ default_date().day() }
	{}

	void Date::add_day(int dd) {
		int days_in_month = 31;
		switch (m) {
		case Month::feb:
			days_in_month = (leapYear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun:
		case Month::sep: case Month::nov:
			days_in_month = 30;
			break;
		}
		if ((d + dd) > days_in_month) {
			d = (d + dd) % days_in_month;
			if (m == Month::dec)
				++y;
			m = (m == Month::dec) ? Month::jan : Month(int(m) + 1); // Не учтено увеличение на несколько месяцев
		}
		else 
			d += dd;
	}

	void Date::add_month(int mm) {}

	void Date::add_year(int yy) {}

	bool is_date(int yy, Month mm, int dd)
	{
		if (dd <= 0) return false;
		if (mm < Month::jan || mm > Month::dec) return false;

		int days_in_month = 31;
		switch (mm) {
		case Month::feb:
			days_in_month = (leapYear(yy)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun:
		case Month::sep: case Month::nov:
			days_in_month = 30;
			break;
		}
		if (days_in_month < dd) return false;
		return true;
	}

	bool leapYear(int yy)
	{
		// chapter 10
		return false;
	}

	bool operator == (const Date& a, const Date& b)
	{
		return a.year() == b.year() &&
			a.month() == b.month() &&
			a.day() == b.day();
	}

	bool operator != (const Date& a, const Date& b)
	{
		return !(a == b);
	}

	std::ostream& operator << (std::ostream& os, const Date& a)
	{
		return os << '(' << a.year()
			<< ',' << int(a.month())
			<< ',' << a.day() << ')';
	}

	std::istream& operator >> (std::istream& is, Date& a)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' ||
			ch3 != ',' || ch4 != ')') {
			is.clear(std::ios_base::failbit);
			return is;
		}
		a = Date(y, Month(m), d);
		return is;
	}
	enum class Day {
		sunday, monday, tuesday, wednesday,
		thursday, friday, saturday
	};

	Day day_of_week(const Date& a) { return Day::friday; }

	Day next_Sunday(const Date& a) { return Day::friday; }

	Day next_Weekend(const Date& a) { return Day::friday; }

	Month operator++(Month& m)
	{
		m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
		return m;
	}
}
