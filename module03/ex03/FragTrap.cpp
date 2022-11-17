#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor called!" << std::endl;
	this->name = "";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(FragTrap& fragtrap)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
	this->name = fragtrap.name;
	this->hit_points = fragtrap.hit_points;
	this->energy_points = fragtrap.energy_points;
	this->attack_damage = fragtrap.attack_damage;
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << "FragTrap constructor called!" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;

}

FragTrap& FragTrap::operator = (const FragTrap& fragtrap)
{
	if (this != &fragtrap)
	{
		this->name = fragtrap.name;
		this->hit_points = fragtrap.hit_points;
		this->energy_points = fragtrap.energy_points;
		this->attack_damage = fragtrap.attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High five guys!" << std::endl;
}
