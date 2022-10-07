#include "Harl.hpp"

int	cmp(std::string complain)
{
	if (complain == "debug" || complain == "DEBUG")
		return 1;
	if (complain == "info" || complain == "INFO")
		return 2;
	if (complain == "warning" || complain == "WARNING")
		return 3;
	if (complain == "error" || complain == "ERROR")
		return 4;
	return (0);
}

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "levels: \n";
		std::cout << "debug\tinfo\twarning\terror";
		return (1);
	}
	std::string	str(argv[1]);
	harl.filter(str);
}
