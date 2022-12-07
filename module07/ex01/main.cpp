#include "iter.hpp"

void upperCase(std::string& str)
{
	size_t length = str.size();

	for (size_t i = 0; i < length; i++)
		str[i] = toupper(str[i]);
}

int main()
{
	std::string array[2];
	array[0] = "hello";
	array[1] = "everyone";
	iter<std::string>(array, 2, upperCase);
	for (int i = 0; i < 2; i++)
		std::cout << array[i] << std::endl;
}
