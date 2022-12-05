#include "convert.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw more_arguments;
		if (argc > 2)
			throw too_many_arguments;
		std::cout << argv[1] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
