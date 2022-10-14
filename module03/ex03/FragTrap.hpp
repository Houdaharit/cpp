#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap();
		FragTrap(FragTrap&);
		FragTrap(const std::string);
		FragTrap& operator = (const FragTrap&);
		~FragTrap();
		void highFivesGuys(void);
};

#endif
