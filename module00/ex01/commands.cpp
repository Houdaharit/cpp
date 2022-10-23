#include "PhoneBook.hpp"

void	Contact::add()
{

	std::cout << "First name: ";
	std::cin >> first_name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	std::cout << "Phone number: ";
	std::cin >> phone_num;
}

void	Contact::display_contact(void)
{
	std::cout << std::setw(10);
	std::cout << first_name.substr(0, 9);
	if (first_name.size() > 10)
		std::cout << ".|";
	std::cout << std::setw(10);
	std::cout << last_name.substr(0, 9) << "|";
	std::cout << std::setw(10);
	std::cout << nickname.substr(0, 9) << "|";
	std::cout << std::setw(10);
	std::cout << phone_num.substr(0, 9) << "|";
	std::cout << std::endl;
}

void	Contact::display_contact_endl()
{
	std::cout << std::endl;
	std::cout << "Contact:" << std::endl;
	std::cout << "First name: " << first_name  << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_num << std::endl;
	std::cout << std::endl;
}

int	PhoneBook::display_pb()
{
	int	i;

	i = 0;
	if (max == 0)
	{
		std::cout << "No contacts yet!" << std::endl;
		return 0;
	}
	while (i < max)
	{
		std::cout << std::setw(10);
		std::cout << i << "|";
		contacts[i++].display_contact();
	}
	return (1);
}

void	PhoneBook::command(std::string cmd)
{
	int	index;

	if (cmd == "ADD" || cmd == "add")
	{
		if (max < 8)
			contacts[max++].add();
		else
			contacts[7].add();
	}
	else if (cmd == "SEARCH" || cmd == "search")
	{
		if (!display_pb())
			return ;
		std::cout << std::endl << "Enter index: ";
		std::cin >> index;
		while (index < 0 || index >= max)
		{
			std::cout << "Try another index: ";
			std::cin >> index;
		}
		contacts[index].display_contact_endl();
	}
}
