#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	std::string	type;
	public:
	Weapon();
	Weapon(std::string type);
	std::string	getType(void);
	void setType(std::string);
};
# endif
