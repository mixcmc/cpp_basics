#include <iostream>
#include <utility>
#include <memory>
#include <vector>

template<typename T>
class uptr
{
	T *ptr;
	public:
	uptr() : ptr(nullptr)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	uptr(std::nullptr_t) : ptr(nullptr)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	uptr(T *t) : ptr(t)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	uptr(T& t) : ptr(&t)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	uptr(uptr<T>&& u) noexcept
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		this->swap(u);
	}
	uptr<T>& operator=(uptr<T>&& u) noexcept
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		this->swap(u);
		return *this;
	}
	T* operator->() const
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return ptr;
	}
	T& operator*() const
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *ptr;
	}
	T* get() const
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return ptr;
	}
	T* release() noexcept
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		T *r = nullptr;
		std::swap(r, ptr);
		return r;
	}
	explicit operator bool()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return ptr;
	}
	~uptr()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		delete ptr;
	}

	void swap(uptr<T>& u) noexcept
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		std::swap(ptr, u.ptr);
	}

	uptr(const uptr<T>&) = delete;
	uptr<T>& operator=(const uptr<T>&) = delete;
};

template<typename T>
void swap(uptr<T>& a, uptr<T>& b)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	a.swap(b);
}

struct dev
{
	int id;
	char bus_address[1024];
};


int main()
{
	std::vector<uptr<dev>> v;
	auto d0 = uptr<dev>();
	//v.emplace_back(std::forward<dev>(d0));
	v.emplace_back(std::move(d0));
	return 0;
}
