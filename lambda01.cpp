#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int i = 7;
	/* empty lambda */
	auto f = [](){};
	auto f1 = [](auto&& arg){ cout << "arg of type(" << typeid(arg).name() <<") = "<< arg <<endl; };

	f();
	f1(5);
	f1(i);
	f1("f1");
	return 0;
}
