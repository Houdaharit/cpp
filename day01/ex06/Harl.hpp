#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class Harl
{
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	public:
	Harl(void);
	~Harl(void);
	void filter(std::string complain);
};

void	comment(Harl *harl, void(Harl::*fct)(void));
int		cmp(std::string complain);
#endif
