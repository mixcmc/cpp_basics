#include <iostream>
#include <cstdint>
using std::cout, std::endl;

consteval uint64_t square(int n) {return n*n;}

int main()
{
	cout << square(5) << endl;
	return 0;
}
