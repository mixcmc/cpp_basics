#include <iostream>
using std::cout;
using std::endl;

template<typename T>
concept IntOrFloat = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <IntOrFloat T>
T sum(T a, T b) { return a + b; }

template <typename T>
concept Ring = requires (T a, T b) {
	{ a + b } -> std::same_as<T>;
	{ a * b } -> std::convertible_to<T>;
};

template <typename T>
requires Ring<T> || IntOrFloat<T>
T f(T a, T b) { return a*b + a; }

int main()
{
	cout << sum(1, 2) << endl;
	cout << sum(1.3, 3.2) << endl;
	/* both args should have the same type */
	//sum(3.0f, 3.2) or sum(5, 1.0) - errors
	cout << f(1, 2) << endl;
	cout << f(.1, .2) << endl;
	return 0;
}
