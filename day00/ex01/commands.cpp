#include "PhoneBook.hpp"

Contact	add()
{
	Contact	contact;

	std::cout << "First name: ";
	std::cin >> contact.first_name;
	std::cout << "Last name: ";
	std::cin >> contact.last_name;
	std::cout << "Nickname: ";
	std::cin >> contact.nickname;
	std::cout << "Phone number: ";
	std::cin >> contact.phone_num;
	return (contact);
/*	std::cout << "Darkest secret: ";
	std::cin >> contact.dark_secret;*/
}
