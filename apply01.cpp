#include <iostream>
#include <tuple>
using std::cout;
using std::endl;

int mul(int a, int b) {return a*b;}

int main()
{
	cout << std::apply(mul, std::make_pair(2,3)) << endl;
	return 0;
}
