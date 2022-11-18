#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = "";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap& scavtrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->name = scavtrap.name;
	this->hit_points = scavtrap.hit_points;
	this->energy_points = scavtrap.energy_points;
	this->attack_damage = scavtrap.attack_damage;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& scavtrap)
{
	if (this != &scavtrap)
	{
		this->name = scavtrap.name;
		this->hit_points = scavtrap.hit_points;
		this->energy_points = scavtrap.energy_points;
		this->attack_damage = scavtrap.attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hit_points > 0 && this->energy_points > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damgage << "  points of damage!";
		std::cout << std::endl;
		this->energy_points--;
	}
	else
	{
		std::cout << this->name << " doesn't have enough energy or hit points to attack!";
		std::cout << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}
