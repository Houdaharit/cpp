#include "Zombie.hpp"

int main()
{
	Zombie	*zombie = zombieHorde(5, "HEHE");
	int		i;

	i = 0;
	while (i < 5)
		zombie[i++].announce();
	delete[] zombie;
	return (0);
}
