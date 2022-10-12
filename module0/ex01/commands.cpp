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
	std::cout << first_name << "\t";
	std::cout << last_name << "\t";
	std::cout << nickname << "\t";
	std::cout << phone_num << "\t";
	std::cout << std::endl;
}

void	Contact::display_contact_endl()
{
	std::cout << std::endl;
	std::cout << "Contact:" << std::endl;
	std::cout << first_name << "\n";
	std::cout << last_name << "\n";
	std::cout << nickname << "\n";
	std::cout << phone_num << "\n";
	std::cout << std::endl;
}

void	PhoneBook::display_pb()
{
	int	i;

	i = 0;
	if (max == 0)
	{
		std::cout << "No contacts yet!" << std::endl;
		return ;
	}
	std::cout << "Index:          ";
	std::cout << "First Name:     ";
	std::cout << "Last Name:      ";
	std::cout << "Nickname:       ";
	std::cout << "Phone Number:   " << std::endl;
	while (i < max)
	{
		std::cout << i << "       ";
		contacts[i++].display_contact();
	}
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
		display_pb();
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
