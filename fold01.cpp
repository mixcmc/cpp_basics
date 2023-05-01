#include <iostream>

template<typename ... T>
auto sum (T ... t)
{
	auto res = (t + ...);
	std::cout << typeid(res).name() << std::endl;
	return res;
}

template<typename ... T>
auto div (T ... t)
{
	return (t / ...);
}

template<typename ... T>
auto div2 (T ... t)
{
	return (... / t);
}

template<typename ... T>
auto avg (T ... t)
{
	/* not obvious syntax in sizeof */
	return (... + t) / sizeof...(t);
}

int main()
{
	/* T is a maximum type, double in this case */
	std::cout << sum(1,2,3.0,4,5) <<std::endl;
	/* why 0.375? what rule is used? 0.375 = 3/2/4
	 * looks like eval order is not guaranteed (SO answers etc)
	 * but can't find it in c++17 standard.
	 * P0145R3 propose solution for fixing evaluation order
	 * (not in fold but in many contexts) */
	std::cout << div(1.0,2.0,3.0,4.0) <<std::endl;
	std::cout << (4.0/3.0/2.0/1.0) << std::endl;
	/* looks like it does 1/2/3/4 but why div does not do 4/3/2/1? */
	std::cout << div2(1.0,2.0,3.0,4.0) <<std::endl;
	std::cout << (1.0/2.0/3.0/4.0) << std::endl;
	std::cout << avg(1.0,2.0,3.0,4.0) <<std::endl;
	return 0;
}
