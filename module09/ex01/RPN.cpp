#include "RPN.hpp"

void	error_msg()
{
	std::cerr << "Error" << std::endl;
	exit(1);
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

void	insert_data(std::string& str, std::vector<int>& numbers, std::vector<char>& operations)
{
	int i = 1;
	if (!isdigit(str[0]))
		error_msg();
	else
		numbers.push_back(str[0] - '0');
	while (str[i])
	{
		if (i % 2 == 1 && isdigit(str[i]))
			numbers.push_back(str[i] - '0');
		else if (i % 2 == 0 && strchr("+*/-", str[i]))
			operations.push_back(str[i]);
		else
			error_msg();
		i++;
	}
	if (numbers.size() -1  != operations.size())
		error_msg();
}
