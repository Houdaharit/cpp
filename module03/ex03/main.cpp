#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap harry("Harry");
	harry.attack("bob");
	harry.takeDamage(5);
	harry.beRepaired(2);
	harry.whoAmI();
}
