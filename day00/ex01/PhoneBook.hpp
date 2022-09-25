#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <cstring>

class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_num;
	private:
		std::string	dark_secret;
};

class	PhoneBook
{
	Contact	contacts[8];
};

Contact	add(void);

# endif
