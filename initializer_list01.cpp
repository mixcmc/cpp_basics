#include <iostream>
#include <initializer_list>
#include <vector>
#include <iterator>

template <typename T>
struct S
{
	std::vector<T> v;
	S(std::initializer_list<T> l) : v(l)
	{
		std::cout << __PRETTY_FUNCTION__ << ": initialized with " << l.size() << "-element list\n";
	}
	void append(std::initializer_list<T> l) { v.insert(v.end(), l.begin(), l.end()); }
	std::pair<const T*, std::size_t> c_arr() const { return {&v[0], v.size()}; }
};

int main()
{
	S s = {1, 2, 3, 4, 5, 6};
	s.append({7, 8, 9});
	std::cout << "Vector conent:\n";
	std::copy(s.v.begin(), s.v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
