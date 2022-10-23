#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for" <<
		"my 7XL-double-cheese-triple-pickle-special-ketchup" <<
		"burger. I really do!";
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs" <<
		"more money. You didn’t put" <<
		"enough bacon in my burger!" << 
		"If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra" <<
		"bacon for free. I’ve been coming for" <<
		"years whereas you started working" << 
		"here since last month.";
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	comment(Harl *harl, void(Harl::*fct)(void))
{
	(harl->*fct)();
}

void	Harl::complain(std::string level)
{
	Harl	harl;
	const char *str1[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	const char *str2[4] = {"debug", "info", "warning", "error"};
	void (Harl::*complains[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == str1[i] || level == str2[i])
			comment(&harl, complains[i]);
	}
}
