#include "RPN.hpp"

int main(int argc, char **argv)
{
	std::string str;
	std::vector<int> numbers;
	std::vector<char> operations;
	int res;

	if (argc == 2)
	{
		str = erase_space(argv[1]);
		if (insert_data(str, numbers, operations) == 1)
			return (1);
		res = calcul(numbers, operations);
		std::cout << res << std::endl;
	}
	return (0);
}
