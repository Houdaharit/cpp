#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor called" << std::endl;
	name = "";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constractor called" << std::endl;
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;

}

ClapTrap::ClapTrap(ClapTrap& claptrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	name = claptrap.name;
	hit_points = claptrap.hit_points;
	energy_points = claptrap.energy_points;
	attack_damage = claptrap.attack_damage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing" << " 1 points of damage!";
		std::cout << std::endl;
		energy_points--;
	}
	else
		std::cout << name <<" doesn't have enough hit points or energy to attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " took " << amount << " amount of damage" << std::endl;
	attack_damage += amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0)
	{
		std::cout << name << " is repairing himself" << std::endl;
		hit_points += amount;
		energy_points--;
	}
	else
		std::cout << name << " doesn't have enough energy to repair himself" << std::endl; 
}
