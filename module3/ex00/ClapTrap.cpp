#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, unsigned int hit_points, unsigned energy_points, unsigned attack_damage)
{
	this->name = name;
	this->hit_points = hit_points;
	this->energy_points = energy_points;
	this->attack_damage = attack_damage;
}

ClapTrap::ClapTrap(ClapTrap& claptrap)
{
	name = claptrap.name;
	hit_points = claptrap.hit_points;
	energy_points = claptrap.energy_points;
	attack_damage = claptrap.attack_damage;
}

ClapTrap::~ClapTrap()
{
}

void	ClapTrap::attack(const std::string& target)
{

}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{

}
