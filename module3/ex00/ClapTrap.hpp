#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;
	std::string		name;

	public:
	ClapTrap();
	ClapTrap(std::string, unsigned int, unsigned int, unsigned int);
	ClapTrap(ClapTrap&);
	~ClapTrap();
	void	attack(const std::string&);
	void	takeDamage(unsigned int);
	void	beRepaired(unsigned int);
}
