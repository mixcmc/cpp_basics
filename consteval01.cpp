#include <iostream>
#include <cstdint>
using std::cout, std::endl;

consteval uint64_t square(int n) {return n*n;}
constexpr int get_val(const int n){if(n > 3) return n + 1; return n;}

int get_val2(void) {return 2;}

int main()
{
	int n = 6;
	const int nn = 7;
	constexpr int nnn = 8;
	const int n4 = get_val2();
	cout << "5*5 = " << square(5) << endl;
	//square(n); <-- error: n is not const
	cout << "const int: n*n = " << square(nn) << endl;
	cout << "constexpr int: n*n = " << square(nnn) << endl;
	cout << "constexpr(*(const)): n*n = " << square(get_val(3)) << endl;
	//square(get_val(n)); <-- error: the value of ‘n’ is not usable in a constant expression
	cout << "constexpr(*(const var)): n*n = " << square(get_val(nn)) << endl;
	//square(n4) << endl; <-- error: the value of ‘n’ is not usable in a constant expression
	return 0;
}
