#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "";
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::Weapon(std::string type)
{
	setType(type);
}


std::string	Weapon::getType()
{
	const std::string &Rtype = type;

	return (Rtype);
}
