#include "Convert.hpp"

int main(int argc, char** argv)
{
	try
	{
		if (argc < 2)
			throw NotEnoughArgumentsException();
		if (argc > 2)
			throw TooManyArgumentsException();
		std::string str(argv[1]);
		Convert convert(str);
convert.display();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
