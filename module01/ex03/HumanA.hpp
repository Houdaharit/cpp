#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	Weapon		&weapon;
	std::string	name;
	public:
	HumanA();
	HumanA(std::string, Weapon&);
	~HumanA();
	void attack();
};

# endif
