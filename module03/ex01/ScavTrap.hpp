#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap(ScavTrap&);
		ScavTrap& operator = (const ScavTrap&);
		~ScavTrap();
		void attack(const std::string&);
		void guardGate(void);
};
#endif
