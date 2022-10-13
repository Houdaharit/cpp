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
};

Zombie	*newZombie(std::string);
void	randomChump(std::string);
#endif
