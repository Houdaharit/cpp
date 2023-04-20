#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: cannot open file" << std::endl;
		return 1;
	}
	else if (argc > 2)
	{
		std::cerr << "Error: too many files" << std::endl;
		return 1;
	}
	display(argv[1]);
	return 0;
}
