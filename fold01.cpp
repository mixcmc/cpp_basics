#include <iostream>

template<typename ... T>
auto sum (T ... t)
{
	auto res = (t + ...);
	std::cout << typeid(res).name() << std::endl;
	return res;
}

int main()
{
	/* T is a maximum type, double in this case */
	std::cout << sum(1,2,3.0,4,5) <<std::endl;
	return 0;
}
