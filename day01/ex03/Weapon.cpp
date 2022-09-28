#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "";
}

Weapon::Weapon(std::string type)
{
	setType(type);
}
void	Weapon::setType(std::string type)
{
	this->type = type;
}

std::string	Weapon::getType()
{
	return (type);
}
