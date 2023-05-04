#include <iostream>
#include <tuple>
using std::cout;
using std::endl;

int mul(int a, int b) {return a*b;}

auto add = [](auto a, auto b){ return a+b; };

int main()
{
	cout << "mul: " << std::apply(mul, std::make_pair(2,3)) << endl;
	cout << "add: " << std::apply(add, std::pair(1.5, 2.3)) << endl;
	return 0;
}
