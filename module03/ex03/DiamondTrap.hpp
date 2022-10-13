#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap
{
	std::string name;
	public:
	DiamondTrap();
	DiamondTrap(std::string);
	DimondTrap(DiamondTrap&);
	~DiamondTrap();
	void	whoAmI();
};

#endif
