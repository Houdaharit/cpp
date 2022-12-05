#include "convert.hpp"

int is_char(std::string& str)
{
	if (!isdigit(str[0]) && str.size() == 1)
		return 1;
	return 0;
}

int is_int(std::string& str)
{
	int i = 0;

	if (str[0] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

int is_double(std::string& str)
{
	int i = 0;
	int sign = 1;

	if (str[0] == '-' || str[i] == '+')
		i++;
	if (!str.find("."))
		return 0;
	while (str[i])
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return 0;
		if (str[i] == '.')
		{
			if (sign == 2)
				return 0;
			else
				sign = 2;
		}
		i++;
	}
	return 1;
}

int is_float(std::string& str)
{
	int i = 0;
	int sign = 1;

	if (str[0] == '-' || str[i] == '+')
		i++;
	if (str[str.size() - 1] != 'f' || !str.find("."))
		return 0;
	while (str[i] && (i < (int)str.size() - 1))
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return 0;
		if (str[i] == '.')
		{
			if (sign == 2)
				return 0;
			else
				sign = 2;
		}
		i++;
	}
	return 1;

}

char input_type(std::string& str)
{
	if (is_char(str))
		return 'c';
	else if (is_int(str))
		return 'i';
	else if (is_float(str))
		return 'f';
	else if (is_double(str))
		return 'd';
	return 'n';
}