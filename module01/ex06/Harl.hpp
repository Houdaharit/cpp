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

int		level(std::string complain);
#endif
