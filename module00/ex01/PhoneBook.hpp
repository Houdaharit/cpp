#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <cstring>
# include <iomanip>

class Contact
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_num;
	std::string	dark_secret;
	public:
	int	add(void);
	void	display_contact(void);
	void	display_contact_endl();
};

class	PhoneBook
{
	Contact	contacts[8];
	public:
	int	max;
	int index;
	int	display_pb(void);
	int	command(std::string);
};

# endif
