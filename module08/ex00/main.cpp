#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	for(int i = 0; i < 9; i++)
		v.push_back(i);
	try
	{
		std::cout << *easyfind(v, 15) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Element found: " << *easyfind(v, 5) <<  "!"<< std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

