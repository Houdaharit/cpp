#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap ,public ScavTrap
{
	std::string name;
	public:
	DiamondTrap();
	DiamondTrap(const std::string&);
	DiamondTrap(DiamondTrap&);
	DiamondTrap& operator = (const DiamondTrap&);
	~DiamondTrap();
	void	attack(const std::string&);
	void	whoAmI();
};

#endif
