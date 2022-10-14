#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	name = "";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap& scavtrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	name = scavtrap.name;
	hit_points = scavtrap.hit_points;
	energy_points = scavtrap.energy_points;
	attack_damage = scavtrap.attack_damage;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& scavtrap)
{
	if (this != &scavtrap)
	{
		name = scavtrap.name;
		hit_points = scavtrap.hit_points;
		energy_points = scavtrap.energy_points;
		attack_damage = scavtrap.attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hit_points > 0 && energy_points > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing 1 points of damage!";
		std::cout << std::endl;
		energy_points--;
	}
	else
	{
		std::cout << name << " doesn't have enough energy or hit points to attack!";
		std::cout << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}
