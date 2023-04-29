#include <iostream>
#include <functional>
#include <string>
using std::cout;
using std::endl;

void print(const int val, const std::string& msg)
{
	cout << "msg: " << msg << ", val=" << val << endl;
}

template <typename T>
void print2(const T val, const std::string& msg)
{
	cout << __PRETTY_FUNCTION__ << ": msg: " << msg << ", val(" << typeid(T).name() << ")=" << val << endl;
}

int main()
{
	int i = 6;
	/* bind will copy its args and cannot accept just "f0" for some reason */
	auto f0 = std::bind(&print, i, "f0");
	auto f1 = std::bind(&print, std::ref(i), std::string("f1"));//i is a reference => changes to i applied to arg 
	auto f2 = std::bind(&print, std::ref(i), std::placeholders::_1);//need to pass second arg
	/* cant bind template, need to explicitly pass parameter type */
	auto f3 = std::bind(&print2<int>, 1, "f3");
	auto f4 = std::bind(&print2<double>, 2.3, "f3");
	/* args order can be changed with placeholders */
	auto f5 = std::bind(&print, std::placeholders::_2, std::placeholders::_1);
	
	f0();
	i++;
	f0();
	
	f1();
	i++;
	f1();
	
	f2("f2::1");
	i++;
	f2("f2::2");

	f3();
	f4();

	f5("f5", 18);
	return 0;
}
