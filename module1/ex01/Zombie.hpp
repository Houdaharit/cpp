#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class	Zombie
{
	std::string	name;
	public:
	Zombie();
	Zombie(std::string);
	~Zombie();
	void	announce(void)
	{
		std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
	}
};

Zombie	*zombieHorde(int, std::string);
#endif
