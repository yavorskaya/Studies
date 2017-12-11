#pragma once

#include <iostream>

namespace Chrono {
	enum class Month {
		jan = 1, feb, mar, apr, may, jun,
		jul, aug, sep, oct, nov, dec
	};

	class Date {
	public:
		class Invalid {};				// Для генерации исключений
		Date(int y, Month m, int d);	// Проверка корректности и инициализация

		Date();

		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		void add_day(int _d);
		void add_month(int _m);
		void add_year(int _y);

	private:
		int y;
		Month m;
		int d;
	};						
	// Почему вспомогательные функции за пределами класса
	bool is_date(int _y, Month _m, int _d);
	bool leapYear(int _y);
	bool operator==(const Date& _a, const Date& _b);
	bool operator!=(const Date& _a, const Date& _b);
	std::ostream& operator<<(std::ostream& os, const Date& _a);
	std::istream& operator>>(std::istream& is, Date& _a);
}
