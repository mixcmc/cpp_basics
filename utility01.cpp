/* Examples of utility library functions use:
 *     * std::rel_ops operators
 *     * std::exchange
 *     * std::forward
 *     * std::move
 *     * std::swap(pair)
 *     * std::make_pair
 *     * std::pair
 *     * std::get(pair)
 * */
#include <iostream>
#include <utility>
#include <vector>
using std::cout;
using std::endl;

template<typename T>
requires std::is_arithmetic_v<T>
struct num {
	T a;
	num(T&& b) noexcept : a(std::forward<T>(b)) {}
	num(num&& other) noexcept : a(std::exchange(other.a,0)) {}
	num& operator=(num&& other) noexcept
	{
		cout << __PRETTY_FUNCTION__ << endl;
		if (this != &other) a = std::exchange(other.a, 0);
		return *this;
	}
	template <T>
	friend std::ostream& operator<<(std::ostream& os, const num<T>& n);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const num<T>& n) { os << n.a; return os; }

template <typename T>
requires std::is_arithmetic_v<T>
bool operator==(const num<T>& a, const num<T>& b) { return a.a == b.a; }

template <typename T>
requires std::is_arithmetic_v<T>
bool operator<(const num<T>& a, const num<T>& b) { return a.a < b.a; }

int main()
{
	num<int> n1 = {1}, n2 = {3};
	auto p1 = std::make_pair(15, 17.17);
	auto p2 = std::pair(33, 31.13); //since c++17
	auto print_pair = [&](const auto& msg) {
		cout << msg << ": "
			<< "p1 = (" << std::get<0>(p1) << ", " << std::get<1>(p1) << "), "
			<< "p2 = (" << std::get<0>(p2) << ", " << std::get<1>(p2) << ")\n";
	};
	std::vector<num<int>> v;

	/* rel_ops */
	using namespace std::rel_ops;
	cout << std::boolalpha;
	cout << "(n1 == n2) -> " << (n1 == n2) << endl;
	cout << "(n1 != n2) -> " << (n1 != n2) << endl;
	cout << "(n1  < n2) -> " << (n1  < n2) << endl;
	cout << "(n1  > n2) -> " << (n1  > n2) << endl;
	cout << "(n1 >= n2) -> " << (n1 >= n2) << endl;
	cout << "(n1 <= n2) -> " << (n1 <= n2) << endl;

	/* exchange */
	n1 = std::move(n2);
	cout << "n1.a = " << n1.a << ", n2.a = " << n2.a << endl;

	/* swap(pair) */
	print_pair("before swap");
	std::swap(p1, p2);
	print_pair("after swap");

	v.emplace_back(std::forward<num<int>>(n1));
	v.emplace_back(std::forward<num<int>>(n2));
	cout << "v[0] = " << v[0] << ", v[1] = " << v[1] << endl;
	return 0;
}
