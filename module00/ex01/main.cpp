#include "PhoneBook.hpp"

int	check_cmd(std::string cmd)
{
	if (cmd == "ADD" || cmd == "add")
		return 1;
	else if (cmd == "search" || cmd == "SEARCH")
		return 1;
	return 0;
}

int main()
{
	PhoneBook	phonebook;
	std::string	cmd;

	phonebook.max = 0;
	phonebook.index = 0;
	std::cout << "Enter command: ";
	std::cin >> cmd;
	if (std::cin.eof())
		return 0;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Enter command: ";
		std::cin >> cmd;
	}
	while (cmd != "exit" && cmd != "EXIT")
	{
		if (check_cmd(cmd))
		{
			if (!phonebook.command(cmd))
				return 0;
		}
		std::cout << "Enter command: ";
		std::cin >> cmd;
		if (std::cin.fail())
			return 0;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Enter command: ";
			std::cin >> cmd;
		}
	}
	return (0);

}
