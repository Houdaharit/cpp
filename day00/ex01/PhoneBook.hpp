#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <cstring>

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
};

class	PhoneBook
{
	Contact	contacts[8];
	public:
	int	max;
	void	display_pb(void);
	void	command(std::string);
};

# endif
