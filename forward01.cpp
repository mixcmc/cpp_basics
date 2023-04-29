#include <iostream>
#include <utility>
using std::cout;
using std::endl;

void print (int& val) { cout << __PRETTY_FUNCTION__ <<": val=" << val << endl; }
void print (int&& val) { cout << __PRETTY_FUNCTION__ <<": val=" << val << endl; }

template <typename T>
void pr(T&& val) { print(std::forward<T>(val)); }

int main()
{
	int v = 5;
	pr(v);
	pr(9);
	return 0;
}
