#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void    Harl::filter(std::string complain)
{
    Harl    harl;
    int     l;

    l = level(complain);
    switch (l)
    {
        case 1:
            {
				std::cout << "[DEBUG]\n";
				harl.debug();
				std::cout << std::endl;
            }
        case 2:
            {
				std::cout << "[INFO]\n";
				harl.info();
				std::cout << std::endl;
            }
        case 3:
            {
				std::cout << "[WARNING]\n";
				harl.warning();
				std::cout << std::endl;
            }
        case 4:
            {
				std::cout << "[ERROR]\n";
				harl.error();
				break;
            }
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}
