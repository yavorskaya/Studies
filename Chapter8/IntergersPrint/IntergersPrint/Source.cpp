#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void Print(const vector<int>& _vec, string _str)
{
	for (int i = 0; i < (_vec.size() - 1); ++i)
		cout << _vec[i] << _str;
	cout << _vec[(_vec.size() - 1)];
	cout << endl;
	
}

int main(int argc, char* argv[])
{
	vector<int>vec = {3, 7, 9, 10, 11, 56, 2, 90, 33};
	Print(vec, ", ");
	return 0;
}