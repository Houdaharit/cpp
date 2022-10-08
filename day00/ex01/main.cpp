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

	std::cout << "Enter command: ";
	std::cin >> cmd;
	while (cmd != "exit" && cmd != "EXIT")
	{
		if (check_cmd(cmd))
			phonebook.command(cmd);
		std::cout << "Enter command: ";
		std::cin >> cmd;
	}
	return (0);

}
