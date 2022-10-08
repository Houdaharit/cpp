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
}

void	PhoneBook::display_pb()
{
	int	i;

	i = 0;
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
	int	i;

	i = 0;
	if (cmd == "ADD" || cmd == "add")
	{
		if (max < 8)
			contacts[i++].add();
		else
			contacts[7].add();
	}
}
