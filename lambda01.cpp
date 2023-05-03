#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int i = 7;
	/* empty lambda */
	auto f = [](){};
	auto f1 = [](auto&& arg){ cout << "arg of type(" << typeid(arg).name() <<") = "<< arg <<endl; };
	/* create functional objects of arbitrary types with any number of args
	 * and pass them to other functional objects */
	auto list = [](auto ...xs) {	
		return [=](auto access){return access(xs...);};
	};
	auto head = [](auto xs) {
		return xs([](auto first, auto ...rest) {return first;});
	};
	auto tail = [=](auto xs) {
		return xs([=](auto first, auto ...rest) {return list(rest...);});
	};
	auto length = [](auto xs) {
		return xs([](auto ...z){return sizeof ...(z);});
	};
	auto prod = [](auto xs) {
		return xs([](auto ...args){ return (args * ...); });
	};
	auto l = list(1,2,3,4,5);
	auto sum = l([](auto ...args){ return (args + ...); });
	auto mul = l([](auto ...args){ return (args * ...); });
	cout << "length(list(1,'2',\"3\"))=" << length(list(1,'2',"3")) << endl;
	cout << "sum=" << sum << endl;
	cout << "mul=" << mul << endl;
	cout << "head(list(1,'2',\"3\"))=" << head(list(1, '2', "3")) << endl;
	cout << "head(tail(list(1,'2',\"3\")))=" << head(tail(list(1, '2', "3"))) << endl;
	cout << "head(tail(tail(list(1,'2',\"3\"))))=" << head(tail(tail(list(1, '2', "3")))) << endl;
	cout << "prod(l)=" << prod(l) << endl;
	/* head(tail(tail(tail(list(1, '2', "3"))))) => error because list need at least 1 arg */

	f();
	f1(5);
	f1(i);
	f1("f1");
	return 0;
}
