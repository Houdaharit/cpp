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
	void	announce(void);
	void	set_name(std::string);
	};

Zombie	*zombieHorde(int, std::string);
#endif
