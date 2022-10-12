#include "Harl.hpp"

int main()
{
	Harl		harl;
	std::string	level;


	std::cout << "level: ";
	std::cin >> level;
	harl.complain(level);
}
