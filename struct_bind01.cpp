#include <iostream>
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
		std::cout << name << " = " << std::hex << val << "\n";
	}

	S s ={13, "boo"};
	auto [a, b] = s;
	std::cout << "a=" << a << ", b=" << b << std::endl;
	return 0;
}
