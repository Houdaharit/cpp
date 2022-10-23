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
	void	add(void);
	void	display_contact(void);
	void	display_contact_endl();
};

class	PhoneBook
{
	Contact	contacts[8];
	public:
	int	max;
	int	display_pb(void);
	void	command(std::string);
};

# endif
