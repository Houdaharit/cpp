#include "ScavTrap.hpp"

int main()
{
	ScavTrap harry("Harry");
	harry.guardGate();
	harry.attack("bob");
	harry.takeDamage(5);
	harry.beRepaired(2);
}
