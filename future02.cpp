#include <iostream>
#include <future>
#include <thread>
#include <chrono>


void print_val(std::future<int> &v)
{
	const auto start{std::chrono::steady_clock::now()};
	int val = v.get();
	const auto end{std::chrono::steady_clock::now()};
	const std::chrono::duration<double> dur{end - start};
	std::cout << "Got " << val << "\n";
	std::cout << dur << std::endl;
}

int main()
{
	std::promise<int> prom;
	std::future<int> fut = prom.get_future();
	std::thread th1(print_val, std::ref(fut));
	std::this_thread::sleep_for(std::chrono::seconds(3));

	prom.set_value(13);

	th1.join();
	return 0;
}
