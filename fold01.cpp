#include <iostream>

template<typename ... T>
auto sum (T ... t)
{
	return (t + ...);
}

int main()
{
	std::cout << sum(1,2,3,4,5) <<std::endl;
	return 0;
}
