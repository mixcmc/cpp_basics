#include <iostream>
#include <future>
#include <thread>
#include <limits>

int main()
{
	auto shared_prom = std::make_shared<std::promise<void>>();
	std::future<void> waiter = shared_prom->get_future();
	const auto finder = [shared_prom](size_t val)
	{
		size_t i = std::numeric_limits<size_t>::max();
		std::cout << "Searching...\n";
		while (i) {
			if (i-- == val) {
				shared_prom->set_value();
				std::cout << "Value found: " << val << std::endl;
				break;
			}
		}
	};
	std::thread th(finder, std::numeric_limits<size_t>::max() - 123456789);
	std::cout << "Thread created\n";
	th.detach();
	std::cout << "Waiting...\n";
	waiter.get();
	std::cout << "Done.\n";
	return 0;
}
