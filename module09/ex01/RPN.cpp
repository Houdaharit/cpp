#include "RPN.hpp"

int error_msg()
{
	std::cerr << "Error" << std::endl;
	return (-1);
}

std::string erase_space(char *argv)
{
	int pos; 

	std::string str(argv);
	std::string::iterator it = str.begin();

	while(str.find(" ") != std::string::npos)
	{
		pos = str.find(" ");
		str.erase(it + pos);
	}
	return (str);
}

int insert_data(std::string& str, std::list<int>& numbers, std::list<char>& operations)
{
	int i = 1;
	if (!isdigit(str[0]))
		return error_msg();
	else
		numbers.push_back(str[0] - '0');
	while (str[i])
	{
		if (i % 2 == 1 && isdigit(str[i]))
			numbers.push_back(str[i] - '0');
		else if (i % 2 == 0 && strchr("+*/-", str[i]))
			operations.push_back(str[i]);
		else
			return error_msg();
		i++;
	}
	if (numbers.size() -1  != operations.size())
		return error_msg();
	return 0;
}

int	operation(int res, int num, char op)
{
	if (op == '+')
		return res + num;
	else if (op == '-')
		return res - num;
	else if (op == '*')
		return res * num;
	return res / num;
}

int	calcul(std::list<int>& nums, std::list<char>& op)	
{
	int res = 0;
	int num;

	num = nums.front();
	nums.pop_front();
	res = operation(num, nums.front(), op.front());
	nums.pop_front();
	op.pop_front();
	while (op.size() > 0)
	{
		res = operation(res, nums.front(), op.front());
		op.pop_front();
		nums.pop_front();
	}
	return (res);
}
