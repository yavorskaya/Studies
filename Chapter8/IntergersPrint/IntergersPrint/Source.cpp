#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void Print(const vector<int>& _vec, const string& _str)
{
	for (int i = 0; i < (_vec.size() - 1); ++i)
		cout << _vec[i] << _str;
	cout << _vec[(_vec.size() - 1)];
	cout << endl;
}

void Print(const vector<int>& _vec, const string& _name, const string& _str)
{
	cout << _name << "\n";
	for (int i = 0; i < (_vec.size()); ++i) {
		if (i != (_vec.size() - 1))
			cout << _vec[i] << _str; // После последнего элемента не должен выводиться символ разделения
		else cout << _vec[i];
	}
	cout << endl;
}

void PrintUsingRange(const vector<int>& _vec, const string& _str)
{
	cout << _str << endl;
	for (int x : _vec) // Для перебора всех элементов контейнера
		cout << x << " ";
	cout << endl;

}

int main(int argc, char* argv[])
{
	vector<int>vec = {3, 7, 9, 10, 11, 56, 2, 90, 33};
	Print(vec, ", ");
	PrintUsingRange(vec, "Vector with range: ");
	Print(vec, "Function Overload: ", ", ");
	return 0;
}