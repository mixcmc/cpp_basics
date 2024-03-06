#include <iostream>
#include <future>
#include <thread>

int calc(int a, int b)
{
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return a + 2*b + 1;
}

int main()
{
	int s;
	std::future<int> res = std::async(std::launch::async, calc, 3, 5);
	std::cout << "Waiting for result or doing smth else" << std::endl;
	s = res.get();
	std::cout << "Result of calc(3,5): " << s << std::endl;
	return 0;
}
