#include <iostream>

template<typename ... T>
auto sum (T ... t)
{
	auto res = (t + ...);
	std::cout << "result of type " << typeid(res).name() << " is ";
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

template<typename ... T>
auto biased_avg (T ... t)
{
	constexpr int i = 2;
	/* expands like i + t0 + t1 + ... + tn,
	 *  () are mandatory
	 *  ... + t + (i)
	 *  for accepted variants:
	 *  (pack op ...)
	 *  (... op pack)
	 *  (init op ... op pack)
	 *  (pack op ... op init), ops can be different */
	return ((i) + ... + t) / sizeof...(t);
}

template<typename ... B>
auto conjunct_all(B ... b) { return (b && ...); }

int main()
{
	/* T is a maximum type, double in this case */
	std::cout << "sum=" << sum(1,2,3.0,4,5) <<std::endl;
	/* why 0.375? what rule is used? 0.375 = 3/2/4
	 * looks like eval order is not guaranteed (SO answers etc)
	 * but can't find it in c++17 standard.
	 * P0145R3 propose solution for fixing evaluation order
	 * (not in fold but in many contexts) */
	std::cout << "div=" << div(1.0,2.0,3.0,4.0) <<std::endl;
	std::cout << (4.0/3.0/2.0/1.0) << std::endl;
	/* looks like it does 1/2/3/4 but why div does not do 4/3/2/1? */
	std::cout << "div2=" << div2(1.0,2.0,3.0,4.0) <<std::endl;
	std::cout << (1.0/2.0/3.0/4.0) << std::endl;
	std::cout << "avg=" << avg(1.0,2.0,3.0,4.0) <<std::endl;
	std::cout << "biased_avg=" << biased_avg(1.0,2.0,3.0,4.0) <<std::endl;
	std::cout << (2+1.0+2.0+3.0+4.0)/4 <<std::endl;
	std::cout << "conjunct_all=" <<std::boolalpha << conjunct_all(true, true, false, true) << std::endl;
	return 0;
}
