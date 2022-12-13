#include "Convert.hpp"

int input_type(std::string &input)
{
	if (input.size() == 1 && !std::isdigit(input[0]))
		return 'c';
	else if (input[input.size() - 1] == 'f' && input.find('.') != std::string::npos)
	{
		if (std::isdigit(input[0]))
			return 'f';
		else if ((input[0] == '+' || input[0] == '-') && std::isdigit(input[1]))
			return 'f';
	}
	else if (input[input.size() - 1] != 'f' && input.find('.') != std::string::npos)
	{
		if (std::isdigit(input[0]))
			return 'd';
		else if ((input[0] == '+' || input[0] == '-') && std::isdigit(input[1]))
			return 'd';
	}
	if (input[input.size() - 1] != 'f' && input.find('.') == std::string::npos)
	{
		if (std::isdigit(input[0]))
			return 'i';
		else if ((input[0] == '+' || input[0] == '-') && std::isdigit(input[1]))
			return 'i';
	}
	return 'n';
}