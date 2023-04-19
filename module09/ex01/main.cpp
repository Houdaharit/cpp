#include "RPN.hpp"

int main(int argc, char **argv)
{
	std::string str;
	std::stack<int> numbers;
	int res;

	if (argc == 2)
	{
		std::string str(argv[1]);
		res = insert_data(str, numbers);
		std::cout << res << std::endl;
	}
	return (0);
}
