#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;

	std::cout << "a= " << a << std::endl;
	std::cout << "b= " << b << std::endl;
	swap<int>(a, b);
	std::cout << std::endl;
	std::cout << "a= " << a << std::endl;
	std::cout << "b= " << b << std::endl;
	std::cout << "max: " << max<int>(a, b) << std::endl;
	std::cout << "min: " << min<int>(a, b) << std::endl;
	std::cout << "max: " << max<float>(1.5f, 1.55f) << std::endl;
	std::cout << "min: " << min<float>(1.5f, 1.55f) << std::endl;
}
