#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <chrono>

std::future<bool> check_str(const std::string &str)
{
	auto handle = [](const std::string &str) -> bool
	{
		std::cout << "Checking str '" << str << "'" << std::endl;
		return true;
	};

	std::packaged_task<bool(const std::string &)> task(handle);
	auto fut = task.get_future();
	std::thread th(std::move(task), str);

	th.detach();
	return std::move(fut);
}

int main()
{
	auto check = check_str("just string");
	if (check.get()) {
		std::cout << "string accepted\n";
	} else {
		std::cout << "string rejected\n";
	}
	return 0;
}
