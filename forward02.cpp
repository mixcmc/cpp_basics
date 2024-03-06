#include <iostream>
#include <utility>
#include <memory>
#include <vector>


struct dev{
	int id;
	char *str;
};

typedef std::unique_ptr<dev> dev_uptr;

std::vector<dev_uptr> devices;

int main()
{
	dev_uptr d0 = std::make_unique<dev>();
	dev_uptr d1 = dev_uptr(new dev[3]);

	devices.emplace_back(std::forward<dev_uptr>(d0));
	//devices.emplace_back(std::forward<dev_uptr>(std::make_unique<dev>(new dev)));
	devices.emplace_back(std::forward<dev_uptr>(d1));

	devices.push_back(std::move(dev_uptr()));
	return 0;
}
