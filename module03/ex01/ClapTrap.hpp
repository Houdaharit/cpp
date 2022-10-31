#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
	protected:
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;
	std::string		name;

	public:
	ClapTrap();
	ClapTrap(std::string);
	ClapTrap(ClapTrap&);
	~ClapTrap();
	ClapTrap& operator = (const ClapTrap&);
	void	attack(const std::string&);
	void	takeDamage(unsigned int);
	void	beRepaired(unsigned int);
};

#endif
