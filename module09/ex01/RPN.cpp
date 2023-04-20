#include "RPN.hpp"

void error_msg()
{
	std::cerr << "Error" << std::endl;
	exit(1);
}

int	operation(int res, int num, char op)
{
	if (op == '/' && res == 0)
		error_msg();
	if (op == '+')
		return res + num;
	else if (op == '-')
		return num - res;
	else if (op == '*')
		return res * num;
	return num / res;
}

int insert_data(std::string& str, std::stack<int>& numbers)
{
	int i = 0;
	int res = 0;

	while (str[i])
	{
		if (isdigit(str[i]))
			numbers.push(str[i] - '0');
		else if (strchr("+*/-", str[i]))
		{
			if (numbers.size() >= 2)
			{
				res = numbers.top();
				numbers.pop();
				res = operation(res, numbers.top(), str[i]);
				numbers.pop();
				numbers.push(res);
			}
			else
				error_msg();
		}
		i++;
	}
	if (numbers.size() > 1)
		error_msg();
	return numbers.top();
}

int check_input(std::string& str)
{
	char whitespace[] = " \n\r\t\f\v";

	int i = 0;
	while (str[i])
	{
		if (!strchr(whitespace, str[i]) && !isdigit(str[i]) && !strchr("+*/-", str[i]))
			return 0;
		i++;
	}
	return 1;
}
