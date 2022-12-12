#include "Convert.hpp"

int displayInf(const std::string &str)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	if (str == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	if (str == "inf")
	{
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	if (str == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	return 1;
}

int check_inf(std::string &input)
{
	if (input == "nan")
		return displayInf("nan");
	if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff")
		return displayInf("inf");

	if (input == "-inf" || input == "inf" || input == "inff" || input == "-inff")
		return displayInf("-inf");
	return 0;
}
int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw NotEnoughArgumentsException();
		if (argc > 2)
			throw TooManyArgumentsException();
		std::string str(argv[1]);
		if (!check_inf(str))
		{
				Convert convert(str);
				convert.display();
		}
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
