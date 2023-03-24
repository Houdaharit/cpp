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

int insert_data(std::string& str, std::vector<int>& numbers, std::vector<char>& operations)
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
		error_msg();
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

int	calcul(std::vector<int>& nums, std::vector<char>& op)	
{
	int res = 0;
	int i = 2;
	size_t j = 1;

	res = operation(nums[0], nums[1], op[0]);
	while (j < op.size())
		res = operation(res, nums[i++], op[j++]);
	return (res);
}
