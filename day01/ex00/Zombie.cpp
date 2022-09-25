#include "Zombie.hpp"

Zombie::Zombie(std::string name_)
{
	name = name_;	
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed\n";
}
