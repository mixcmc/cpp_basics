#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <string>

struct S {
	int a;
	std::string b;
};

int main()
{
	std::unordered_map<std::string, int> um = {
		{"RED",   0xff0000},
		{"GREEN", 0x00ff00},
		{"BLUE",  0x0000ff}
	};
	for (const auto&[name, val] : um) {
		std::cout << std::setfill(' ') << std::setw(5) << name << " = 0x" << std::setfill('0') << std::setw(8) <<  std::hex << val << "\n";
	}

	S s ={13, "boo"};
	auto [a, b] = s;
	std::cout << "a=" << std::dec << a << ", b=" << b << std::endl;
	return 0;
}
