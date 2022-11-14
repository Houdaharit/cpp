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

//do something about it
void	Contact::display_contact(void)
{
	std::cout << std::setw(10);
	if (first_name.size() > 10)
		std::cout << first_name.substr(0, 9) << ".|";
	else
		std::cout << first_name.substr(0, 9) << "|";
	std::cout << std::setw(10);
	if (last_name.size() > 10)
		std::cout << last_name.substr(0, 9) << ".|";
	else
		std::cout << last_name.substr(0, 9) << "|";
	std::cout << std::setw(10);
	if (nickname.size() > 10)
		std::cout << nickname.substr(0, 9) << ".|";
	else
		std::cout << nickname.substr(0, 9) << "|";
	std::cout << std::setw(10);
	if (phone_num.size() > 10)
		std::cout << phone_num.substr(0, 9) << ".|";
	else
		std::cout << phone_num.substr(0, 9) << ".|";
	std::cout << "|";
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
	std::cout << std::setw(10);
	std::cout << "index";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "First Name";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "Last Name";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "Nickname";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "Phone Nb";
	std::cout << "|";
	std::cout << std::endl;

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
	int	i;

	if (cmd == "ADD" || cmd == "add")
	{
		if (index < 8)
		{
			contacts[index++].add();
			if (max < 8)
				max++;
		}
		else
		{
			max = 8;
			index = 0;
			contacts[index++].add();
		}
	}
	else if (cmd == "SEARCH" || cmd == "search")
	{
		if (!display_pb())
			return ;
		std::cout << std::endl << "Enter index: ";
		std::cin >> i;
		if (std::cin.eof())
		{
			std::cout << "HEHE"<< std::endl;
			return ;
		}
		while(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << std::endl << "Enter index: ";
			std::cin >> i;
		}
		while (i < 0 || i >= max)
		{
			std::cout << "Try another index: ";
			std::cin >> i;
		}
		contacts[i].display_contact_endl();
	}
}
