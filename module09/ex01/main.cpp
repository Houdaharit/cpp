#include "RPN.hpp"

int main(int argc, char **argv)
{
	std::string str;
	std::vector<int> numbers;
	std::vector<char> operations;

	if (argc == 2)
	{
		str = erase_space(argv[1]);
		insert_data(str, numbers, operations);
	}
	return (0);
}
