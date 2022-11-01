#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{
	std::string name;
	public:
	DiamondTrap();
	DiamondTrap(DiamondTrap&);
	DiamondTrap& operator = (const DiamondTrap&);
	~DiamondTrap();
	DiamondTrap(const std::string&);
	void	attack(const std::string&);
	void	whoAmI();
};

#endif
