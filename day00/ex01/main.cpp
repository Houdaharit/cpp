#include "PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	std::string	command;
	int		i;

	i = 0;
	std::cin >> command;
	while (command != "EXIT")
	{
		if (command == "ADD")
		{
			if (pb.max < 8)
				pb.contacts[i++] = add();
			else
				pb.contacts[7] = add();
		}
		else if (command == "SEARCH")
			display_pb(pb);
		std::cin >> command;
	}
	return (0);
}
