#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
{
	std::cout << "Diamond constructor called!" << std::endl;
	name = "";
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const std::string& name) 
{
	std::cout << "Diamond constructor called!" << std::endl;
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap& diamond)
{
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
	name = diamond.name;
	hit_points = diamond.hit_points;
	energy_points = diamond.energy_points;
	attack_damage = diamond.attack_damage;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& diamond)
{
	if (this != &diamond)
	{
		name = diamond.name;
		hit_points = diamond.hit_points;
		energy_points = diamond.energy_points;
		attack_damage = diamond.attack_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
