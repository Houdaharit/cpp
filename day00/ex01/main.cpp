#include "PhoneBook.hpp"

int main()
{
	char	*command;

	command = NULL;
	std::cin >> command;
	if (!strcmp(command, "EXIT"))
		return (0);
	else
		std::cout << "YES!";
	return (0);
}
