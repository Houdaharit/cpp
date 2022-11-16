#include "Zombie.hpp"

int main()
{
	Zombie	*z1;
	Zombie  z2("z2");

	z1 = newZombie("z1");
	z1->announce();
	z2.announce();
	randomChump("z3");
	delete z1;
}
