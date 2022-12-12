#include "Convert.hpp"

int main(int argc, char** argv)
{
	try
	{
		if (argc < 2)
			throw NotEnoughArgumentsException();
		if (argc > 2)
			throw TooManyArgumentsException();
		Convert convert(argv[1]);
		//std::cout << isChar(argv[1]) << std::endl;
		std::cout << isFloat(argv[1]) << std::endl;
		//std::cout << isInt(argv[1]) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
