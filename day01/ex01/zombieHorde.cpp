#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	int	i;

	i = 0;
	Zombie	*zombie = new Zombie[n];
	while (i < n)
		zombie[i++] = Zombie(name);
	return (zombie);
}
