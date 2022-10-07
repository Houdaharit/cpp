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
	void filter(const char *complain);
};

void	comment(Harl *harl, void(Harl::*fct)(void));
int		cmp(const char *complain);
#endif
