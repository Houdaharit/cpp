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
}

void	display_contact(Contact contact)
{
	std::cout << contact.first_name << "            ";
	std::cout << contact.last_name << "            ";
	std::cout << contact.nickname << "            ";
	std::cout << contact.phone_num << "             ";
}

void	display_pb(PhoneBook pb)
{
	int	i;

	i = 0;
	std::cout << "Index:          ";
	std::cout << "First Name:     ";
	std::cout << "Last Name:      ";
	std::cout << "Nickname:       ";
	std::cout << "Phone Number:   " << std::endl;
	while (i < pb.max)
	{
		std::cout << i << "       ";
		display_contact(pb.contacts[i++]);
	}
}
